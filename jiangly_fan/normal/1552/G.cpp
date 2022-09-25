#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
void no(){
    cout << "REJECTED";
    exit(0);
}
int p[10][40], q[10];
int n, k;
void dfs(int v[], int i){
    if (i == k) {
        int m = 1, un = -1;
        for (int j = 0; j < n; j += 1) if (v[j] == 0) {
            if (un != -1) no();
            un = j;
            for (int k = 0; k < j; k += 1) if (v[k] == 2) no();
            for (int k = j + 1; k < n; k += 1) if (v[k] == 1) no();
        }
        if (un != -1) return;
        for (int j = 0; j < n; j += 1) {
            if (v[j] < m) no();
            m = v[j];
        }
        return;
    }
    int cnt[3]{};
    for (int j = 0; j < q[i]; j += 1) cnt[v[p[i][j]]] += 1;
    for (int j = 0; j <= cnt[0]; j += 1) {
        int L = j + cnt[1];
        int w[n]{};
        for (int k = 0; k < n; k += 1) w[k] = v[k];
        for (int j = 0; j < q[i]; j += 1)
            if (j < L) w[p[i][j]] = 1;
            else w[p[i][j]] = 2;
        dfs(w, i + 1);
    }
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> n >> k;
    for (int i = 0; i < k; i += 1) {
        cin >> q[i];
        for (int j = 0; j < q[i]; j += 1) {
            cin >> p[i][j];
            p[i][j] -= 1;
        }
    }
    int v[n]{};
    dfs(v, 0);
    cout << "ACCEPTED";
    return 0;
}