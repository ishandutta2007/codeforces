#include<iostream>
#include<set>
#include<vector>

using namespace std;

const int MAXN = 105;

int n;
int l[MAXN], p[MAXN];
set < pair <int, int> > s;
vector < pair <int, int> > v;

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> l[i];
	}
	p[1]=1;
	s.insert(make_pair(-l[1], 1));
	while (!s.empty()) {
		int cnt=s.begin()->first;
		int ind=s.begin()->second;
		cnt=-cnt;
		s.erase(s.begin());
		for (int i=0; i<cnt; i++) {
			int maxi=-1;
			for (int j=1; j<=n; j++) {
				if (p[j]==0) maxi=max(maxi, l[j]);
			}
			if (maxi==-1) break;
			for (int j=1; j<=n; j++) {
				if (p[j]==0 && maxi==l[j]) {
					p[j]=1;
					v.push_back(make_pair(ind, j));
					s.insert(make_pair(-l[j], j));
					break;
				}
			}
		}
	}
	for (int i=1; i<=n; i++) {
		if (p[i]==0) {
			cout << -1;
			return 0;
		}
	}
	cout << v.size() << endl;
	for (int i=0; i<v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}