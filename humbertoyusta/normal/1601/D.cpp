#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
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

template <typename Tnode,typename Tlazy>
struct ST{
    vector<Tnode> st;
    vector<Tlazy> lazy;
    int sz;
    Tlazy neutraL;

    ST(int n,Tlazy _neutraL){
        sz = n;
        st.resize(4*n);
        lazy.resize(4*n);
        neutraL = _neutraL;
    }

    Tnode merge_(Tnode a, Tnode b){
        Tnode c;
        /// Merge nodes a and b into c
        c = max( a , b );
        return c;
    }

    void push(int nod,int l,int r){
        /// how lazy[nod] affects st[nod]
        st[nod] += lazy[nod];
        if( l != r ){
            /// how lazy[nod] affects lazy[2*nod] and lazy[2*nod+1]
            lazy[2*nod] += lazy[nod];
            lazy[2*nod+1] += lazy[nod];
        }
        lazy[nod] = neutraL;
    }

    void build(Tnode *arr){ build(1,0,sz-1,arr); }

    void build(int nod,int l,int r,Tnode *arr){
        if( l == r ){
            st[nod] = arr[l];
            lazy[nod] = neutraL;
            return;
        }
        int mi = ( l + r ) >> 1;
            build((nod<<1),l,mi,arr);
            build((nod<<1)+1,mi+1,r,arr);
        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
        lazy[nod] = neutraL;
    }

    void build(vector<Tnode> &arr){ build(1,0,sz-1,arr); }

    void build(int nod,int l,int r,vector<Tnode> &arr){
        if( l == r ){
            st[nod] = arr[l];
            lazy[nod] = neutraL;
            return;
        }
        int mi = ( l + r ) >> 1;
            build((nod<<1),l,mi,arr);
            build((nod<<1)+1,mi+1,r,arr);
        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
        lazy[nod] = neutraL;
    }

    void update(int x,int y,Tlazy v){ update(1,0,sz-1,x,y,v); }

    void update(int nod,int l,int r,int x,int y,Tlazy v){

        push(nod,l,r);

        if( l >= x && r <= y ){
            lazy[nod] = v;
            push(nod,l,r);
            return;
        }

        int mi = ( l + r ) >> 1;

        if( x <= mi ) update((nod<<1),l,mi,x,y,v);
            else push(nod<<1,l,mi);
        if( y > mi ) update((nod<<1)+1,mi+1,r,x,y,v);
            else push((nod<<1)+1,mi+1,r);

        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
    }

    Tnode query(int l,int r){ return query(1,0,sz-1,l,r); }

    Tnode query(int nod,int l,int r,int x,int y){

        push(nod,l,r);

        if( l >= x && r <= y ) return st[nod];

        int mi = ( l + r ) >> 1;

        if( y <= mi ) return query((nod<<1),l,mi,x,y);

        if( x > mi ) return query((nod<<1)+1,mi+1,r,x,y);

        return merge_( query((nod<<1),l,mi,x,y), query((nod<<1)+1,mi+1,r,x,y) );
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //cin >> tc;
     tc = 1;
    while( tc-- ){
        int n, d;
        cin >> n >> d;

        vector<pair<int,int>> a(n);
        vector<pair<int,int>> cmp;
        cmp.push_back({-1,-1});
        for(int i=0; i<n; i++){
            cin >> a[i].f >> a[i].s;
            cmp.push_back({a[i].f,i});
            cmp.push_back({a[i].s,n+i});
        }
        cmp.push_back({d,-1});
        sort(cmp.begin(),cmp.end());
        int curr = 0;
        for(int i=1; i<cmp.size(); i++){
            curr += ( cmp[i].f > cmp[i-1].f );
            if( cmp[i].s == -1 ){
                d = curr;
                continue;
            }
            if( cmp[i].s < n ) a[cmp[i].s].f = curr;
                else a[cmp[i].s-n].s = curr;
        }

        function<bool(pair<int,int>,pair<int,int>)> comparison = [](pair<int,int> a,pair<int,int> b){
            return (pair<int,int>){ a.f + a.s , a.s } < (pair<int,int>){ b.f + b.s , b.s };
        };
        sort(a.begin(),a.end(),comparison);

        vector<int> init(2*n+3,-mod);
        init[d] = 0;
        ST<int,int> dp(2*n+2,0);
        dp.build(init);
        for( auto i : a ){
            if( i.s >= i.f ){
                int ndp = dp.query(0,i.f) + 1;
                dp.update(i.s,i.s,-dp.query(i.s,i.s)+ndp);
            }
            else{
                int ndp = dp.query(0,i.s) + 1;
                dp.update(i.s,i.s,-dp.query(i.s,i.s)+ndp);
                dp.update(i.s+1,i.f,1);
            }
        }
        cout << dp.query(0,2*n+2) << '\n';
    }

    return 0;
}