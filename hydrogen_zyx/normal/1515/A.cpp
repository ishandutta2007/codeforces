#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100005;
int a[N];

int main() {
    ios::sync_with_stdio(false),
            cin.tie(nullptr),
            cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int sum = 0;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
        }
        if (sum == k) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            sum = 0;
            for (int i = 1; i <= n; i++) {
                if (sum + a[i] != k) {
                    cout << a[i] << ' ';
                    sum += a[i];
                } else {
                    sum += a[i + 1];
                    cout << a[i + 1] << ' ';
                    cout << a[i] << ' ';
                    sum += a[i];
                    i++;
                }
            }
        }
        cout << endl;
    }
}