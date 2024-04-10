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

const long long MOD = 1e9 + 7;

long long mobius(long long n) 
{ 
    long long p = 0; 
    // if (n%2 == 0) { 
    //     n = n/2; 
    //     p++; 
    //     if (n % 2 == 0) 
    //        return 0; 
    // } 
  
    for (long long i = 2; i * i <= n; i++)  { 
        if (n%i == 0)  { 
            n = n/i; 
            p++; 
        if (n % i == 0) 
               return 0; 
        } 
    } 
    return (p % 2 == 0)? -1 : 1; 
} 

long long powMod(long long base, long long exp) {
	if(exp == 0)return 1;
	long long tmp = powMod(base, exp / 2);
	tmp = (1LL * tmp * tmp) % MOD;
	if(exp % 2) tmp = (tmp * base) % MOD;
	return tmp;
}

map <long long, long long> f;

long long solve2(long long val) {
	// dbg(val);
	// dbg(powMod(2, val - 1) - 1);
	return powMod(2, val - 1) - 1;
}

long long solve(long long val) {
	if(f.count(val) == 0) {
		long long x = -1;
		if(val == 1) return 1;
		long long ret = powMod(2, val - 1) - 1;
		// dbg(val, ret);

		for(long long i = 2; i * i <= val; i++) {
			if(val % i != 0) continue;
			// i+t t = mobius(i);
			long long t = mobius(i);
			dbg(t, i);
			ret += t * solve2(val / i);
			ret %= MOD;
			// dbg(ret);
			if(i * i != val) {
				long long t = mobius(val / i);
				// dbg(t, val, i);
				ret += t * solve2(val/ (val / i));
				ret %= MOD;
				// dbg(t, ret);
			}
		}
		ret += MOD;
		f[val] = ret % MOD;
	} 
	return f[val];
}

int main() {
	ios_base::sync_with_stdio(false);
	long long x, y;

	// dbg(mobius(2));
	// dbg(mobius(3));
	// dbg(mobius(4));
	// dbg(mobius(5));
	// dbg(mobius(6));
	cin >> x >> y;
	if(y % x != 0) return cout << "0\n", 0;
	cout << solve(y / x);
}