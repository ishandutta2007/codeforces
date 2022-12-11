#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const ll mod = 1e9 + 7;
const int nmax = 1e6 + 10;

void mul(ll& a, ll b)
{
	a *= b;
	if (a >= mod) {
		a %= mod;
	}
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> classId(m);
	int total = 1;

	while (n--) {
		map<int, int> cnt;
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			--x;
			++cnt[x];
		}
		map<int, vector<int> > classes;
		for (auto it : cnt) {
			classes[it.second].pb(it.first);
		}
		for (map<int, vector<int> >::iterator it = classes.begin(); it != classes.end(); ++it) {
			map<int, int> curr;
			for (int v : it->second) {
				if (curr.count(classId[v])) {
					classId[v] = curr[classId[v]];
				} else {
					curr[classId[v]] = total;
					classId[v] = total++;
				}
			}
		}
	}

	map<int, int> mapa;
	for (int i = 0; i < m; ++i) {
		++mapa[classId[i]];
	}

	vector<ll> fact(nmax);
	fact[0] = 1;
	for (int i = 1; i < nmax; ++i) {
		fact[i] = fact[i - 1];
		mul(fact[i], i);
	}

	ll ans = 1;
	for (auto it : mapa) {
		mul(ans, fact[it.second]);
	}
	cout << ans << "\n";

}