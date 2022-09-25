#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 640000;
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
int p[maxn], q[maxn], ip[maxn];
int sum[maxn << 2], ssum[maxn << 2];
void update(int v, int tl, int tr, int p, int x){
    if(tl == tr) ssum[v] = max(ssum[v], sum[v] += x);
    else{
        if(p <= tm) update(ls, tl, tm, p, x);
        else update(rs, tm + 1, tr, p, x);
        sum[v] = sum[ls] + sum[rs];
        ssum[v] = max(ssum[rs], sum[rs] + ssum[ls]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> p[i];
        ip[p[i]] = i;
    }
    for(int i = 1; i <= n; i += 1) cin >> q[i];
    update(1, 1, 2 * n, ip[n] * 2 - 1, 1);
    cout << n << " ";
    for(int i = 1, ans = n; i < n; i += 1){
        update(1, 1, 2 * n, 2 * q[i], -1);
        while(ssum[1] == 0){
            ans -= 1;
            update(1, 1, 2 * n, ip[ans] * 2 - 1, 1);
        }
        cout << ans << " ";
    }
    return 0;
}