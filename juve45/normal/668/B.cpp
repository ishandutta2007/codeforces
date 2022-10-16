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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const long long N = ;
long long n, q, op, x;
long long sum;
vector <long long> ops;

void shift(vector <long long> &v, long long pas) {
	vector <long long> ret;
	ret.resize(v.size());
	long long n = ret.size();
	pas %= n;
	// dbg(pas);

	for(long long i = 0; i < v.size(); i++)
		ret[(n + i + pas) % n] = v[i];
	v = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q;

	// vector <long long> g = {5, 6, 3, 7, 8};
	// shift(g, -2);
	// dbg(g);

	vector <long long> v;
	for(long long i = 1; i <= n; i++) 
		v.push_back(i);


	for(long long i = 1; i <= q; i++) {
		cin >> op;
		if(op == 2) {
			long long to = abs(sum) % 2;
			if(!ops.empty() && ops.back() == to)
				ops.pop_back();
			else ops.push_back(to); 
		} else {
			cin >> x;
			sum += x;
		}
	}

	if(ops.size() != 0) {
		long long pas = ops.size() % n;
		if(ops[0] == 1) pas *= -1;

		vector <long long> ret;
		ret.resize(n);
		for(long long i = 0; i < n; i++)
			if(i % 2 == 0)
				ret[(n + i + pas) % n] = v[i];
			else
				ret[(n + i - pas) % n] = v[i];
		v = ret;
	}
	sum %= n;
	// dbg(v);
	shift(v, sum);
	for(auto i : v) assert(1 <= i && i <= n);
	for(auto i : v) cout << i << ' ';
	cout << '\n';
}