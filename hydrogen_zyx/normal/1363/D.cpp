#include <bits/stdc++.h>
using namespace std;
int f[2000];
vector<int> v[2000];
bool vis[2000];
bool numvis[2000];
int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 2000; i++) v[i].clear();
        memset(f, 0, sizeof(f));
        memset(numvis, 0, sizeof(numvis));
        int n, k, num = 0;
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                v[i].push_back(++num);
                int a;
                cin >> a;
                numvis[a] = 1;
                f[num] = a;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (numvis[i] == 0) {
                f[++num] = i;
            }
        }
        cout << '?' << ' ' << n << ' ';
        for (int i = 1; i <= n; i++) cout << i << ' ';
        cout << endl;
        cout.flush();
        int allmax;
        cin >> allmax;
        int l = 0, r = k, mid;
        while (l < r - 1) {
            mid = (l + r) >> 1;
            int size = 0;
            for (int i = l; i < mid; i++) size += v[i].size();
            cout << '?' << ' ' << size << ' ';
            for (int i = l; i < mid; i++) {
                for (int j = 0; j < v[i].size(); j++) {
                    cout << f[v[i][j]] << ' ';
                }
            }
            cout << endl;
            cout.flush();
            int midmax;
            cin >> midmax;
            if (midmax == allmax) {
                r = mid;
            } else {
                l = mid;
            }
        }
        for (int i = 0; i < v[l].size(); i++) vis[v[l][i]] = 1;
        cout << '?' << ' ' << n - v[l].size() << ' ';
        for (int i = 1; i <= n; i++)
            if (!vis[i]) cout << f[i] << ' ';
        cout << endl;
        cout.flush();
        int pointmax;
        cin >> pointmax;
        cout << '!' << ' ';
        for (int i = 0; i < k; i++) {
            if (i == l)
                cout << pointmax << ' ';
            else
                cout << allmax << ' ';
        }
        cout << endl;
        string s;
        cin >> s;
    }
}