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
        c = min( a , b );
        return c;
    }

    void update_node(int nod,Tup v){
        /// how v affects to st[nod]
        st[nod].f = v;
    }

    void build(Tnode *arr){ build(1,0,sz-1,arr); }

    void build(int nod,int l,int r,Tnode *arr){
        if( l == r ){
            st[nod] = arr[l];
            return;
        }
        int mi = ( l + r ) >> 1;
            build((nod<<1),l,mi,arr);
            build((nod<<1)+1,mi+1,r,arr);
        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
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
    //cin >> tc;
     tc = 1;
    while( tc-- ){
        int n;
        cin >> n;

        vector<pair<int,int>> a(n+1);
        for(int i=1; i<=n; i++){
            cin >> a[i].f;
            a[i].f *= -1;
            a[i].f += i;
            a[i].s = i;
        }

        ST<pair<int,int>,int> st(n+1);
        st.build(a);

        vector<int> b(n+1);
        vector<int> endup[n+1];
        for(int i=1; i<=n; i++){
            cin >> b[i];
            endup[i+b[i]].push_back(i);
        }

        vector<int> p(n+1), dist(n+1,mod);

        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while( !q.empty() ){
            int u = q.front();
            q.pop();
            if( u == n ) break;
            while( true ){
                pair<int,int> v = st.query(u+1,n);
                if( v.f > u ) break;
                for( auto i : endup[v.s] ){
                    dist[i] = dist[u] + 1;
                    p[i] = u;
                    q.push(i);
                }
                st.update(v.s,mod);
            }
        }

        if( dist[n] == mod ){
            cout << -1 << '\n';
        }
        else{
            cout << dist[n] << '\n';
            vector<int> ans;
            function<void(int)> backtrack = [&](int x){
                if( x == 0 ) return;
                ans.push_back(p[x]);
                backtrack(p[x]);
            };
            backtrack(n);
            for( auto i : ans ) cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}