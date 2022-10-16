#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd ; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
int n;

bool isPrime(int n) {
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}


bool solve(int n) {

	int add = 0;
	while(!isPrime(n + add)) add++;
	if(2 * add > n) return 0;

	vector <pair<int, int> > edges;
	edges.push_back({1, n});
	for(int i = 1; i < n; i++)
		edges.push_back({i, i + 1});
	for(int i = 1; i <= add; i++) {
		assert(i + 1 != n - i);
		edges.push_back({i, n - i});
	}
	cout << edges << '\n';
	return 1;
}	

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	solve(n);
	// for(int i = 3; i <= 1000; i++)
	// 	if(!solve(i))  {
	// 		dbg(i);
	// 		return 0;
	// 	}


}