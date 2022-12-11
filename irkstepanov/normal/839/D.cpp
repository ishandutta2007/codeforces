#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int mod = 1e9 + 7;

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void sub(int& a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;	
	}
}

void mul(int& a, int b) {
	ll c = ll(a) * ll(b);
	if (c >= mod) {
		c %= mod;
	}
	a = c;
}

const int amax = 1e6 + 10;
int k[amax];
int sum[amax];
int degs[amax];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");

	int n;
	cin >> n;
	
	while (n--) {
		int a;
		cin >> a;
		for (int d = 1; d * d <= a; ++d) {
			if (a % d == 0) {
				if (d != 1) {
					++k[d];
				}
				if (d * d != a) {
					++k[a / d];
				}
			}
		}
	}

	degs[0] = 1;
	for (int i = 1; i < amax; ++i) {
		degs[i] = degs[i - 1];
		mul(degs[i], 2);
	}

	int ans = 0;

	for (int d = amax - 1; d > 1; --d) {
		sum[d] = k[d];
		if (k[d]) {
			mul(sum[d], degs[k[d] - 1]);
		}
		for (int i = d * 2; i < amax; i += d) {
			sub(sum[d], sum[i]);
		}
		int val = sum[d];
		mul(val, d);
		add(ans, val);
	}

	cout << ans << "\n";

}