#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 1e6 + 100;

int p[nmax];
char used[nmax];

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		--p[i];
	}

	memset(used, 0, sizeof(used));

	vector<int> cycles;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		used[i] = true;
		if (p[i] == i) {
			cycles.pb(1);
			continue;
		}
		int curr = p[i];
		int len = 2;
		used[curr] = true;
		while (p[curr] != i) {
			++len;
			curr = p[curr];
			used[curr] = true;
		}
		cycles.pb(len);
	}

	map<int, int> mapa;
	for (int x : cycles) {
		++mapa[x];
	}

	bitset<nmax> b;
	b[0] = 1;
	for (auto it : mapa) {
		if (it.second <= 1000) {
			for (int u = 1; u <= it.second; ++u) {
				b |= (b << it.first);
			}
			continue;
		}
		vector<int> minCnt(nmax);
		for (int i = 0; i < nmax; ++i) {
			if (b[i]) {
				if (!b[i + it.first] && minCnt[i] + 1 <= it.second) {
					b[i + it.first] = 1;
					minCnt[i + it.first] = minCnt[i] + 1;
				}
			}
		}
	}

	if (b[k]) {
		cout << k << " ";
	} else {
		cout << k + 1 << " ";
	}

	int ones = 0;
	int ans = 0;
	int curr = k;
	for (int i = 0; i < sz(cycles) && curr; ++i) {
		if (curr >= cycles[i] / 2) {
			ans += (cycles[i] / 2) * 2;
			curr -= cycles[i] / 2;
			if (cycles[i] & 1) {
				++ones;
			}
			continue;
		}
		ans += curr * 2;
		curr = 0;
	}

	if (curr) {
		ans += min(curr, ones);
	}
	cout << ans << "\n";

}