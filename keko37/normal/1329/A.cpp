#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 100005;

llint n, m, sum;
llint a[MAXN], sol[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    llint rig = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        sum += a[i];
        if (i == 1) sol[i] = 1; else sol[i] = sol[i - 1] + a[i - 1];
        rig = max(rig, i - 1 + a[i]);
    }
    if (sum < n || rig > n) {
        cout << -1;
        return 0;
    }
    llint ofs = 0;
    cout << 1 << " ";
    for (int i = 2; i <= m; i++) {
        llint d = sum - n;
        ofs += min(a[i - 1] - 1, d);
        sum -= min(a[i - 1] - 1, d);
        cout << sol[i] - ofs << " ";
    }
    return 0;
}