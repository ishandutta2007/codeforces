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
const int maxn = 1000010;
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
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

struct Node {
    pair<int,int> mn, mx;
    Node(){};
};

template <typename Tnode,typename Tup>
struct ST{
    vector<Tnode> st;
    int sz;

    ST(int n){
        sz = n;
        st.resize(4*n);
    }

    Tnode merge_(Tnode a, Tnode b){
        Tnode c;
        /// Merge a and b into c
        c.mn = min(a.mn, b.mn);
        c.mx = max(a.mx, b.mx);
        return c;
    }

    void update_node(int nod,Tup v){
        /// how v affects to st[nod]
        st[nod] = v;
    }

    void build(vector<Tnode> &arr){ build(1,0,sz-1,arr); }

    void build(int nod,int l,int r,vector<Tnode> &arr){
        if( l == r ){
            st[nod] = arr[l];
            return;
        }
        int mi = ( l + r ) >> 1;
            build((nod<<1),l,mi,arr);
            build((nod<<1)+1,mi+1,r,arr);
        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
    }

    void update(int id,Tup v){ update(1,0,sz-1,id,v); }

    void update(int nod,int l,int r,int id,Tup v){
        if( l == r ){
            update_node(nod,v);
            return;
        }
        int mi = ( l + r ) >> 1;
        if( id <= mi ) update((nod<<1),l,mi,id,v);
            else update((nod<<1)+1,mi+1,r,id,v);
        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
    }

    Tnode query(int l,int r){ return query(1,0,sz-1,l,r); }

    Tnode query(int nod,int l,int r,int x,int y){

        if( l >= x && r <= y ) return st[nod];

        int mi = ( l + r ) >> 1;

        if( y <= mi ) return query((nod<<1),l,mi,x,y);

        if( x > mi ) return query((nod<<1)+1,mi+1,r,x,y);

        return merge_( query((nod<<1),l,mi,x,y), query((nod<<1)+1,mi+1,r,x,y) );
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while (tc--)
    {

        int n, a, b;
        cin >> n >> a >> b;

        vector<int> p(n), l(n), r(n);
        for (int i=0; i<n; i++)
        {
            cin >> p[i];
            l[i] = max(0, i - p[i]);
            r[i] = min(n - 1, i + p[i]);
        }

        ST<Node, Node> st(n);
        vector<Node> init(n);
        for (int i=0; i<n; i++)
        {
            init[i].mn = {l[i], i};
            init[i].mx = {r[i], i};
        }
        st.build(init);

        Node badNode;
        badNode.mn = {mod, 0};
        badNode.mx = {-mod, 0};

        vector<int> dist(n);
        queue<int> q;
        q.push(a-1);
        st.update(a-1, badNode);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (l[u] < u)
            {
                while (true)
                {
                    pair<int, int> qu = st.query(l[u], u - 1).mx;
                    int v = qu.s;

                    if (qu.f < u)
                        break;

                    dist[v] = dist[u] + 1;
                    q.push(v);
                    st.update(v, badNode);
                }
            }

            if (u < r[u])
            {
                while (true)
                {
                    pair<int, int> qu = st.query(u + 1, r[u]).mn;
                    int v = qu.s;

                    if (qu.f > u)
                        break;

                    dist[v] = dist[u] + 1;
                    q.push(v);
                    st.update(v, badNode);
                }
            }
        }

        cout << dist[b-1] << '\n';

    }

    return 0;
}