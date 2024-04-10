#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("f.out");
	//freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n, k;
    cin >> n >> k;

    vector<vector<int> > ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        if (k == 1) {
            ans[i][i] = 1;
            --k;
        } else if (k >= 1) {
            ans[i][i] = 1;
            --k;
            for (int j = i + 1; j < n && k >= 2; ++j, k -= 2) {
                ans[i][j] = ans[j][i] = 1;
            }
        }
    }

    if (k) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

}