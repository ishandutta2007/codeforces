#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 200010;
const int mod = 1000000007;
const ll INF = 1ll * mod * mod;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
//mt19937_64 rnd(time(0));
mt19937 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

template<typename T>
struct Treap
{
    struct node
    {
        T key;
        int value;
        int maxV;
        int sz;
        ll prior;
        node *l,*r;
        node(T key,int _value) : l(0),r(0),key(key),sz(1),prior(rng(1, INF)),value(_value),maxV(_value) {}
    };
    typedef node* pnode;
    pnode root;
    Treap() : root(0){}

    int sz(pnode p)
    {
        return p ? p->sz : 0;
    }

    int value(pnode p)
    {
        return p ? p->value : -mod;
    }

    int maxV(pnode p)
    {
        return p ? p->maxV : -mod;
    }

    void update(pnode p)
    {
        if(p)
        {
            p->sz=1+sz(p->l)+sz(p->r);
            p->maxV = max(p->value, max(maxV(p->l), maxV(p->r)));
        }
    }

    ///left subtree will contain elements less than or equal to key
    void split(pnode p,T key,pnode &l,pnode &r)
    {
        if(!p)
            l=r=0;
        else if(key<p->key)
        {
            split(p->l,key,l,p->l);
            r=p;
        }
        else
        {
            split(p->r,key,p->r,r);
            l=p;
        }
        update(p);
    }

    void insert(T key,int _value)
    {
        pnode add=new node(key, _value);
        insert(root,add);
    }

    int size() { return sz(root); }

    void insert(pnode &p,pnode it)
    {
        if(!p)
            p=it;
        else if(it->prior>p->prior)
        {
            split(p,it->key,it->l,it->r);
            p=it;
        }
        else
        {
            if(it->key<p->key)
                insert(p->l,it);
            else
                insert(p->r,it);
        }
        update(p);
    }

    void merge(pnode &p,pnode l,pnode r)
    {
        if(!l || !r)
        {
            if(l)
                p=l;
            else
                p=r;
        }
        else if(l->prior>r->prior)
        {
            merge(l->r,l->r,r);
            p=l;
        }
        else
        {
            merge(r->l,l,r->l);
            p=r;
        }
        update(p);
    }

    int queryUpTo(T x)
    {
        pnode l, r;
        split(root, x, l, r);
        int ans = maxV(l);
        merge(root, l, r);
        return ans;
    }

    int queryFrom(T x)
    {
        pnode l, r;
        split(root, x - 1, l, r);
        int ans = maxV(r);
        merge(root, l, r);
        return ans;
    }
};

Treap<ll> abiL[maxn], abiR[maxn];

void updateL(int id,ll key, int val)
{
    for (; id < maxn; id += (id&-id))
        abiL[id].insert(key, val);
}

void updateR(int id,ll key, int val)
{
    for (; id > 0; id -= (id&-id))
        abiR[id].insert(key, val);
}

int queryL(int id, ll key)
{
    int ans = -mod;
    for (; id > 0; id -= (id&-id))
        ans = max(ans, abiL[id].queryFrom(key));
    return ans;
}

int queryR(int id, ll key)
{
    int ans = -mod;
    for (; id < maxn; id += (id&-id)){
        ans = max(ans, abiR[id].queryUpTo(key));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n;
    ll v;
    cin >> n >> v;

    vector<ll> t(n+1), a(n+1);
    vector<pair<int, int>> compress(1, {-mod, -mod});
    for (int i=1; i<=n; i++)
    {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        compress.push_back({a[i], i});
    }
    compress.push_back({0, 0});

    sort(compress.begin(), compress.end());

    vector<int> id(n+1);
    int cnt = 0;
    for (int i=1; i<compress.size(); i++)
    {
        if (compress[i].f != compress[i-1].f)
            cnt ++;
        id[compress[i].s] = cnt;
    }

    vector<int> dp(n+1, -mod);
    updateL(id[0], 0, 0);
    updateR(id[0], 0, 0);

    int ans = 0;
    for (int i=1; i<=n; i++)
    {
        int abiId = id[i];

        dp[i] = max(dp[i], queryL(abiId, a[i] - v * t[i]) + 1);

        dp[i] = max(dp[i], queryR(abiId, a[i] + v * t[i]) + 1);

        updateL(abiId, a[i] - v * t[i], dp[i]);

        updateR(abiId, a[i] + v * t[i], dp[i]);

        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}