    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX
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
const int maxn = 5005;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// rng
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

const int K = 10;
struct node{
    int nxt[K];
    int go[K];
    int slink;
    int leaf;
    int pch;
    int p;
    node(){}
    node(int tp,int tpch){
        for(int i=0; i<K; i++)
            nxt[i] = go[i] = -1;
        slink = -1;
        leaf = 0;
        pch = tpch;
        p = tp;
    }
};
vector<node> AHC;
string s;
int x, n, dp[maxn/5+5][maxn], nxt[maxn][11];
vector<string> vs;

bool isp(string sx){
    for(int l=0; l<sx.size(); l++){
        int sum = 0;
        for(int r=l; r<sx.size(); r++){
            sum += sx[r] - '0';
            if( sum < x && sum >= 1 ){
                if( x % sum == 0 )
                    return false;
            }
        }
    }
    return true;
}

void generate_(string s,int sum){
    if( sum > x ) return;
    if( sum == x ){
        if( isp(s) ){
            vs.pb(s);
        }
        return;
    }
    for(char nxt = '1'; nxt <= '9'; nxt++)
        generate_(s+nxt,sum+(nxt-'0'));
}

void AHC_insert(string& s){
    int curr = 0;
    for(int i=0; i<s.size(); i++){
        int nch = ( s[i] - '0' );
        if( AHC[curr].nxt[nch] == -1 ){
            AHC.pb(node(curr,nch));
            AHC[curr].nxt[nch] = AHC.size() - 1;
        }
        curr = AHC[curr].nxt[nch];
    }
    AHC[curr].leaf ++;
}

int go(int nod,int ch);

int get_link(int nod){
    if( AHC[nod].slink == -1 ){
        if( nod == 0 || AHC[nod].p == 0 )
                AHC[nod].slink = 0;
            else
                AHC[nod].slink = go(get_link(AHC[nod].p),AHC[nod].pch);
    }
    return AHC[nod].slink;
}

int go(int nod,int ch){
    if( AHC[nod].go[ch] == -1 ){
        if( AHC[nod].nxt[ch] != -1 )
                AHC[nod].go[ch] = AHC[nod].nxt[ch];
            else{ if ( nod == 0 )
                        AHC[nod].go[ch] = 0;
                    else
                        AHC[nod].go[ch] = go(get_link(nod),ch); }
    }
    return AHC[nod].go[ch];
}

void AHC_build(int nod){

    get_link(nod);

    for(int i=0; i<K; i++)
        go(nod,i);

    for(int i=0; i<K; i++)
        if( AHC[nod].nxt[i] != -1 )
            AHC_build(AHC[nod].nxt[i]);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> s;

    cin >> x;

    n = s.size();

    generate_("",0);

    AHC.pb(node(0,0));

    for( auto i : vs )
        AHC_insert(i);

    AHC_build(0);

    for(int i=0; i<10; i++)
        nxt[n+1][i] = n + 1;
    for(int i=n; i>=0; i--){
        for(int j=0; j<10; j++){
            nxt[i][j] = nxt[i+1][j];
        }
        if( i ) nxt[i][s[i-1]-'0'] = i;
    }

    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=AHC.size(); j++)
            dp[i][j] = mod;
    dp[0][0] = 0;

    for(int i=0; i<=n; i++){
        for(int j=0; j<AHC.size(); j++){
            for(int k=1; k<10; k++){
                int l = nxt[i+1][k];
                if( AHC[go(j,k)].leaf == 0 )
                    dp[l][go(j,k)] = min( dp[l][go(j,k)] , dp[i][j] + ( l - i - 1 ) );
            }
        }
    }

    int ans = n;
    for(int i=0; i<AHC.size(); i++)
        if( AHC[i].leaf == 0 )
            ans = min( dp[n+1][i] , ans );
    cout << ans << '\n';

    return 0;
}