#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 200000;
using PII = pair<int, int>;
using PIII = pair<PII, int>;
using LL = long long;
PII pa[maxn + 1], pb[maxn + 1];
PIII pc[maxn + 1];
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
LL sum[maxn << 2], mpr[maxn << 2];
void update(int v, int tl, int tr, int p, int x){
    if(tl == tr) mpr[v] = sum[v] += x;
    else{
        if(p <= tm) update(ls, tl, tm, p, x);
        else update(rs, tm + 1, tr, p, x);
        sum[v] = sum[ls] + sum[rs];
        mpr[v] = max(mpr[ls], sum[ls] + max(mpr[rs], 0LL));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i += 1)
        cin >> pa[i].first >> pa[i].second;
    for(int i = 1; i <= m; i += 1)
        cin >> pb[i].first >> pb[i].second;
    for(int i = 1; i <= p; i += 1)
        cin >> pc[i].first.first >> pc[i].first.second >> pc[i].second;
    sort(pa + 1, pa + n + 1);
    sort(pb + 1, pb + m + 1);
    sort(pc + 1, pc + p + 1);
    for(int i = 1; i <= m; i += 1) update(1, 1, m, i, -pb[i].second + pb[i - 1].second);
    LL ans = -2e9;
    for(int i = 1, j = 1; i <= n; i += 1){
        while(j <= p and pc[j].first.first < pa[i].first){
            int x = upper_bound(pb + 1, pb + m + 1, (PII){pc[j].first.second, 1e9}) - pb;
            if(x <= m) update(1, 1, m, x, pc[j].second);
            j += 1;
        }
        ans = max(ans, mpr[1] - pa[i].second);
    }
    cout << ans;
    return 0;
}