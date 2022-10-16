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

long long n;
vector <pair<unsigned long long, long long> > v;
long long val, ans, sum;
unsigned long long mask;

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> val >> mask;
		v.push_back({mask, val});
		sum += val;
	}

	sort(v.begin(), v.end());

	long long i = 0;
	for(unsigned long long step = 1; step <= (1LL << 62); step *= 2) {

		long long new_sum = 0;
		while(i < v.size() && ( v[i].st < step)) {
			if(__builtin_popcountll(v[i].st & ans) % 2 == 0)
				new_sum += v[i].nd;
			else 
				new_sum -= v[i].nd;
			i++;
		}
		
		if(new_sum == 0)
			continue;

		if(sum > 0 && new_sum > 0 || sum < 0 && new_sum < 0)
			ans += step / 2;
	}
	cout << ans << '\n';

}