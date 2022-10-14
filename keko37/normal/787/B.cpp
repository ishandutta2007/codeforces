#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int MAXN = 10005;

int n, m, k, x, ok=1;
vector <int> v;
int l[MAXN];

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		v.clear();
		cin >> k;
		for (int j=0; j<k; j++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		bool temp=0;
		for (int j=0; j<v.size(); j++) {
			l[abs(v[j])]++;
			if (l[abs(v[j])]==2) temp=1;
		}
		if (temp==0) ok=0;
		for (int j=0; j<v.size(); j++) {
			l[abs(v[j])]--;
		}
	}
	if (ok) cout << "NO"; else cout << "YES";
	return 0;
}