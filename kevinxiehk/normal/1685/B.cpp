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
int cmp(pair<int, int> a, pair<int, int> b) {
    // if(a.fi * b.se == a.se * b.fi) {
    //     return 
    // }
    return a.fi * b.se > a.se * b.fi;
}
void solve(int TC) {
    int a, b, c, d;
    string s;
    cin >> a >> b >> c >> d >> s;
    int n = s.length();
    int cnt = 0;
    for(auto x: s) cnt += (x == 'A');
    if(cnt != a + c + d) {
        cout << "NO\n";
        return;
    }
        // cout << " " << c << ' ' << d << '\n';
    vector<pair<int, int>> sto; // AB, BA
    int cnta = 0, cntb = 0;
    for(int i = 1; i <= n; i++) {
        if(i == n || s[i] == s[i - 1]) {
            if(cnta + cntb > 0) {
                sto.pb(mp(cnta, cntb));
                cnta = cntb = 0;
            }
        }
        else if(s[i] == 'A') cntb++;
        else cnta++;
    }
    sort(sto.begin(), sto.end(), cmp);
    for(auto x: sto) {
        // cout << x.fi << ' ' << x.se << '\n';
        if(c > 0) {
            if(x.fi <= c) c -= x.fi;
            else {
                int lef = min(x.fi, x.se) - c;
                c = 0;
                d -= lef;
            }
        }
        else{
            d -= x.se;
        }
        // cout << " " << c << ' ' << d << '\n';
    }
    if(c <= 0 && d <= 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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