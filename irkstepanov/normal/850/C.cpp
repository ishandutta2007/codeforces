#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

bool bit(int mask, int pos) {
	return (mask >> pos) & 1;
}

map<int, int> res;

int solve(int mask) {
	if (res.count(mask)) {
		return res[mask];
	}
	set<int> setik;
	for (int k = 1; k < 30; ++k) {
		if ((mask >> k) > 0) {
			setik.insert(solve((mask & ((1 << k) - 1)) | (mask >> k)));
		}
	}
	for (int x = 0; ; ++x) {
		if (!setik.count(x)) {
			res[mask] = x;
			return x;
		}
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n;
	cin >> n;

	map<int, int> masks;

	while (n--) {
		int a;
		cin >> a;
		for (int d = 2; d * d <= a; ++d) {
			if (a % d == 0) {
				int cnt = 0;
				while (a % d == 0) {
					++cnt;
					a /= d;
				}
				masks[d] |= (1 << cnt);
			}
		}
		if (a != 1) {
			masks[a] |= (1 << 1);
		}
	}

	int sum = 0;
	for (auto it : masks) {
		sum ^= solve(it.second);
	}

	cout << (sum ? "Mojtaba\n" : "Arpa\n");

}