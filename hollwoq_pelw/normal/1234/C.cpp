#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// input, output
#define IOS         std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n)      fixed << setprecision(n)
// pair
#define F           first
#define S           second
#define pii         pair<int, int>
#define pll         pair<ll, ll>
#define pdd         pair<ld, ld>
// vector & !!?(string)
#define eb          emplace_back
#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()
#define len(a)      a.length()
// geometry calc
#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e9+7;
const int N = 100005, M = 200010;

void solve(){
    int n;
    string s[2];
    cin >> n >> s[0] >> s[1];
    int r = 0, c = 0;
    bool d = 0; // 0 = go by row && 1 = go by col
    while (true){
        //cout << r << ' ' << c << endl;
        if (s[r][c] == '1' || s[r][c] == '2'){
            if (d){
                cout << "NO\n"; 
                return ;
            }else{
                c ++;
            }
        }else{
            if (!d){
                r = 1-r;
            }else{
                c ++;
            }
            d = 1-d;
        }
        if (r && c == n){
            if (d) cout << "NO\n";
            else cout << "YES\n";
            break;
        }
    }
}

int main(){
    IOS;
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}