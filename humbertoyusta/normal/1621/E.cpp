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
const int maxn = 100010;
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    ST<int,int> st(maxn,0);
    vector<int> init(maxn,0);
    st.build(init);

    int tc;
    //tc = 1;
    cin >> tc;
    while( tc-- ){
        int n, m;
        cin >> n >> m;//db(n)db(m)


        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];//db(a[i])
            st.update(0,a[i],1);
        }

        vector<vector<int>> b(m);
        vector<int> mean(m);
        vector<ll> sum(m);
        for(int i=0; i<m; i++){
            int k;
            cin >> k;//db(k)
            for(int j=0; j<k; j++){
                int u;
                cin >> u;
                b[i].push_back(u);//db(u)
                sum[i] += u;
            }
            mean[i] = ( sum[i] + k - 1 ) / k;
            st.update(0,mean[i],-1);
        }

        vector<int> ans;
        for(int i=0; i<m; i++){
            int k = b[i].size();
            st.update(0,mean[i],1);
            for(int j=0; j<k; j++){
                st.update(0,(sum[i]-b[i][j]+k-2)/(k-1),-1);

                if( st.query(0,maxn-1) >= 0 )
                    ans.push_back(1);
                else
                    ans.push_back(0);

                st.update(0,(sum[i]-b[i][j]+k-2)/(k-1),1);
            }
            st.update(0,mean[i],-1);
        }

        for( auto i : ans )
            cout << i;
        cout << '\n';

        //clean the ST
        for(int i=0; i<n; i++){
            st.update(0,a[i],-1);
        }
        for(int i=0; i<m; i++){
            st.update(0,mean[i],1);
        }
    }

    return 0;
}