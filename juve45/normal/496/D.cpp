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

const int N = 100100;
int n, a[N], s[3][N];
vector <pair<int, int> > ans;


int binsch(int l, int r, int * v, int lim) {
	while(l != r) {
		int mid = (l + r) / 2;
		if(v[mid] >= lim) r = mid;
		else l = mid + 1;
	}
	return l;
}

int solve(int val) {	
	int n1 = 0;
	int n2 = 0;
	
	vector <int> v;

	for(int start = 1; start <= n;) {
		int fin1 = binsch(start, n + 1, s[1], s[1][start - 1] + val);
		int fin2 = binsch(start, n + 1, s[2], s[2][start - 1] + val);
		
		if(fin1 == fin2) return -1;

		int fin = min(fin1, fin2);
		if(fin == fin1) v.push_back(1);
		else v.push_back(2);

		start = fin + 1;
	}

	int f[] = {0, 0, 0};
	for(auto i : v)
		f[i]++;
	if(f[v.back()] <= f[3 - v.back()]) 
		return -1;
	return f[v.back()];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[1][i] += s[1][i - 1];
		s[2][i] += s[2][i - 1];
		s[a[i]][i]++;
	}

	s[1][n + 1] = s[2][n + 1] = 1e9;

	// ans.push_back({});
	for(int i = 1; i <= n; i++) {
		int x = solve(i);
		if(x >= 0)
			ans.push_back({x, i});
	}
	sort(ans.begin(), ans.end());
	cout << ans;
}