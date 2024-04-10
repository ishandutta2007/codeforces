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
void solve(int TC) {
    int n, m;
    cin >> n >> m;
    int arr[n + 5];
    arr[0] = 0;
    vector<pair<int, int>> t;
    int mm = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        t.pb(mp(arr[i] - arr[i - 1] - 1, i));
        mm = max(mm, (arr[i] - arr[i - 1]) / 2 - 1);
    }
    mm = max(mm, m - arr[n] - 1);
    sort(t.begin(), t.end());
    t.pb(mp(inf, -1));

    int a = t[0].se;
    int mx;
    if(a == n) {
        mx = max(mm, m - arr[n - 1] - 1);
    }
    else mx = max(mm, (arr[a + 1] - arr[a - 1]) / 2 - 1);
    int k = t[1].fi;
    if(t[1].se == a + 1) {
        k = min(arr[t[1].se] - arr[t[1].se - 2] - 1, t[2].fi);
    }
    int ans1 = min(mx, k);

    a = t[1].se;
    if(a == n) {
        mx = max(mm, m - arr[n - 1] - 1);
    }
    else mx = max(mm, (arr[a + 1] - arr[a - 1]) / 2 - 1);
    k = t[0].fi;
    if(t[0].se == a + 1) {
        k = min(arr[t[0].se] - arr[t[0].se - 2] - 1, t[2].fi);
    }
    int ans2 = min(mx, k);

    int ans3 = 0;
    if(t[0].se != 1) {
        a = t[0].se - 1;
        mx = max(mm, (arr[a + 1] - arr[a - 1]) / 2 - 1);
        k = t[0].fi;
        if(t[0].se == a + 1) {
            k = min(arr[t[0].se] - arr[t[0].se - 2] - 1, t[1].fi);
        }
        ans3 = min(mx, k);
    }

    cout << max(ans1, max(ans3, ans2)) << '\n';
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