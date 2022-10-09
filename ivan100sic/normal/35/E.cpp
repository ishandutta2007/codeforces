#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int h[100005], l[100005], r[100005];

int main() {

#ifdef ONLINE_JUDGE
	#define cin fin
	#define cout fout
	ifstream fin("input.txt");
	ofstream fout("output.txt");
#endif

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> h[i] >> l[i] >> r[i];
	
	multiset<int> s;
	s.insert(0);
	map<int, vector<pair<int, int>>> mp;
	for (int i=0; i<n; i++) {
		mp[l[i]].push_back({1, h[i]});
		mp[r[i]].push_back({0, h[i]});
	}

	vector<pair<int, int>> w, q;

	for (auto it = mp.begin(); it != mp.end(); ++it) {
		for (auto [t, x] : it->second) {
			if (t) {
				s.insert(x);
			} else {
				s.erase(s.find(x));
			}
		}
		w.push_back({it->first, *s.rbegin()});
	}

	for (auto [x, y] : w) {
		if (q.size() && y == q.back().second) {
			//
		} else if (q.size()) {
			int y2 = q.back().second;
			q.push_back({x, y2});			
			q.push_back({x, y});			
		} else {
			if (y > 0) {
				q.push_back({x, 0});			
			}
			q.push_back({x, y});			
		}
	}

	cout << q.size() << '\n';
	for (auto [x, y] : q)
		cout << x << ' ' << y << '\n';
}