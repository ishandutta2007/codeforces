#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 1e6 + 100;

ll t[2 * nmax];
int n;

void update(int pos)
{
	for (pos += n; pos; pos >>= 1) {
		++t[pos];
	}
}

ll get(int l, int r)
{
	ll ans = 0;
	for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
		if (l & 1) {
			ans += t[l];
		}
		if (!(r & 1)) {
			ans += t[r];
		}
	}
	return ans;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> n >> k;
    if (k > n - k) {
        k = n - k;
    }

	int curr = 0;
	ll ans = 1;

	for (int i = 0; i < n; ++i) {
		int rg = curr + k;
		if (rg >= n) {
			rg -= n;
		}
		ll sum = 0;
		if (curr < rg) {
			sum = get(curr + 1, rg - 1);
		} else {
			sum = get(curr + 1, n - 1) + get(0, rg - 1);
		}
		ans += sum + 1;
		update(curr);
		update(rg);
		printf("%lld ", ans);
		curr = rg;
	}
	printf("\n");

}