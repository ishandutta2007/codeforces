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
int n, f[N], fp[N], val, m;
char op;
vector <int> d[N];

string add(int val) {
	if(f[val])
		return "Already on\n";
	// dbg(val);
	// dbg(d[val]);
	// if(val == 16) dbg(fp[2]);
	for(auto div : d[val]) {
		if(fp[div])
			return "Conflict with " + to_string(fp[div]) + "\n";
	}
	// dbg(val);
	for(auto div : d[val])
		fp[div] = val;
	f[val] = 1;
	// if(val == 4) dbg(fp[2]); 
	return "Success\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;


	for(int i = 2; i <= n; i++) {
		if(d[i].size() == 0) {
			d[i].push_back(i);
			for(int j = 2 * i; j <= n; j += i)
				d[j].push_back(i);
		}
	}

	for(int i = 1; i <= m; i++) {
		cin >> op >> val;
		if(op == '-') {
			if(f[val] == 0) cout << "Already off\n";
			else  {
				cout << "Success\n";
				f[val] = 0;
				for(auto div : d[val])
					fp[div] = 0;
			}
		} else 
			cout << add(val);
	}
}