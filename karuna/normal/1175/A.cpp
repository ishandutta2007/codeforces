#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll t, ans;
ll n, k;
int main() {
    cin >> t;

    while (t--) {
        cin >> n >> k;
        ans = 0;

        while (n) {
            ans += n%k;
            n -= n%k;

            if (n) {
                n/=k;
                ++ans;
            }
        }

        cout << ans << '\n';
    }
}