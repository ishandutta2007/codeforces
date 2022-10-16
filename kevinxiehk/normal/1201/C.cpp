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
int arr[200005];
int n;
int cnt(int a) {
    int aaa = 0;
    for(int i = n / 2; i < n; i++) aaa += max(0LL, a - arr[i]);
    return aaa;
}
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int l = -1000000000, r = 2000000000;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        if(cnt(mid) <= k) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';

    return 0;
}