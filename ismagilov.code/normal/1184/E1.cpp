#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

#define ft first
#define sc second
#define int ll

using namespace std;
typedef long long ll;

vector<int> p;


int findp(int v) {
	if(v == p[v]) 
		return v;
	p[v] = findp(p[v]);
	return p[v];
}

void merge(int a, int b) {
	a = findp(a);
	b = findp(b);
	if(a == b) 
		return;
	p[b] = a;
}

signed main() {
	/*#ifndef ONLINE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	p = vector<int> (n);
	for (int i = 0; i < n; i++) 
		p[i] = i;
	vector<pair<int, pair<int, int>>> have(m);
	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> have[i].sc.ft >> have[i].sc.sc >> have[i].ft;
		have[i].sc.ft--, have[i].sc.sc--;
		if(i == 0) {
			a = have[i].sc.ft;
			b = have[i].sc.sc;
		}
	}
	sort(have.begin(), have.end());
	bool flag = 0;
	int ans = 1e9;
	for (int i = 0; i < m; i++) {
		int a1 = have[i].sc.ft, b1 = have[i].sc.sc;
		if((findp(a1) == findp(a) && findp(b) == findp(b1)) || (findp(a1) == findp(b) && findp(b1) == findp(a))) {
			if(a != a1 || b != b1) {
				cout << have[i].ft << endl;
				return 0;
			}
			continue;
		}
		merge(a1, b1);
	}
	cout << ans << endl;
}