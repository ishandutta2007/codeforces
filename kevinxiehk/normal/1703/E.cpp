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
pair<int, int> rotate(pair<int, int> now, int n) {
    int x = now.fi;
    int y = now.se;
    if(n % 2 == 0) {
        n++;
        int mid = n / 2;
        if(x >= mid) x++;
        if(y >= mid) y++;
        // int mid = n / 2;
        int dx = x - mid;
        int dy = y - mid;
        pair<int, int> ne = mp(mid + dy, mid - dx);
        if(ne.fi > mid) ne.fi--;
        if(ne.se > mid) ne.se--;
        return ne;
    }
    else {
        int mid = n / 2;
        int dx = x - mid;
        int dy = y - mid;
        return mp(mid + dy, mid - dx);
    }
}
void solve(int TC) {
    int n;
    cin >> n;
    int arr[n + 5][n + 5];
    char c;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        cin >> c;arr[i][j] = c - '0';
    }
    bool vi[n + 5][n + 5];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) vi[i][j] = false;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!vi[i][j]) {
                pair<int, int> now = mp(i, j);
                int t = 0;
                for(int k = 0; k < 4; k++) {
                    t += arr[now.fi][now.se];
                    vi[now.fi][now.se] = true;
                    now = rotate(now, n);
                }
                ans += min(t, 4 - t);
            }
        }
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