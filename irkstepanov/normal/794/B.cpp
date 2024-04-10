#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int ops = 100;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ld h;
    cin >> h;

    ld s = h / ld(2 * n);
    ld s0 = h / ld(2);
    vector<ld> ans(n - 1);
    ld used = 0;

    for (int i = 0; i < n - 1; ++i) {
        ld lf = 0, rg = h;
        for (int op = 0; op < ops; ++op) {
            ld md = (lf + rg) / 2;
            ld x = s0 * (md / h) * (md / h) - used;
            if (x >= s) {
                rg = md;
            } else {
                lf = md;
            }
        }
        ans[i] = lf;
        used = s0 * (lf / h) * (lf / h);
    }

    cout << fixed;
    cout.precision(12);
    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}