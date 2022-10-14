#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> par;
#define M first
#define B second

const int MAXN = 100005;
const llint INF = 10000000000000000LL;

llint n, t, qx, ofs=1;
llint qa[MAXN], qb[MAXN], tin[MAXN], tout[MAXN], dp[MAXN];
vector <int> v[MAXN];
vector <par> line[4*MAXN], hull[4*MAXN];

inline bool bad (par l1, par l2, par l3) {
	return ((long double) l3.B-l1.B)/(l1.M-l3.M)<=((long double) l2.B-l1.B)/(l1.M-l2.M);
}

void ubaci (int x, par ln) {
	if (hull[x].size()==1 && hull[x] [0].M == ln.M && hull[x] [0].B >= ln.B) hull[x].clear();
	while (hull[x].size()>1 && bad(hull[x] [hull[x].size()-2], hull[x] [hull[x].size()-1], ln)) {
		hull[x].pop_back();
	}
	hull[x].push_back(ln);
}

bool manji (int x, int ind) {
	return qx*(hull[x] [ind].M-hull[x] [ind+1].M)>=(hull[x] [ind+1].B-hull[x] [ind].B);
}

llint upit (int x) {
	int low=0, high=hull[x].size()-1, md;
	while (low<high) {
		md=(low+high)/2;
		if (manji(x, md)) {
			low=md+1;
        } else {
			high=md;
		}
	}
	return qx*hull[x] [low].M + hull[x] [low].B;
}

void gen (int x) {
	sort(line[x].begin(), line[x].end());
	for (int i=line[x].size()-1; i>=0; i--) {
		ubaci(x, line[x] [i]);
	}
}

void update (int x, par ln) {
	int pot=1;
	while (x) {
		line[x].push_back(ln);
		if (line[x].size()==pot) gen(x);
		x/=2;
		pot*=2;
	}
}

llint kveri (int x, int from, int to, int low, int high) {
	if (from<=low && high<=to) return upit(x);
	if (to<low || high<from) return INF;
	return min(kveri(x*2, from, to, low, (low+high)/2), kveri(x*2+1, from, to, (low+high)/2+1, high));
}

void dfs (int x, int rod) {
	tin[x]=tout[x]=t;
	t++;
	for (int i=0; i<v[x].size(); i++) {
		int sus=v[x] [i];
		if (sus==rod) continue;
		dfs(sus, x);
		tout[x]=max(tout[x], tout[sus]);
	}
	if (v[x].size()==1 && x!=1) {
		dp[x]=0;
	} else {
		qx=qa[x];
		dp[x] = kveri(1, tin[x]+1, tout[x], 0, ofs-1);
	}
	update(tin[x]+ofs, make_pair(qb[x], dp[x]));
}

int main () {
	cin >> n;
	while (ofs<n) ofs*=2;
	for (int i=1; i<=n; i++) {
		scanf("%I64d", &qa[i]);
	}
	for (int i=1; i<=n; i++) {
		scanf("%I64d", &qb[i]);
	}
	for (int i=0; i<n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	for (int i=1; i<=n; i++) {
		printf("%I64d ", dp[i]);
	}
	return 0;
}