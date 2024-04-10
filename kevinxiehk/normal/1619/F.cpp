#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
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
void solve(int TC) {
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> ss;
    for(int i = 1; i <= n; i++) ss.push(mp(0, i));
    for(int i = 0; i < k; i++) {
        bool yes[n + 5];
        memset(yes, false, sizeof yes);
        int hm = n % m;
        for(int j = 0; j < hm; j++) {
            cout << n / m + 1 << ' ';
            for(int _ = 0; _ < n / m + 1; _++) {
                auto now = ss.top();
                ss.pop();
                cout << now.se << ' ';
                now.fi++;
                yes[now.se] = true;
                ss.push(now);
            }
            cout << '\n';
        }
        int pt = 1;
        for(int j = hm; j < m; j++) {
            cout << n / m << ' ';
            int cnt = n / m;
            while(cnt) {
                while(yes[pt]) pt++;
                cout << pt << ' ';
                pt++;
                cnt--;
            }
            cout << '\n';
        }
    }
    cout << '\n';
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