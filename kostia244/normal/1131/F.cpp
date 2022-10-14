#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<int, int>
using namespace std;
//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937rng(chrono::steady_clock::now().time_since_epoch().count());

class UFDS {
private:
	vector<int> p, rank, setSizes;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSizes.assign(N, 1);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	int unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				setSizes[findSet(x)] += setSizes[findSet(y)];
				p[y] = x;
				return x;
			} else {
				setSizes[findSet(y)] += setSizes[findSet(x)];
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
				return y;
			}
		}
		return -1;
	}
	int setSize(int i) {
		return setSizes[findSet(i)];
	}
	int numDisjointSets() {
		return numSets;
	}
};

ll n, f, t, x, y, px, tn;
vector<vi> v;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n, tn = n, n--;
	v.resize(tn);
	for(int i = 0; i < tn; i++)
		v[i].pb(i);
	UFDS ufds(n + 4);
	while(n--) {
		cin >> f >> t, f--, t--;
		f = ufds.findSet(f);
		t = ufds.findSet(t);
		x = ufds.unionSet(f, t);
		if(x == -1) continue;
		px = x;
		if(x == t) {
			v[t].insert(v[t].end(), v[f].begin(), v[f].end()), v[f].clear();
			px = t;
		}else {
			v[f].insert(v[f].end(), v[t].begin(), v[t].end()), v[t].clear();
			px = f;
		}
	}
	for(auto& i : v[px]) cout << (i+1) << " ";
}