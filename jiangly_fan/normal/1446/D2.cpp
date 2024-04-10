#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
constexpr int sp = 447;
int a[maxn], c[maxn];
int mp[maxn * 2 + 10];
int cnt[maxn + 1];
int cxt[maxn + 1];
int m;
void insert(int x){
    cxt[cnt[x]] -= 1;
    cnt[x] += 1;
    cxt[cnt[x]] += 1;
    m = max(m, cnt[x]);
}
void remove(int x){
    cxt[cnt[x]] -= 1;
    cnt[x] -= 1;
    cxt[cnt[x]] += 1;
    if(cxt[m] == 0) m -= 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        c[a[i]] += 1;
    }
    int f = *max_element(c + 1, c + n + 1);
    if(f == n){
        cout << "0";
        return 0;
    }
    if(count(c + 1, c + n + 1, f) > 1){
        cout << n;
        return 0;
    }
    int x = max_element(c + 1, c + n + 1) - c;
    int ans = 0;
    for(int i = 1; i <= n; i += 1) if(i != x and c[i] >= 447){
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
    for(int i = 1; i <= min(f, 447); i += 1){
        for(int i = 1; i <= n; i += 1) cnt[i] = cxt[i] = 0;
        cxt[0] = n;
        m = 0;
        for(int j = 1, k = 1, xt = 0; j <= n; j += 1){
            while(k <= n and xt + (a[k] == x) <= i){
                insert(a[k]);
                xt += a[k] == x;
                k += 1;
            }
            //cout << i << " " << j << " " << k << " m = " << m << " " << cxt[m] << '\n';
           // for(int i = 1; i <= n; i += 1) cout << cnt[i] << " ";
            //cout << "\n";
            if(cxt[m] >= 2) ans = max(ans, k - j);
            remove(a[j]);
            xt -= a[j] == x;
        }
    }
    cout << ans;
    return 0;
}