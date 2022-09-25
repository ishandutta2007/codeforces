#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
LL a[maxn];
LL b[maxn * 2 + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 1) cin >> a[i];
    shuffle(a, a + n, std::mt19937(std::random_device()()));
    LL L = max(1LL, a[0] - n), R = a[0] + n;
    unordered_set<LL> s; 
    for(LL i = L; i <= R; i += 1) b[i - L] = i;
    for(LL i = 2; i <= 1000001; i += 1){
        LL rL = L % i == 0 ? L : L - L % i + i;
        LL rR = R - R % i;
        for(LL x = rL; x <= rR; x += i)
            while(b[x - L] % i == 0){
                b[x - L] /= i;
                s.insert(i);
            }
    }
    for(LL i = L; i <= R; i += 1) if(b[i - L] > 1) s.insert(b[i - L]);
    LL ans = n;
    for(LL x : s){
        LL pans = 0;
        for(int i = 0; i < n and pans < ans; i += 1)
            if(a[i] <= x) pans += x - a[i];
            else{
                LL y = a[i] % x;
                pans += min(y, x - y);
            }
        ans = min(ans, pans);
    }
    cout << ans;
    return 0;
}