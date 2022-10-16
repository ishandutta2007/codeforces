#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1010;
int n, k;
string ans[N], s, t;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

map <string, int> m;
vector <pair <int, string> > v[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	int nrv = 0;
	for(int i = 1; i <= n; i++) {
		cin >> s >> t;
		string s1 = s.substr(0, 3);
		string s2 = s.substr(0, 2) + t.substr(0, 1);

		ans[i] = s1;

		if(m.count(s1))
			v[m[s1]].push_back({i, s2});
		else {
			v[nrv].push_back({i, s2});
			m[s1] = nrv++;
		}
	}

	queue <int> q;
	set <string> use;
	for(auto i : m) {
		if(v[i.nd].size() > 1) {
			q.push(i.nd);
			use.insert(i.st);
		}
	}

	while(!q.empty()) {
		int e = q.front();
		q.pop();

		for(auto i : v[e]) {
			ans[i.st] = i.nd;
			if(m.count(i.nd) && !use.count(i.nd)) {
				q.push(m[i.nd]);
				use.insert(i.nd);
			}
		}
	}

	set <string> fin;
	for(int i = 1; i <= n; i++)
		fin.insert(ans[i]);

	if(fin.size() != n) return cout << "NO\n", 0;
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}