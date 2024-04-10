#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;

int n, m, s, cnt;
int bio[MAXN], scc[MAXN], a[MAXN], b[MAXN], w[MAXN];
llint val[MAXN], dp[MAXN], sol;
vector < pair <int, int> > v[MAXN], g[MAXN], r[MAXN];
stack <int> st;

void dfs1 (int cvor) {
	if (bio[cvor]) return;
	bio[cvor]=1;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i].first;
		dfs1(sus);
	}
	st.push(cvor);
}

void dfs2 (int cvor) {
	if (scc[cvor]) return;
	scc[cvor]=cnt;
	for (int i=0; i<g[cvor].size(); i++) {
		int sus=g[cvor] [i].first;
		dfs2(sus);
	}
}

int get_val (int len) {
	int low=0, high=20100, mid;
	while (low<high) {
		mid=(low+high+1)/2;
		if (mid*(mid+1)/2<=len) {
			low=mid;
		} else {
			high=mid-1;
		}
	}
	return low;
}

llint sum (int len) {
	llint t=get_val(len);
	return (t+1)*len-(t+1)*t*(t+2)/6;
}

llint f (int cvor) {
	if (dp[cvor]!=-1) return dp[cvor];
	llint res=val[cvor];
	for (int i=0; i<r[cvor].size(); i++) {
		int sus=r[cvor] [i].first;
		llint dis=r[cvor] [i].second;
		res=max(res, val[cvor]+dis+f(sus));
	}
	dp[cvor]=res;
	return res;
}

int main () {
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		scanf("%d%d%d", &a[i], &b[i], &w[i]);
		v[a[i]].push_back(make_pair(b[i], w[i]));
		g[b[i]].push_back(make_pair(a[i], w[i]));
	}
	cin >> s;
	for (int i=1; i<=n; i++) {
		dfs1(i);
	}
	while (!st.empty()) {
		int cvor=st.top();
		st.pop();
		if (!scc[cvor]) {
			cnt++;
			dfs2(cvor);
		}
	}
	for (int i=0; i<m; i++) {
		if (scc[a[i]]==scc[b[i]]) {
			val[scc[a[i]]]+=sum(w[i]);
		} else {
			r[scc[a[i]]].push_back(make_pair(scc[b[i]], w[i]));
		}
	}
	cout << f(scc[s]);
	return 0;
}