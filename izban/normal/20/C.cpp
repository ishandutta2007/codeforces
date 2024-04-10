#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn=1<<17;
const ll inf=1LL<<50;
const double eps=1e-9;

int n,m;
int p[maxn];
ll d[maxn];
vector<pair<int,int>> e[maxn];

void dijkstra(int v) {
	set<pair<ll, int>> s;
	for (int i=2; i<=n; i++) {
		d[i]=inf;
		s.insert(make_pair(d[i],i));
	}
	s.insert(make_pair(0,1));
	while (!s.empty()) {
		v=s.begin()->second;
		s.erase(s.begin());
		for (int i=0; i<e[v].size(); i++) {
			int u=e[v][i].first;
			if (d[u]>d[v]+e[v][i].second) {
				s.erase(s.find(make_pair(d[u],u)));
				d[u]=d[v]+e[v][i].second;
				s.insert(make_pair(d[u],u));
				p[u]=v;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back(make_pair(y,z));
		e[y].push_back(make_pair(x,z));
	}
	dijkstra(1);
	if (p[n]==0) {
		cout << -1;
		return 0;
	}
	int v=n; p[0]=-1;
	vector<int> ans;
	do {
		ans.push_back(v);
		v=p[v];
	} while (p[v]!=-1);
	reverse(ans.begin(),ans.end());
	for (int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
	return 0;
}