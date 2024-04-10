#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
ll t;
int a[200005];
basic_string<int> inv[200005];

struct fw {
	vector<ll> cnt, sum;
	int n, h;

	fw(int n) : cnt(n+1, 0), sum(n+1, 0), n(n) {
		h = n / 2;
		while (h != (h&-h)) h -= h & -h;
	}

	void add(int i, int c, int s) {
		for (int j=i; j<=n; j+=j&-j) {
			cnt[j] += c;
			sum[j] += s;
		}
	}

	int seek(int c) {
		int i = 0;
		for (int step=h; step; step>>=1) {
			if (cnt[i + step] <= c) {
				c -= cnt[i + step];
				i += step;
			}
		}
		return i;
	}

	pair<ll, ll> get(int x) {
		pair<ll, ll> z = {0, 0};
		for (; x; x-=x&-x) {
			z.first += cnt[x];
			z.second += sum[x];
		}
		return z;
	}
} tree(4);

void add(int i) {
	tree.add(i, 1, a[i]);
}

bool ok(int j) {
	if (!j) return true;
	int cn = tree.get(j).first;
	int km = cn % m ? cn - cn % m : cn - m;
	int y = tree.seek(km);
	return tree.get(y).second + tree.get(j).second <= t;
}

int j, solved;
void solve() {
	while (!ok(j)) j--;
	solved = tree.get(j).first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int tcc;
	cin >> tcc;
	while (tcc--) {
		cin >> n >> m >> t;

		j = n;

		set<int> uq;
		uq.insert(1);
		if (t <= 200000)
			uq.insert(t);

		for (int i=1; i<=n; i++) {
			cin >> a[i];
			inv[a[i]] += i;

			if (a[i] <= t)
				uq.insert(a[i]);
		}

		tree = fw(2*n);

		int bsolved = -1, bd = -1;

		for (int x : uq) {
			for (int i : inv[x])
				add(i);
			solve();
			if (solved > bsolved) {
				bsolved = solved;
				bd = x;
			}
		}

		cout << bsolved << ' ' << bd << '\n';

		for (int i=1; i<=n; i++)
			inv[a[i]] = {};
	}
}