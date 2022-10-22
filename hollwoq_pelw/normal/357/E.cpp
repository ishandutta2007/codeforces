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
const int MAXN = 100005, MAX_M = 200010;
// code

int cnt[5];
int n, s;
void Solve() {
    cin >> n;
    for (int i = 0, a; i < n; i++){
        cin >> a;
        cnt[a] ++;
        s += a;
    }
    if (s == 0) {
        cout << 0;
        return;
    }else if (s < 3 || s == 5){
        cout << -1;
        return;
    }
    int ans = min(cnt[1], cnt[2]);
    cnt[3] += ans;
    cnt[1] -= ans;
    cnt[2] -= ans;
    if (cnt[1]){
        ans += (cnt[1] / 3) * 2;
        cnt[3] += cnt[1] / 3;
        cnt[1] %= 3;
        if (cnt[1] == 1){
            if (cnt[3] > 0){
                ans ++;
                cnt[3] --;
                cnt[4] ++;
            }else if (cnt[4] > 1) {
                cnt[4] -= 2;
                cnt[3] ++;
                ans += 2;
            }else{
                cout << -1;
                return;
            }
        }else if (cnt[1] == 2){
            if (cnt[3] > 1){
                cnt[3] -= 2;
                ans += 2;
            }else if (cnt[4] > 0){
                cnt[4] --;
                ans += 2;
            }else{
                cout << -1;
                return;
            }
        }
    }else if (cnt[2]){
        if (cnt[4] == 0 && cnt[3] <= 1){
            if (cnt[2] % 3 == 1){
                if (cnt[2] >= 4){
                    ans += 4;
                    cnt[2] -= 4;
                }else{
                    cout << -1;
                    return;
                }
            }
        }
        ans += (cnt[2] / 3) * 2;
        cnt[3] += cnt[2] / 3;
        cnt[2] %= 3;
        if (cnt[2] == 1){
            if (cnt[4] > 0){
                ans ++;
                cnt[4] --;
                cnt[3] ++;
            }else if (cnt[3] > 1){
                ans += 2;
                cnt[3] -= 2;
                cnt[4] += 2;
            }else{
                cout << -1;
                return;
            }
        }else if (cnt[2] == 2){
            ans += 2;
        }
    }
    cout << ans;
}

signed main(){
    FAST_IO;
    int TC = 1; 
	//cin >> TC;
    while(TC--) Solve();
    return 0;
}