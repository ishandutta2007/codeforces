#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r, x)     for (int i = l; i < r; i+=x)
//#define ForE(i, l, r, x)    for (int i = l; i <= r; i+=x)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O 
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << rl;
//#define PrintVl(a)          Fora(ii, a) cout << ii << rl;
//#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << rl;
//#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << rl;
//#define Ptest(x)            return cout << x, 0;
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calc    
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9+7;
const int MAX_N = 100005, MAX_M = 200010;
// code
//#define int long long

bool sorted(vector<int>& a) {
    for(int i = 1; i < a.size(); i++) 
        if(a[i] < a[i-1]) 
            return 0;
    return 1;
}
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);  
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    multiset<int> s(all(a));
    vector<int> c;
    const auto mex=[&]()->int {
        if(s.find(0)==s.end()) return 0;
        for(auto it: s) 
            if(!s.count(it+1)) 
                return it+1;
    };
    const auto repl=[&](int id)->void {
        c.pb(id+1);
        int v = mex();
        s.erase(s.find(a[id]));
        a[id] = v;
        s.insert(a[id]);
    };
    for(int i = 0; i < 2*n; i++) {
        if(sorted(a)) 
            break;
        if(mex()!=n) 
            repl(mex());
        else {
            for(int i=n-1; i>=0; i--){
                if(a[i]!=i) {
                    repl(i); break;
                }
            }
        }
    }
    
    cout<<c.size()<<endl;
    for(int it: c) cout<<it<<' '; cout<<endl;
}



signed main(){
    FAST_IO;
    int TC = 1;
    cin >> TC;
    while(TC--) Solve();
    return 0;
}