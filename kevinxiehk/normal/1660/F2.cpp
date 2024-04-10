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
int fen[400005][3];
int nn;
void add(int id, int k) {
    while(id <= nn) {
        fen[id][k]++;
        id += (id & -id);
    }
}
int sum(int id, int k) {
    int ans = 0;
    while(id > 0) {
        ans += fen[id][k];
        id -= (id & -id);
    }
    return ans;
}
void solve(int TC) {
    int n;
    string s;
    cin >> n >> s;
    nn = n * 2 + 10;
    for(int i = 0; i <= nn; i++) for(int j = 0; j < 3; j++) fen[i][j] = 0;
    // int cnt[5];
    // cnt[0] = cnt[1] = cnt[2] = 0;
    int ans = 0;
    // cnt[0]++;
    int t = n + 5;
    add(t, t % 3);
    for(int i = 0; i < n; i++) {
        if(s[i] == '+') t--;
        else t++;
        ans += sum(t, t % 3);
        add(t, t % 3);
        // cout << t << ' ' << ans << '\n';
    }
    cout << ans << '\n';
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