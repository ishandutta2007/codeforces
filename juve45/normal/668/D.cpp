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

const int N = 100100;
const int MAXX = 1.01e9;
int n, a, t, x;

map <int, int> aib[N], mp;

int lsb(int k) { return k & (-k); }

int que(map<int, int> &aib, int pos) {
	int ret = 0;
	for(; pos ; pos -= lsb(pos)) {
		// dbg(pos, aib[pos]);
		ret += aib[pos];
	}
	return ret;
}

int upd(map <int, int> &aib, int pos, int val) {
	for(; pos < MAXX; pos += lsb(pos)) {
		// dbg(pos, val);
		aib[pos] += val;
	}
}

int get(int x) {
	if(!mp.count(x)) {
		int k = mp.size();
		mp[x] = k + 1;
	}
	return mp[x];
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a >> t >> x;
		x = get(x)
		;
		// dbg(x);
		if(a == 1)
			upd(aib[x], t, 1);
		else if(a == 2)
			upd(aib[x], t, -1);
		else 
			cout << que(aib[x], t) << '\n';

	}
}