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
long long n;
vector <long long> v[15];
multiset<long long> rep, to_rep;
long long s, a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}

	sort(v[0].begin(), v[0].end(), greater<long long>());
	sort(v[1].begin(), v[1].end(), greater<long long>());
	sort(v[10].begin(), v[10].end(), greater<long long>());
	sort(v[11].begin(), v[11].end(), greater<long long>());

	long long take = v[11].size();
	
	for(auto i : v[11])
		s += i;

	for(long long i = 0; i < v[0].size(); i++) {
		if(i < take) {
			s += v[0][i];
			rep.insert(v[0][i]);
		}
	}

	long long spare = max(0LL, take - (long long) v[0].size());
	take = min(v[1].size(), v[10].size());

	for(long long i = 0; i < v[1].size(); i++) {
		if(i < take)
			s += v[1][i];
		else 
			to_rep.insert(v[1][i]);
	}

	for(long long i = 0; i < v[10].size(); i++) {
		if(i < take)
			s += v[10][i];
		else 
			to_rep.insert(v[10][i]);
	}

	while(spare && to_rep.size() > 0) {
		long long b = *to_rep.rbegin();
		to_rep.erase(prev(to_rep.end()));
		s += b;
		spare--;
	}
	
	while(!to_rep.empty() && !rep.empty()) {
		dbg(a, b);
		long long a = *rep.begin();
		long long b = *to_rep.rbegin();
		if(a < b) {
			s += b - a;
			rep.erase(rep.begin());
			to_rep.erase(prev(to_rep.end()));
			rep.insert(b);
			to_rep.insert(a);
		} else break;
	}
	cout << s << '\n';
}