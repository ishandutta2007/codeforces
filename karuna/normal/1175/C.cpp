#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, n, k, mn, ans;
int arr[202020];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0; i<n; i++) cin >> arr[i];

        mn = INT_MAX;
        for (int i=0; i<n-k; i++) {
            if (mn > -arr[i]+arr[k+i]) {
                mn = -arr[i]+arr[k+i];
                ans = (arr[k+i]+arr[i])/2;
            }
        }

        cout << ans << '\n';
    }
}