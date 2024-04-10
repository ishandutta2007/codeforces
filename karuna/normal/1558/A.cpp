#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b;

        int n = a + b;
        if (n % 2 == 0) {
            if (a < b) swap(a, b);
            int mn = a - n / 2;

            vector<int> Ans;
            for (int i = 0; i <= min(n / 2 - a + n / 2, n / 2); i++) {
                Ans.push_back(a - n / 2 + 2 * i);
            }
            sort(Ans.begin(), Ans.end());

            cout << Ans.size() << '\n';
            for (int x : Ans) cout << x << ' ';
            cout << '\n';
        }
        else {
            if (a < b) swap(a, b);

            int ma = (n + 1) / 2, mb = (n - 1) / 2;
            vector<int> Ans;
            for (int i = 0; i <= min(mb - a + ma, ma); i ++) {
                Ans.push_back(a - ma + 2 * i);
            }

            ma = (n - 1) / 2; mb = (n + 1) / 2;
            for (int i = 0; i <= min(mb - a + ma, ma); i ++) {
                Ans.push_back(a - ma + 2 * i);
            }
            sort(Ans.begin(), Ans.end());
            Ans.erase(unique(Ans.begin(), Ans.end()), Ans.end());

            cout << Ans.size() << '\n';
            for (int x : Ans) cout << x << ' ';
            cout << '\n';
        }
    }
}