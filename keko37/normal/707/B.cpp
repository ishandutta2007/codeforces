#include<iostream>
#include<vector>

using namespace std;

int n, m, k, x, y, d, sol=1000000005;
int a[100005];
int l[100005];
vector < pair <int, int> > v[100005];

int main () {
	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		cin >> x >> y >> d;
		v[x].push_back(make_pair(y, d));
		v[y].push_back(make_pair(x, d));
	}
	for (int i=0; i<k; i++) {
		cin >> a[i];
		l[a[i]]=1;
	}
	for (int i=0; i<k; i++) {
		int cvor=a[i];
		for (int j=0; j<v[cvor].size(); j++) {
			if (l[v[cvor] [j].first]==0) sol=min(sol, v[cvor] [j].second);
		}
	}
	if (sol==1000000005) cout << -1; else cout << sol;
	return 0;
}