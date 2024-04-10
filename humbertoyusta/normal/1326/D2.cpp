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
const int maxn = 1000010;
const int MaxN = 10000010;
const int MOD = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<62ll)-1ll)*2ll)+1ll;
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
/// My Code -------------------------------------------------

string s;
int a, b, ans1, ans2(MOD);
int h[5][maxn], ih[5][maxn], pot[5][maxn];
int base[5], mod[5];

bool ispal(int l,int r){
    l++, r++;
    int c = 0;
    for(int i=0; i<5; i++){
        if( ( h[i][r] + mod[i] - h[i][l-1] * pot[i][r-l+1] % mod[i] ) % mod[i] == ( ih[i][l] + mod[i] - ih[i][r+1] * pot[i][r-l+1] % mod[i] ) % mod[i] )
            c++;
    }
    return ( c == 5 );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    base[0] = 173;
    base[1] = 181;
    base[2] = 331;
    base[3] = 311;
    base[4] = 737;

    mod[0] = 1000000007;
    mod[1] = 1000000021;
    mod[2] = 1000000009;
    mod[3] = 998244353;
    mod[4] = 2000000099;

    for(int i=0; i<5; i++)
        pot[i][0] = 1;
    for(int i=1; i<maxn; i++)
        for(int j=0; j<5; j++)
            pot[j][i] = pot[j][i-1] * base[j] % mod[j];

    int tc;
    cin >> tc;
    while( tc-- ){

    cin >> s;

    for(int i=0; i<s.size(); i++)
        for(int j=0; j<5; j++)
            h[j][i+1] = ( h[j][i] * base[j] + (int)(s[i]) ) % mod[j];

    for(int i=s.size()-1; i>=0; i--)
        for(int j=0; j<5; j++)
            ih[j][i+1] = ( ih[j][i+2] * base[j] + (int)(s[i]) ) % mod[j];


    ans1 = 0, ans2 = MOD;
    a = -1, b = s.size();
    while( s[a+1] == s[b-1] && a + 1 < b - 1 ) a++, b--;
    for(int i=a+1; i<b; i++)
        if( ispal(a+1,i) ) ans1 = max( ans1 , i );
    for(int i=b-1; i>a; i--)
        if( ispal(i,b-1) ) ans2 = min( ans2 , i );

    string t;
    for(int i=0; i<=a; i++)
        t += s[i];
    if( ans1 - a > b - ans2 ){ for(int i=a+1; i<=ans1; i++) t += s[i]; }
        else{ for(int i=ans2; i<b; i++) t += s[i]; }
    for(int i=b; i<s.size(); i++)
        t += s[i];

    cout << t << '\n';

    }

    return 0;
}