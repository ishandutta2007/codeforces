#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
int n;
string s, t;
vector <pair<int, int>> ans;
int lastAB = - 1, lastBA = -1;

void move(int &x, int y) {
	ans.push_back({x + 1, y + 1});
	x = -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s >> t;
	for(int i = 0; i < n; i++) {
		if(s[i] == t[i]) continue;
		if(s[i] == 'a') {
			if(lastAB == -1) lastAB = i;
			else move(lastAB, i);
		} else {
			if(lastBA == -1) lastBA = i;
			else move(lastBA, i);
		}
	}
	if(lastAB == -1 && lastBA != -1) return cout << "-1\n", 0;
	if(lastAB != -1 && lastBA == -1) return cout << "-1\n", 0;
	if(lastAB != -1 && lastBA != -1) {
		ans.push_back({lastBA + 1, lastBA + 1});
		move(lastBA, lastAB);
	}
	cout << ans;
}