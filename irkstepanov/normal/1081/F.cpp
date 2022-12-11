#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int get(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    if (n % 2 == 0) {
        vector<int> ans(n);
        for (int r = 0; r < n; ++r) {
            int a = t;
            int d = -1;
            while (d == -1) {
                int x = get(r, r);
                int y = get(r, r);
                if (y == a) {
                    continue;
                }
                d = y;
            }
            ans[r] = (a + d - n + 1) / 2;
            a = -1;
            while (a == -1) {
                int x = get(r, r);
                int y = get(r, r);
                if (y == t) {
                    a = t;
                }
            }
        }
        cout << "! ";
        for (int i = 0; i < n; ++i) {
            cout << ans[i];
        }
        cout << endl;
        return 0;
    }

    vector<int> sum(n);
    for (int r = 1; r < n; ++r) {
        int a = t;
        int d = -1;
        while (d == -1) {
            int x = get(r - 1, r);
            int y = get(r - 1, r);
            if (y == a) {
                continue;
            }
            d = y;
        }
        sum[r] = (a + d - n + 2) / 2;
        a = -1;
        while (a == -1) {
            int x = get(r - 1, r);
            int y = get(r - 1, r);
            if (y == t) {
                a = t;
            }
        }
    }

    int total = 0;
    for (int i = 1; i < n; i += 2) {
        total += sum[i];
    }

    vector<int> ans(n);

    ans[n - 1] = t - total;
    for (int i = n - 1; i; --i) {
        ans[i - 1] = sum[i] - ans[i];
    }

    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
    cout << endl;
    
}