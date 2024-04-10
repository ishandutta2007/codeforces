#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int n, arr[1000005];    
vector<int> conn[1000005];
bool vi[1000005];
void init(int k) {
    for(int i = 0; i <= k; i++) {
        arr[i] = 0;
        vi[i] = false;
        conn[i].clear();
    }
}
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
bool test(int l, int r) {
    if(r - l < 2) return true;
    if(r - l == 2) {
        if(arr[r] == arr[r - 1] || arr[r - 1] == arr[r - 2]) return false;
        return (arr[r] <= arr[r - 1] != arr[r - 1] <= arr[r - 2]);
    }
    else {
        int a = arr[l], b = arr[l + 1], c = arr[l + 2], d = arr[r];
        if(b > a && d > c && c < a && d < b) return true;
        if(b < a && d < c && c > a && d > b) return true;
        return false;
    } 
}
void solve() {  
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = max(0LL, i - 3); j <= i; j++) {
            if(test(j, i)) ans++;
        }
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}