    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 100010;
const int mod = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Pow------------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, ch[maxn][26], color[maxn], cnt;
vector<int> g[maxn];
multiset<int> s[maxn];
string u;
map<ii,bool> mp;

void insert_(int nod,int pos){
    if( pos == u.size() - 1 ){
        color[nod] = 1;
        return;
    }
    else{
        int nxt = (int)(u[pos+1] - 'a');
        if( ch[nod][nxt] == 0 ){
            ch[nod][nxt] = ++cnt;
            g[nod].pb(cnt);
            mp[{nod,cnt}] = 1;
            insert_(cnt,pos+1);
        }
        else{
            if( !mp[{nod,ch[nod][nxt]}] ){
                g[nod].pb(ch[nod][nxt]);
                mp[{nod,ch[nod][nxt]}] = 1;
            }
            insert_(ch[nod][nxt],pos+1);
        }
    }
}

void dfs(int u,int lv){
    for( auto v : g[u] ){
        dfs(v,lv+1);
        if( s[u].size() < s[v].size() )
            swap( s[u] , s[v] );
        for( auto i : s[v] )
            s[u].insert(i);
        s[v].clear();
    }
    if( color[u] ){
        s[u].insert(lv);
    }
    else{
        if( u != 0 ){
            auto it = s[u].end();
            it--;
            s[u].erase(it);
            s[u].insert(lv);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> u;
        u = '$' + u;
        insert_(0,0);
    }

    dfs(0,0);

    int ans = 0;
    for( auto i : s[0] )
        ans += i;
    cout << ans << '\n';

    return 0;
}