#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T;
ll c, h, t;
ll ub, lb, mid;
int main() {
    cin >> T;
    while (T--) {
        cin >> h >> c >> t;
        h -= c;
        t -= c;
        ub = 1000000;
        lb = 2;
        if ((long double)t <= (long double)h / 2.0) {
            cout << 2 << "\n";
            continue;
        }
        if ((long double)t > 5.0 * (long double)h / 6.0) {
            cout << 1 << "\n";
            continue;
        }
        while (ub >= lb) {
            mid = (ub + lb) / 2;
            if (mid * h > t * (2 * mid - 1))
                lb = mid + 1;
            else
                ub = mid - 1;
        }
        if(abs((long double)(ub+1)*h/(2*ub+1)-(long double)t)<abs((long double)(ub)*h/(2*ub-1)-(long double)t))cout << 2*ub+1;
        else cout << 2*ub-1;
        cout << "\n";
    }
    return 0;
}