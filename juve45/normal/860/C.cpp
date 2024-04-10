#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define free frig304g

using namespace std;

const int N = 200100;
int n, k, place[N], a[N], t[N], nrex;
vector <pair<string, string> > ans;
string s;
vector <int> etot, ttoe, spare;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << '\n';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << "move " << p.st << ' ' << p.nd;  
}

set <int> free;
map <string, int> m;

int get(string s) { 
	if(!m.count(s)) {
		int nr = m.size();
		m[s] = nr + 1;
	}
	return m[s];
}

string ss[2 * N];

int main() {
	ios_base::sync_with_stdio(false);
	

	cin >> n;

	for(int i = 1; i <= n; i++) 
		free.insert(i), get(to_string(i)), ss[i] = to_string(i);

	for(int i = 1; i <= n; i++) {
		cin >> s >> t[i];
		a[i] = get(s);
		ss[a[i]] = s;
		nrex += t[i];
	}

	for(int i = 1; i <= n; i++) {
		free.erase(a[i]);
		// etot ttoe;
		if(a[i] > n)
			spare.push_back(i);
		else if(a[i] <= nrex && t[i] == 0)
			etot.push_back(a[i]);
		else if(a[i] > nrex && t[i])
			ttoe.push_back(a[i]);
	}

	if(free.empty()) {
		if(!etot.empty() && !ttoe.empty()) {
			int p = etot.back();
			ss[n + 1] = "juve45";
			a[n + 1] = n + 1;
			ans.push_back({ss[p], ss[n + 1]});
			spare.push_back(n + 1);
			free.insert(p);
			etot.pop_back();
		}
	}

	// free.size() = 0
	while(!etot.empty() || !ttoe.empty()) {
		if(*free.begin() <= nrex && ttoe.size() > 0) {
			int p = *free.begin();
			free.erase(free.begin());
			ans.push_back(make_pair(ss[ttoe.back()], ss[p]));
			free.insert(ttoe.back());
			ttoe.pop_back();
		}
		else if(*free.rbegin() > nrex && etot.size() > 0) {
			int p = *free.rbegin();
			free.erase(p);
			ans.push_back({ss[etot.back()], ss[p]});
			free.insert(etot.back());
			etot.pop_back();
		}
	}
	
	for(auto j : spare) {
		int p = *free.begin();
		if(t[j] == 0)
			p = *free.rbegin();
		free.erase(p);
		ans.push_back(make_pair(ss[a[j]], ss[p]));
	}

	cout << ans << '\n';

}