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
long long n, la, lb, ra, rb, ta, tb;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;

	int sza = ra - la + 1;
	int szb = rb - lb + 1;
	long long g = __gcd(ta, tb);
	la %= g;
	lb %= g;

	if(la > lb) {
		swap(la, lb);
		swap(ra ,rb);
		swap(ta, tb);
		swap(sza, szb);
	}

	ra = la + sza - 1;
	rb = lb + szb - 1;

	long long ans1 = max(min(rb, ra) - max(la, lb) + 1, 0LL);

	la += g;
	ra += g;

	long long ans2 = max(min(rb, ra) - max(la, lb) + 1, 0LL);
	cout << max(ans1, ans2);

	// long long dif1 = (la - lb) % g;
	// long long dif2 = (lb - la) % g;
	// if(dif1 < 0) dif1 += g;
	// if(dif2 < 0) dif2 += g;
	// dbg(dif1, dif2);

	// cout << max({min(ra - (la + dif2) + 1, rb - lb), min(rb - (lb + dif1) + 1, ra - la), 0LL});

}