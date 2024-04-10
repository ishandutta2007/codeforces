#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
int a[maxn], c[maxn];
int mp[maxn * 2 + 10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int m = min(n, 100);
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        c[a[i]] += 1;
    }
    int f = *max_element(c + 1, c + m + 1);
    if(f == n){
        cout << "0";
        return 0;
    }
    if(count(c + 1, c + m + 1, f) > 1){
        cout << n;
        return 0;
    }
    int x = max_element(c + 1, c + m + 1) - c;
    int ans = 0;
    for(int i = 1; i <= m; i += 1) if(i != x){
        for(int j = -n; j <= n; j += 1) mp[j + maxn] = -1;
        int sum = 0;
        mp[sum + maxn] = 0;
        for(int j = 1; j <= n; j += 1){
            if(a[j] == x) sum += 1;
            if(a[j] == i) sum -= 1;
            if(mp[sum + maxn] != -1) ans = max(j - mp[sum + maxn], ans);
            else mp[sum + maxn] = j;
        }
    }
    cout << ans;
    return 0;
}