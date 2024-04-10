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

const int N = 400100;
int n, p[N], t;

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	int g = 1;
	p[n + 1] = -1;
	while(p[1] == p[g + 1] && g < n) g++;
	int s = g + 1;
	if(s + g > n / 2){
		cout << "0 0 0\n";
		return;
	}
	while(p[g + s] == p[g + s + 1] && g + s < n) s++;
	int b = -1;
	for(int i = g + g + 1 + s; i <= n / 2; i++ )
		if(p[i] != p[i + 1])
			b = i - g - s;
	
	if(b + s + g > n / 2){
		cout << "0 0 0\n";
		return;
	}
	if(b == -1) g = s = b = 0;
	cout << g << ' ' << s << ' ' <<  b << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--) {
		solve();
	}
}