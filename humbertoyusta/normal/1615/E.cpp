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
        st[nod].f += lazy[nod];
        if( l != r ){
            /// how lazy[nod] affects lazy[2*nod] and lazy[2*nod+1]
            lazy[2*nod] += lazy[nod];
            lazy[2*nod+1] += lazy[nod];
        }
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

ll get(int white,int red,int blue){
    return 1ll * white * ( red - blue );
}

ll mn(int white,int red,int blue){
    int l = 0, r = blue;
    ll ans = INF;
    while( r - l > 7 ){
        int p1 = l + ( r - l + 1 ) / 3;
        int p2 = r - ( r - l + 1 ) / 3;
        if( get(white+p1,red,blue-p1) > get(white+p2,red,blue-p2) )
            l = p1;
        else
            r = p2;
    }
    for(int i=l; i<=r; i++)
        ans = min( ans , get(white+i,red,blue-i) );
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    tc = 1;
    //cin >> tc;
    while( tc-- ){
        int n, k;
        cin >> n >> k;

        vector<int> g[n];
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> p(n), tl(n), tr(n), tp;
        int cnt = 0;
        function<void(int)> dfs = [&](int u){
            tl[u] = tr[u] = cnt++;
            tp.push_back(u);
            for( auto v : g[u] ){
                if( v != p[u] ){
                    p[v] = u;
                    dfs(v);
                    tr[u] = max( tr[u] , tr[v] );
                }
            }
        };
        dfs(0);

        ST<pair<int,int>,int> st(n,0);

        vector<pair<int,int>> init(n);
        for(int i=0; i<n; i++)
            init[i].s = tp[i];

        st.build(init);

        for(int i=0; i<n; i++)
            st.update(tl[i],tr[i],1);

        int red(0), white(0), blue(n);
        ll ans = -INF;
        vector<int> mk(n);
        for(int i=0; i<k; i++){
            int x = st.query(0,n-1).s;//db(x)
            if( mk[x] ){
                for(int i=0; i<=white; i++){
                    if( red + i <= k )
                        ans = max( ans , mn(white-i,red+i,blue) );
                }
                break;
            }

            red ++;
            blue --;
            mk[x] = 1;
            st.update(tl[x],tr[x],-1);
            x = p[x];

            while( mk[x] == 0 ){
                white ++;
                blue --;
                mk[x] = 1;
                st.update(tl[x],tr[x],-1);
                if( x == 0 )
                    break;
                x = p[x];
            }

            ans = max( ans , mn(white,red,blue) );
        }

        cout << ans << '\n';
    }

    return 0;
}