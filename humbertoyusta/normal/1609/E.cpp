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
const ll INF = 1ll * mod * mod;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    ll pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

struct node{
    int dp[3][3];
    node(){
        for(int i=0; i<3; i++)
            for(int j=i; j<3; j++)
                dp[i][j] = mod;
    }
    node(char a){
        int x = a - 'a';
        for(int i=0; i<3; i++)
            for(int j=i; j<3; j++)
                dp[i][j] = ( x == j );
    }
};

template <typename Tup>
struct ST{
    vector<node> st;
    int sz;

    ST(int n){
        sz = n;
        st.resize(4*n);
    }

    node merge_(node a, node b){
        node nc('a');
        /// Merge a and b into c
        for(int i=0; i<3; i++)
            for(int j=i; j<3; j++)
                nc.dp[i][j] = mod;
        for(int i=0; i<3; i++)
            for(int j=i; j<3; j++)
                for(int k=j; k<3; k++){
                    nc.dp[i][k] = min( nc.dp[i][k] , a.dp[i][j] + b.dp[j][k] );
                }
        return nc;
    }

    void update_node(int nod,Tup v){
        /// how v affects to st[nod]
        st[nod] = node(v);
    }

    void build(vector<node> &arr){ build(1,0,sz-1,arr); }

    void build(int nod,int l,int r,vector<node> &arr){
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

    node query(int l,int r){ return query(1,0,sz-1,l,r); }

    node query(int nod,int l,int r,int x,int y){

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
    tc = 1;//cin >> tc;
    while( tc-- ){

        int n, q;

        cin >> n >> q;

        string s;
        cin >> s;

        vector<node> init;
        for( auto i : s )
            init.push_back(node(i));

        ST<char> st(n);
        st.build(init);

        for(int i=0; i<q; i++){
            int x; char c;
            cin >> x >> c;
            x --;
            st.update(x,c);

            node ans = st.query(0,n-1);
            int res = mod;
            for(int j=0; j<3; j++)
                for(int k=j; k<3; k++)
                    res = min( res , ans.dp[j][k] );
            cout << res << '\n';
        }
    }

    return 0;
}