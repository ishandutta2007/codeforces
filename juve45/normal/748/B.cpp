#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 256;
int n, ok[N];

string s, t;
set <char> mp[N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> s >> t;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == t[i]) 
			ok[t[i]] = 1;
		else {
			mp[s[i]].insert(t[i]);
			mp[t[i]].insert(s[i]);
		}
	}

	set <pair<char, char> > ans;

	for(char i = 'a'; i <= 'z'; i++) {
		if(ok[i]) {
			if(mp[i].size() > 0) return cout << "-1\n", 0;
		} else 	if(mp[i].size() > 1) return cout << "-1\n", 0;
		else if(mp[i].size() == 1) ans.insert({min(i, *mp[i].begin()), max(i, *mp[i].begin())});
	}
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i.st << ' ' << i.nd << '\n';
}