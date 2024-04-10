#include <bits/stdc++.h>

using namespace std;
const int N = 1 << 20;

vector<int> g[N];

int cnt[N];
int leaf[N];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    bool f = 1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            cnt[g[i][0]]++;
            leaf[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!leaf[i] && cnt[i] < 3) f = 0;
    }
    if (f) cout << "Yes" << endl;
    else cout << "No" << endl;
}