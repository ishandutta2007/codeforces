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
        c = a + b;
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
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //tc = 1;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;
        vector<int> v[30];
        for(int i=n-1; i>=0; i--){
            v[s[i]-'a'].push_back(i);
        }

        vector<int> init(n,1);
        ST<int,int> st(n);
        st.build(init);

        ll ans = INF;
        ll curr = 0;
        for(int i=0; i<n; i++){

            int nid = n;
            for(int j=0; j<t[i]-'a'; j++){
                if( !v[j].empty() )
                    nid = min( nid , v[j].back() );
            }
            if( nid != n ){
                if( nid - 1 >= 0 )
                    ans = min( ans , curr + st.query(0,nid-1) );
                else
                    ans = min( ans , curr );
            }

            if( v[t[i] - 'a'].empty() )
                break;
            int id = v[t[i] - 'a'].back();
            v[t[i] - 'a'].pop_back();
            if( id - 1 >= 0 )
                curr += st.query(0,id-1);
            st.update(id,0);
        }
        if( ans == INF )
            ans = -1;
        cout << ans << '\n';
    }

    return 0;
}