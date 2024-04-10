#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 1010;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int ans1 = ((n + k - 1) / k) * t;
    int ans2 = ans1;

    for (int x = 0; x <= nmax; ++x) {
        for (int y = 0; y <= nmax; ++y) {
            if (x * k + y * k >= n) {
                ans2 = min(ans2, max(x * t, y * t + d));
            }
        }
    }

    cout << (ans2 < ans1 ? "YES\n" : "NO\n");

}