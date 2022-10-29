#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

typedef pair<int, string> pis;
map<pis, vector<int> > mp;

int main(){
	int n;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s, t;
		cin >> s >> t;
		int vis = 0;
		for (auto &x : t)
			vis |= (1 << (x - 'a'));
		while (s.length() && ((vis >> (s.back() - 'a')) & 1))
			s.pop_back();
		mp[pis(vis, s)].push_back(i);
	}
	cout << mp.size() << endl;
	for (auto &x : mp) {
		cout << x.second.size();
		for (auto &y : x.second)
			cout << ' ' << y;
		cout << endl;
	}
	return 0;
}