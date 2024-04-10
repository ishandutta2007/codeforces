#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[50][50];
bool b[50];
string s1, s2;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        cin >> s1 >> s2;
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (s1[i] > s2[i]) ok = 0;
            a[s1[i] - 'a'][s2[i] - 'a'] = 1;
        }
        if (!ok) {
            cout << -1 << endl;
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < 30; i++) {
            memset(b, 0, sizeof(b));
            for (int j = 0; j < i; j++) {
                if (a[j][i]) {
                    cnt++;
                    for (int k = i; k < 30; k++) {
                        b[k] |= a[j][k];
                        a[j][k] = 0;
                    }
                }
            }
            for (int j = i + 1; j < 30; j++) {
                a[i][j] |= b[j];
            }
        }
        cout << cnt << endl;
    }
}