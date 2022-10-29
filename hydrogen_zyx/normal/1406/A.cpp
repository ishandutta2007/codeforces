#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        int now = 0;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (a[i] == now)
                now++;
            else
                v.push_back(a[i]);
        }
        int nnow = 0;
        for (auto x : v) {
            if (x == nnow) nnow++;
        }
        cout << now + nnow << endl;
    }
}