#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll x;
        cin >> x;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
        ll offset = 0;
        ll out = 0;
        ll budgetleft = x;
        ll tobuy = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]+offset <= budgetleft) {
                tobuy++;
                budgetleft -= a[i] + offset;
            }
        }
        while (true) {
            //cout << offset << ' ' << budgetleft << ' ' << tobuy << endl;
            if (tobuy == 0) break;

            ll daysuntilbad = (budgetleft / tobuy) + 1;
            out += tobuy * daysuntilbad;
            offset += daysuntilbad;

            // decrease budgetleft
            budgetleft -= daysuntilbad*tobuy;
            while (budgetleft < 0 && tobuy > 0) {
                budgetleft += a[tobuy-1] + offset;
                tobuy--;
            }
        }
        cout << out << endl;
    }
}