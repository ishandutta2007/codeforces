#include <bits/stdc++.h>
using namespace std;
int a[1000000];
bool cmp(int a, int b) { return a > b; }
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n, cmp);
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum++;
            if (sum * a[i] >= m) {
                sum = 0;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}