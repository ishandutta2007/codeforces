#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

vector <pair<int, int> > e[N];

bool dfs(int u, int pr, int k, int x, int &fase, int &mxr, int &len) {
    fase = 0;
    // fase = 0 - no vertex
    // fase = 1 - put
    // fase = 2 - end of put || izgib
    mxr = 0;
    int  vfase, vmxr, vlen;
    bool ok = true;
    len = 0;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i].first != pr) {
        ok &= dfs(e[u][i].first, u, k, x, vfase, vmxr, vlen);
        vmxr += e[u][i].second;
        if (fase == 0) {
            if (vfase == 0)
                if (vmxr > x)
                    if (k == 1) {
                        len = 1;
                        fase = 2;
                        if (mxr + e[u][i].second > x)
                            ok = false;
                        mxr = e[u][i].second;
                    } else {
                        len = 2;
                        fase = 1;
                    }
                else
                    mxr = max(mxr, vmxr);
            if (vfase == 1) {
                len = vlen + 1;
                fase = 1;
            }
            if (vfase == 2) {
                fase = 2;
                if (mxr + vmxr > x)
                    ok = false;
                mxr = vmxr;
            }
        } else if (fase == 1) {
                if (vfase == 0)
                    if (vmxr > x)
                        if (len == k)
                            ok = false;
                        else {
                            fase = 2;
                            mxr = 0;
                        }
                if (vfase == 1) {
                    if (vlen + len > k)
                        ok = false;
                    fase = 2;
                    mxr = 0;
                }
                if (vfase == 2)
                    ok = false;
            } else {
                    if (vfase == 0)
                        if (mxr + vmxr > x)
                            ok = false;
                    if (vfase > 0)
                        ok = false;
                }
    }
    if (len == k && fase == 1) {
        fase = 2;
        mxr = 0;
    }
    return ok;
}

int main() {
    int i, j, n, k, a, b, c;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i < n; ++i) {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int x = (l + r) / 2 - 1;
        if (dfs(1, 0, k, x, a, b, c))
            r = x + 1;
        else
            l = x + 1;
    }
    cout << l;
}