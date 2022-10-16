#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << ' '; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
int n, k, limit[N], f[N], sum, x;
vector <int> res[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> x; 
		f[x]++;
	}

	for(int i = 1; i <= k; i++) cin >> limit[i];

	int ans = 0;
	
	set <pair<int, int> > s;

	for(int i = k; i > 0; i--) {
		
		while(!s.empty() && s.begin()->st < limit[i] && f[i]) {
			int cnt = min(f[i], limit[i] - s.begin()->st);
			f[i] -= cnt;
			auto p = *s.begin();
			s.erase(s.begin());
			s.insert({p.st + cnt, p.nd});
			for(int j = 0; j < cnt; j++)
				res[p.nd].push_back(i);
		}

		while(f[i]) {
			int cnt = min(f[i], limit[i]);
			f[i] -= cnt;
			int sz = s.size();
			s.insert({cnt, sz + 1});	
			for(int j = 0; j < cnt; j++)
				res[sz + 1].push_back(i);
		}
	}
	cout << s.size() << '\n';
	for(int i = 1; i <= s.size(); i++)
		cout << res[i] << '\n';
}