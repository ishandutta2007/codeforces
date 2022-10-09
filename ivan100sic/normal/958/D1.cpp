#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct rac {
	int x, y;
	bool operator< (const rac& b) const {
		return x*b.y < y*b.x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int m;
	cin >> m;
	map<rac, int> mp;
	vector<rac> d(m);
	for (int i=0; i<m; i++) {
		string s;
		cin >> s;
		int j = s.find('+');
		int k = s.find('/');
		int a = stoi(s.substr(1, j-1));
		int b = stoi(s.substr(j+1, k-j-1));
		int c = stoi(s.substr(k+1));
		d[i] = {a+b, c};
		mp[d[i]]++;
	}
	for (int i=0; i<m; i++)
		cout << mp[d[i]] << " \n"[i == m-1];
}