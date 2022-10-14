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
        c = min( a , b );
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

int abi[maxn];

void update_abi(int id){
    for( ; id > 0; id -= ( id & -id ) )
        abi[id] ++;
}

int query_abi(int id,int n){
    int res = 0;
    for( ; id <= n ; id += ( id & -id) )
        res += abi[id];
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    // tc = 1;
    while( tc-- ){

        int n, m;
        cin >> n >> m;

        vector<pair<int,int>> events;
        vector<pair<int,int>> kp;

        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            events.push_back({a[i],-i-1});
            events.push_back({a[i],i+1});
            kp.push_back({a[i],i+1});
        }

        vector<int> b(m);
        for(int i=0; i<m; i++){
            cin >> b[i];
            events.push_back({b[i],0});
        }

        ST<int,int> st(n+1,0);
        vector<int> init_(n+1);
        st.build(init_);

        for(int i=0; i<n; i++)
            st.update(i+1,n,1);

        sort(events.begin(),events.end());
        sort(kp.begin(),kp.end());

        ll ans = 0;
        vector<int> v;
        for( auto i : events ){
            if( i.s < 0 ){
                i.s = -i.s-1;
                st.update(i.s+1,n,-1);
                continue;
            }
            if( i.s == 0 ){
                ans += st.query(0,n);
                continue;
            }
            st.update(0,i.s-1,1);
        }

        for( auto i : kp )
            v.push_back(i.s);

        for(int i=0; i<=n; i++)
            abi[i] = 0;
        for( auto i : v ){
            ans += query_abi(i+1,n);
            update_abi(i);
        }
        cout << ans << '\n';
    }

    return 0;
}