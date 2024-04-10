    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
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
const int maxn = 1000010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2000000000000000000ll;
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

int tc;
string s, t;

bool can(int id){
    if( id < 0 || id > s.size() - 7 ) return false;
    for(int i=0; i<7; i++)
        if( s[id+i] != t[i] && s[id+i] != '?' )
            return false;
    return true;
}

bool can2(int id){
    for(int i=0; i<7; i++)
        if( s[id+i] != t[i] )
            return false;
    return true;
}

bool can3(int id, int al){
    if( id < 0 || id > s.size() - 7 ) return false;
    int res = 0;
    for(int i=0; i<7; i++)
        if( s[id+i] == t[i] || ( s[id+i] == '?' && ( id + i >= al && id + i <= al + 6 ) ) )
            res++;
    return ( res == 7 );
}

void to_aba(int id){
    for(int i=0; i<7; i++)
        if( s[id+i] == '?' )
            s[id+i] = t[i];
}

void to_z(int id){
    for(int i=0; i<s.size(); i++)
        if( s[i] == '?' )
            s[i] = 'z';
}

int getcnt(){
    int res = 0;
    for(int i=0; i<=s.size()-7; i++){
        if( can2(i) ){
            res++;
        }
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    t = "abacaba";

    cin >> tc;
    while( tc-- ){
        int n; cin >> n;
        cin >> s;
        bool b = 1;
        int cnt = getcnt();

        if( cnt > 1 ){
            cout << "No\n";
            continue;
        }
        if( cnt == 1 ){
            to_z(0);
            cout << "Yes\n";
            cout << s << '\n';
            continue;
        }
        for(int i=0; i<=s.size()-7; i++){
            if( ( can(i) && ( (!can3(i+6,i)) && (!can3(i-6,i)) ) ) && ( (!(can3(i+4,i))) && (!(can3(i-4,i))) ) ){
                to_aba(i);
                to_z(i);
                if( getcnt() == 1 ){
                    cout << "Yes\n";
                    cout << s << '\n';
                    b = 0;
                    break;
                }
                else{
                    b = 1;
                    break;
                }
            }
        }
        if( b ){
            cout << "No\n";
            continue;
        }
    }

    return 0;
}