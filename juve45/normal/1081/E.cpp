#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 400100;
long long n, x[N];
set <long long> s;
vector <long long> ans;

int main() {
	ios_base::sync_with_stdio(false);

	for(long long i = 1; i < N; i++)
		s.insert(i * i);

	cin >> n;
	long long last = 0;
	for(long long i = 1; i <= n; i += 2) {
		// dbg(i, last); 
		cin >> x[i + 1];
		last++;
		while(!s.count(last * last + x[i + 1]) && last < N) last++;

		// dbg(last);
		if(last >= N) return cout << "No\n", 0;

		ans.push_back(last * last - x[i - 1]);
		ans.push_back(x[i + 1]);
		last = sqrt(last * last + x[i + 1] + 0.1);
		x[i + 1] = last * last;
	}
	cout << "Yes\n" << ans << '\n';
}