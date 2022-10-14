#include<iostream>
#include<vector>

using namespace std;

int n, m;
int l[4005] [4005];
int p[4005];
vector < pair <int, int> > v;
int sol=1000000000;

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		l[a] [b]=1;
		l[b] [a]=1;
		p[a]++;
		p[b]++;
		v.push_back(make_pair(a, b));
	}
	for (int i=0; i<m; i++) {
		int a=v[i].first, b=v[i].second;
		for (int j=0; j<n; j++) {
			if (l[a] [j] && l[b] [j]) {
				sol=min(sol, p[a]+p[b]+p[j]-6);
			}
		}
	}
	if (sol==1000000000) cout << -1; else cout << sol;
	return 0;
}