#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int get(int x) {
    cout << "? " << x + 1 << endl;
    int ans;
    cin >> ans;
    --ans;
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        get(0);
        vector<int> ans(n, -1);
        for (int i = 0; i < n - 1; ++i) {
            if (ans[i] != -1) {
                continue;
            }
            int j = get(i);
            vector<int> vals;
            vals.pb(j);
            while (true) {
                int x = get(i);
                if (x == j) {
                    break;
                }
                vals.pb(x);
            }
            int pos = -1;
            for (int k = 0; k < sz(vals); ++k) {
                if (vals[k] == i) {
                    pos = k;
                    break;
                }
            }
            assert(pos != -1);
            vector<int> order;
            for (int k = pos; k < sz(vals); ++k) {
                order.pb(vals[k]);
            }
            for (int k = 0; k < pos; ++k) {
                order.pb(vals[k]);
            }
            for (int k = 0; k < sz(order); ++k) {
                ans[order[k]] = order[(k + 1) % sz(order)];
            }
        }
        if (ans[n - 1] == -1) {
            ans[n - 1] = n - 1;
        }
        cout << "! ";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }

}