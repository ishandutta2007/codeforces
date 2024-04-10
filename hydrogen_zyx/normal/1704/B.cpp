#include<bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;

int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        int cnt = 0;
        int mmin = 0x3f3f3f3f, mmax = -0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            mmin = min(mmin, a[i]);
            mmax = max(mmax, a[i]);
            if (mmax - mmin > 2 * x) {
                cnt++;
                mmin = mmax = a[i];
            }
        }
        cout << cnt << endl;
    }
}