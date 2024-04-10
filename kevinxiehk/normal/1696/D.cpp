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
pair<int, int> spsmx[250005][25];
pair<int, int> spsmi[250005][25];
int p2[250005];
int n;
pair<int, int> rmxq(int l, int r) {
    if(r > n) return mp(-1, -1);
    int d = r - l + 1;
    d = p2[d];
    return max(spsmx[l][d], spsmx[r - (1 << d) + 1][d]);
}
pair<int, int> rmiq(int l, int r) {
    if(r > n) return mp(-1, -1);
    int d = r - l + 1;
    d = p2[d];
    return min(spsmi[l][d], spsmi[r - (1 << d) + 1][d]);
}
void solve(int TC) {
    cin >> n;
    int arr[n + 5];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        spsmx[i][0] = spsmi[i][0] = mp(arr[i], i);
    }
    for(int j = 1; j <= 20; j++) {
        for(int i = 1; i <= n; i++) {
            spsmx[i][j] = max(spsmx[i][j - 1], spsmx[min(n, i + (1 << (j - 1)))][j - 1]);
            spsmi[i][j] = min(spsmi[i][j - 1], spsmi[min(n, i + (1 << (j - 1)))][j - 1]);
        }
    }
    int now = 1, ans = 0;
    while(now < n) {
        if(arr[now + 1] < arr[now]) {
            int pp = now;
            for(int i = (1 << 17); i > 0; i /= 2) {
                if(rmxq(now, pp + i).se == now) pp += i;
            }
            now = rmiq(now, pp).se;
        }
        else {
            int pp = now;
            for(int i = (1 << 17); i > 0; i /= 2) {
                if(rmiq(now, pp + i).se == now) pp += i;
            }
            now = rmxq(now, pp).se;
        }
        ans++;
    }
    cout << ans << '\n';
}
signed main(){
    p2[1] = 0;
    for(int i = 2; i <= 250000; i++) p2[i] = p2[i / 2] + 1;
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}