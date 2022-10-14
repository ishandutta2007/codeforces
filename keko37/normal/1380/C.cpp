#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int t, n, x;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int curr = 0, want = 0, sol = 0;
        for (int i = n-1; i >= 0; i--) {
            int val = (x + a[i] - 1) / a[i];
            want = max(want, val);
            curr++;
            if (curr == want) {
                sol++;
                curr = want = 0;
            }
        }
        cout << sol << '\n';
    }
    return 0;
}