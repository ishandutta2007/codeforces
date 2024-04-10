#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 100005;
const int INF = 1000000007;

int n, r, q, pot=1, cnt, ind, k, last;
int l[MAXN], dub[MAXN], tin[MAXN], tout[MAXN];
vector <int> v[MAXN];
vector < pair <int, int> > t[4*MAXN];

void dfs (int cvor, int par) {
	tin[cvor]=cnt; cnt++;
	tout[cvor]=-1;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		if (sus==par) continue;
		dub[sus]=dub[cvor]+1;
		dfs(sus, cvor);
		tout[cvor]=max(tout[cvor], tout[sus]);
	}
	t[pot+tin[cvor]].push_back(make_pair(dub[cvor], l[cvor]));
	if (tout[cvor]==-1) tout[cvor]=tin[cvor];
}

void build () {
	for (int i=pot-1; i>0; i--) {
		for (int j=0; j<t[i*2].size(); j++) {
			t[i].push_back(t[i*2] [j]);
		}
		for (int j=0; j<t[i*2+1].size(); j++) {
			t[i].push_back(t[i*2+1] [j]);
		}
	}
	for (int i=pot-1; i>0; i--) {
		sort(t[i].begin(), t[i].end());
		for (int j=1; j<t[i].size(); j++) {
			t[i] [j].second=min(t[i] [j].second, t[i] [j-1].second);
		}
	}
}

int upit (int cvor, int from, int to, int low, int high) {
	if (from<=low && high<=to) {
		int br=upper_bound(t[cvor].begin(), t[cvor].end(), make_pair(k, INF))-t[cvor].begin();
		if (br==0) return INF; return t[cvor] [br-1].second;
	}
	if (to<low || high<from) return INF;
	return min(upit(cvor*2, from, to, low, (low+high)/2), upit(cvor*2+1, from, to, (low+high)/2+1, high));
}

int main () {
	cin >> n >> r;
	while (pot<n) pot*=2;
	for (int i=1; i<=n; i++) {
		scanf("%d", &l[i]);
	}
	for (int i=0; i<n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(r, -1);
	build();
	cin >> q;
	for (int i=0; i<q; i++) {
		int p, q;
		scanf("%d%d", &p, &q);
		ind=(last+p)%n+1;
		k=(last+q)%n+dub[ind];
		last=upit(1, tin[ind], tout[ind], 0, pot-1);
		printf("%d\n", last);
	}
	return 0;
}