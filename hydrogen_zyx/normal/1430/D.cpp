#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[200005];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> a + 1;
        int cnt = 0;
        int qian = 1;
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] != a[i - 1])
                qian++;
            else {
                cnt++;
                cnt = min(cnt, qian);
            }
        }
        cnt += (qian - cnt + 1) / 2;
        cout << cnt << endl;
    }
}