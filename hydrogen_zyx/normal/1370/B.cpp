#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10000];
vector<int> v[10000];
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> a[i];
        }
        for (int i = 2; i <= 5000; i++) {
            for (int i = 0; i < 5000; i++) v[i].clear();
            for (int j = 1; j <= 2 * n; j++) {
                v[a[j] % i].push_back(j);
            }
            int cnt = 0;
            if (i & 1) {
                for (int j = 1; j <= i / 2; j++) {
                    cnt += min(v[j].size(), v[i - j].size());
                }
                cnt += v[0].size() / 2;
            } else {
                for (int j = 1; j < i / 2; j++) {
                    cnt += min(v[j].size(), v[i - j].size());
                }
                cnt += v[0].size() / 2;
                cnt += v[i / 2].size() / 2;
            }
            if (cnt >= n - 1) {
                int ccc = 0;
                if (i & 1) {
                    for (int j = 1; i <= j / 2 && ccc != n - 1; j++) {
                        for (int k = 0; k < min(v[j].size(), v[i - j].size()) &&
                                        ccc != n - 1;
                             k++) {
                            cout << v[j][k] << ' ' << v[i - j][k] << endl;
                            ccc++;
                        }
                    }
                    for (int k = 0; k + 1 < v[0].size() && ccc != n - 1;
                         k += 2) {
                        ccc++;
                        cout << v[0][k] << ' ' << v[0][k + 1] << endl;
                    }
                    break;
                } else {
                    for (int j = 1; i < j / 2 && ccc != n - 1; j++) {
                        for (int k = 0; k < min(v[j].size(), v[i - j].size()) &&
                                        ccc != n - 1;
                             k++) {
                            cout << v[j][k] << ' ' << v[i - j][k] << endl;
                            ccc++;
                        }
                    }
                    for (int k = 0; k + 1 < v[0].size() && ccc != n - 1;
                         k += 2) {
                        ccc++;
                        cout << v[0][k] << ' ' << v[0][k + 1] << endl;
                    }
                    for (int k = 0; k + 1 < v[i / 2].size() && ccc != n - 1;
                         k += 2) {
                        ccc++;
                        cout << v[i / 2][k] << ' ' << v[i / 2][k + 1] << endl;
                    }
                    break;
                }
            }
        }
    }
}