#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;

int n;
vector<int> a, b;
vector<int> firstBet, lastBet;
vector<vector<int> > pos;

struct comp
{
	bool operator()(int a, int b)
	{
		return lastBet[a] < lastBet[b];
	}
};

int main()
{

	//ifstream cin("input.txt");

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	a.resize(n), b.resize(n);
	pos.resize(n);
	firstBet.assign(n, inf);
	lastBet.assign(n, -inf);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		--a[i];
		firstBet[a[i]] = min(firstBet[a[i]], i);
		lastBet[a[i]] = max(lastBet[a[i]], i);
		pos[a[i]].pb(i);
	}

	set<int, comp> s;
	for (int i = 0; i < n; ++i) {
		s.insert(a[i]);
	}

	int q;
	scanf("%d", &q);

	while (q--) {
		int k;
		scanf("%d", &k);
		vector<int> dead;
		for (int i = 0; i < k; ++i) {
			int x;
			scanf("%d", &x);
			--x;
			if (lastBet[x] != -inf) {
				dead.pb(x);
				s.erase(x);
			}
		}
		if (s.empty()) {
			printf("0 0\n");
			for (int x : dead) {
				s.insert(x);
			}
			continue;
		}
		set<int, comp>::iterator it = s.end();
		--it;
		int winner = *it;
		if (sz(s) == 1) {
			printf("%d %d\n", winner + 1, b[firstBet[winner]]);
			for (int x : dead) {
				s.insert(x);
			}
			continue;
		}
		--it;
		int prev = *it;
		int lf = -1, rg = sz(pos[winner]) - 1;
		while (rg - lf > 1) {
			int md = (lf + rg) >> 1;
			if (pos[winner][md] > lastBet[prev]) {
				rg = md;
			} else {
				lf = md;
			}
		}
		printf("%d %d\n", winner + 1, b[pos[winner][rg]]);
		for (int x : dead) {
			s.insert(x);
		}
	}

}