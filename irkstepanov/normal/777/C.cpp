#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

int main()
{

	//freopen("input.txt", "r", stdin);
	//ifstream cin("input.txt");
    //ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> ptr(n);
    for (int i = 0; i < n; ++i) {
        ptr[i] = i;
    }

    for (int j = 0; j < m; ++j) {
        int prev = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i][j] <= a[i + 1][j]) {
                continue;
            } else {
                for (int k = prev; k <= i; ++k) {
                    ptr[k] = max(ptr[k], i);
                }
                prev = i + 1;
            }
        }
        for (int k = prev; k < n; ++k) {
            ptr[k] = max(ptr[k], n - 1);
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << (ptr[l] >= r ? "Yes\n" : "No\n");
    }

}