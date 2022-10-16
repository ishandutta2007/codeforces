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
    int arr[m + 5];
    for(int i = 0; i < m; i++) cin >> arr[i];
    sort(arr, arr + m);
    arr[m] = arr[0] + n;
    priority_queue<int> gaps;
    for(int i = 0; i < m; i++) {
        gaps.push(arr[i + 1] - arr[i] - 1);
    } 
    // int aaa = m * 2;
    // int nextminus = 0;
    // while(!gaps.empty() && gaps.top() == 0) {
    //     aaa -= 2;
    //     gaps.pop();
    // }
    // while(!gaps.empty() && gaps.top() == 1) {
    //     aaa--;
    //     gaps.pop();
    //     nextminus++;
    // }
    int ans = m;
    int days = 0;
    while(!gaps.empty()) {
        int k = gaps.top();
        gaps.pop();
        if(k == days * 2 + 1) ans += k - 1;
        else ans += min(k, days * 2 + 1);
        days += 2;
    }
    // while(aaa > 0) {
    //     aaa--;
    //     ans += aaa;
    //     cout << "day: " << days << ' ' << aaa << ' ' << gaps.size() << '\n';
    //     days++;
    //     aaa -= nextminus;
    //     nextminus = 0;
    //     while(!gaps.empty() && gaps.top() == days * 2) {
    //         aaa -= 2;
    //         gaps.pop();
    //     }
    //     while(!gaps.empty() && gaps.top() == days * 2 + 1) {
    //         aaa--;
    //         gaps.pop();
    //         nextminus++;
    //     }
    // }
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