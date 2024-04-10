 #include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 200100;
int n, k;
string s;

set<int> st[3];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << ' ';
	for(auto e : v) out << e + 1 << ' ';
	cout << '\n';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;

	for(int i = 0; i < s.size(); i++) {
		st[s[i] - '0'].insert(i);
	}

	vector <vector <int> > ans;

	while(!st[0].empty()) {

		vector <int> a;

		int zero = *st[0].begin();
		st[0].erase(zero);
		a.push_back(zero);
		
		while(true) {
			if(st[1].size() > 0 && st[0].size() > 0 && st[1].lower_bound(zero) != st[1].end()) {
				int one = *st[1].lower_bound(zero);
				auto it = st[0].lower_bound(one);
				if(it == st[0].end()) {
					cout << "-1\n";
					return 0;
				}
				zero = *it;
				st[1].erase(one);
				st[0].erase(zero);
				a.push_back(one);
				a.push_back(zero);
			} else break;
		}
		ans.push_back(a);
	}
	if(st[0].size() + st[1].size() == 0) {
		cout << ans.size() << '\n';
		for(auto i : ans) cout << i;
	}
	else cout << "-1\n";
}