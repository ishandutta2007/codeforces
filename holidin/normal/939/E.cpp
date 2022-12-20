#include <bits/stdc++.h>
using namespace std;
const long double e = 1e-10;
multiset <int> s;

int main() {
    int i, j, n, k, t, cnt = 1, mxt = 0;
    long long sum = 0;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cout << fixed << setprecision(10);
    for (i = 0; i < n; ++i) {
        cin >> t;
        if (t == 1) {
            if (mxt != 0) {
                sum -= mxt;
                s.insert(mxt);
            }
            cin >> mxt;
            sum += mxt;
        } else {
            while (s.size() > 0 && (sum + *s.begin())* 1.0 / (cnt + 1) - e < sum * 1.0 / cnt) {
                sum += *s.begin();
                s.erase(s.begin());
                ++cnt;
            }
            cout << (mxt - sum * 1.0 / cnt) << "\n";
        }
    }
}