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

///0-min
///1-max
template<typename T>
struct RMQ{
    vector<vector<T>> rmq;
    vector<int> lg;
    int n;
    bool t;
    RMQ(vector<T> &v,bool t) : n(v.size()),t(t)
    {
        lg.push_back(-1);
        for(int i=1;i<=n+5;i++)
            lg.push_back(lg.back()+!(i&(i-1)));

        for(int i=0;i<=n;i++)
            rmq.push_back(vector<T>(lg[n]+1));
        for(int i=0;i<n;i++)
            rmq[i][0]=v[i];
        for(int j=1;j<=lg[n];j++)
            for(int i=0;i+(1<<j)<=n;i++)
            {
                if(!t)
                    rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
                else
                    rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
            }
    }

    T query(int l,int r)
    {
        if(l>r)
            swap(l,r);
        int po=lg[r-l+1];
        if(!t)
            return min(rmq[l][po],rmq[r-(1<<po)+1][po]);
        return max(rmq[l][po],rmq[r-(1<<po)+1][po]);
    }
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
        c = max( a , b );
        return c;
    }

    void update_node(int nod,Tup v){
        /// how v affects to st[nod]
        st[nod] = max( st[nod] , v );
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
        vector<int> a(n+1);
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        int x;
        cin >> x;
        for(int i=1; i<=n; i++)
            a[i] -= x;

//        vector<vector<int>> dp(n+1,vector<int> (2,-mod));
//        dp[0][0] = 0;
//        int ans = 0;
//        for(int i=1; i<=n; i++){
//            dp[i][0] = max( dp[i-1][0] , dp[i-1][1] );
//            dp[i][1] = dp[i-1][0] + 1;
//            if( a[i] + a[i-1] >= 0 )
//                dp[i][1] = max( dp[i][1] , dp[i-1][1] + 1 );
//            ans = max( ans , max( dp[i][0] , dp[i][1] ) );
//        }
//        cout << ans << '\n';

        vector<pair<ll,int>> sums;
        sums.push_back({-INF,-INF});
        ll sum = 0;
        for(int i=0; i<=n; i++){
            sum += a[i];
            sums.push_back({sum,i});
        }
        sort(sums.begin(),sums.end());

        int cnt = 0;
        vector<int> b(n+1);
        for(int i=1; i<sums.size(); i++){
            if( sums[i].f != sums[i-1].f ){
                cnt ++;
            }
            b[sums[i].s] = cnt;
        }

        RMQ<int> rmq(b,1);

        auto is_valid = [&](int l,int r){
            if( l >= r ) return true;
            if( l == 0 ) return false;
            if( l + 1 == r )
                return ( a[l] + a[r] >= 0 );

            return ( rmq.query(l-1,r-2) <= b[r] );
        };

        vector<int> c(n+1);
        for(int i=1; i<=n; i++){
            int l = 1, r = i;
            while( l < r ){
                int mi = ( l + r ) >> 1;
                if( is_valid(mi,i) ) r = mi;
                    else l = mi + 1;
            }
            if( is_valid(l-1,i) ) l --;
            if( !is_valid(l,i) ) l ++;
            if( l > i )
                 l = i;
            c[i] = l;
        }

        RMQ<int> rmq2(c,1);

        auto is_good = [&](int l,int r){
            if( l >= r ) return true;
            if( l == 0 ) return false;
            return ( rmq2.query(l,r) <= l );
        };

        vector<int> init(n+1,-mod);
        init[1] = -1;
        ST<int,int> st(n+1);
        st.build(init);

        int ans = 0;
        vector<int> dp(n+1,-mod);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            int l = 1, r = i;
            while( l < r ){
                int mi = ( l + r ) >> 1;
                if( is_good(mi,i) ) r = mi;
                    else l = mi + 1;
            }
            if( is_good(l-1,i) ) l --;
            if( !is_good(l,i) ) l ++;
            if( l > i )
                 l = i;

            if( i - 2 >= 0 )
                st.update(i,dp[i-2]-i);
            dp[i] = st.query(l,i) + i + 1;
            dp[i] = max( dp[i] , dp[i-1] );
            ans = max( ans , dp[i] );
        }
        cout << ans << '\n';
//
//        vector<int> init(n+1+1,-mod);
//        init[b[0]] = 0;
//        ST<int,int> st(n+1+1);
//        st.build(init);
//
//        vector<int> dp(n+1,-mod);
//        dp[0] = 0;
//        int offset = 0, ans = 0;
//        for(int i=1; i<=n; i++){
//
//            offset ++;
//
//            dp[i] = st.query(b[i],n+1) + offset;
//            ans = max( ans , dp[i] );
//
//
////            st.update(b[i],dp[i-1]-offset);
////            if( i - 2 >= 0 )
////                st.update(b[i],dp[i-2]-offset);
//        }
//        cout << ans << '\n';
    }

    return 0;
}