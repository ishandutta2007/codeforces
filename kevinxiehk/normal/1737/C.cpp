#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
int calc(int a, int b) {
    return (a % 2) * 2 + b % 2;
}
bool onedge(int n, int a, int b) {
    return a == 1 || b == 1 || a == n || b == n;
}
void solve(int TC) {
    int n;
    cin >> n;
    set<int> ss;
    int a, b;
    int cnt = 0;
    bool die = false;
    set<pair<int, int>> aa;
    for(int i = 0; i < 4; i++) {
        cin >> a >> b;
        if(i < 3) {
            cnt += onedge(n, a, b);
            aa.insert(mp(a, b));
        }
        else {
            if(cnt == 3) {
                // sort(aa.begin(), aa.end());
                if(aa.find(mp(1, 1)) != aa.end() && aa.find(mp(1, 2)) != aa.end() && aa.find(mp(2, 1)) != aa.end()) {
                    if(min(a, b) > 1) die = true;
                }
                if(aa.find(mp(1, n - 1)) != aa.end() && aa.find(mp(1, n)) != aa.end() && aa.find(mp(2, n)) != aa.end()) {
                    if(a != 1 && b != n) die = true;
                }
                if(aa.find(mp(n - 1, 1)) != aa.end() && aa.find(mp(n, 1)) != aa.end() && aa.find(mp(n, 2)) != aa.end()) {
                    if(a != n && b != 1) die = true;
                }
                if(aa.find(mp(n - 1, n)) != aa.end() && aa.find(mp(n, n - 1)) != aa.end() && aa.find(mp(n, n)) != aa.end()) {
                    if(a != n && b != n) die = true;
                }
            }
        }
        ss.insert(calc(a, b));
    }
    if(ss.size() == 4 || die) cout << "NO\n";
    else cout << "YES\n";
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}