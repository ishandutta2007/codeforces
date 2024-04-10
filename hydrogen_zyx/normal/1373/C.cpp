#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
int main() {
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        cin >> a;
        ll k = 0, sum = 0, ans = 0;
        ll mmin = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '+')
                sum++;
            else
                sum--;
            if (sum < mmin) {
                mmin = sum;
                ans += i + 1;
            }
        }
        cout << ans + a.length() << endl;
    }
}