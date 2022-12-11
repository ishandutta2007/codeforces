#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("f.out");
	//freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> lf(n, -inf);
    vector<int> rg(n, inf);

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            lf[i] = i;
        } else if (i) {
            lf[i] = lf[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            rg[i] = i;
        } else if (i != n - 1) {
            rg[i] = rg[i + 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << min(i - lf[i], rg[i] - i) << " ";
    }
    cout << "\n";

}