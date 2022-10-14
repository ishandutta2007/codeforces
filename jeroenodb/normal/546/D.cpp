/* TaDar1/CsChill/TanishqGupta*/
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define nline "\n"
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define rep(i,b,a) for(i = b ; i < a ; i++)
#define pb push_back
#define fr first
#define sc second
#define vl vector<long long> 
#define vc vector<char> 
#define vvl vector<vector<long long>> 
#define vvc vector<vector<char>> 
#define vpll vector<pair<long long,long long>>
#define pl pair<ll,ll>
#define it(v) v.begin(), v.end()
#define lb lower_bound 
#define ub upper_bound
#define Traverse(m) for(auto it = m.begin(); it!=m.end(); it++)
 

#ifndef TaDark1
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key


// --------------------------------------------------------------------------
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// --------------------------------------------------------------------------


// --------------------------------------------------------------------------
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
// --------------------------------------------------------------------------


// ******* ****      *       *******  ****      *    *******  ****       *  
//    *    *    *  * *         *     *    *   * *       *     *    *   * *
//    *    *    *    *        *     *    *      *       *     *    *     *    
//    *    ****    * * *     *      ****     * * * *    *     ****     * * * *    

ll num[5000005];
ll dp[5000005];
void precompute(){
    for(ll i = 2; i < 5000005; i++){
        if(num[i]!=0)
            continue;
        for(ll j = i ; j <5000001; j+=i){
            // ll temp = j;
            num[j] = 1 + num[j/i];
        }
    }
    for(ll i = 1; i < 5000005; i++){
        dp[i] = dp[i-1] + num[i];
    }
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("../input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("../output.txt", "w", stdout);
    #endif
    ll t,m,n,k,i,j;
    string s;
    ll dx[] = {0,0,1,-1};
    ll dy[] = {1,-1,0,0};
    memset(num, 0, sizeof(num));
    memset(dp, 0, sizeof(dp));
    precompute();
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<dp[a] - dp[b]<<"\n"; // O(1)
    }
    
    return 0; 
}


      // *****   *******   !        ******   *******   !    ******  *******   ! 
      // *            *    !       *             *    !     *            *    !
      // ***        *      !      ***         *      !      ***        *      !
      // *        *        !     *         *        !       *        *        !
      // *****   *******   !    ******   *******   !        *****   *******   !