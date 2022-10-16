#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;


const unsigned long long N = 1e8 + 4;
unsigned long long n, k, a, b, c, d, ans;

bitset<N> isPrime;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

unsigned long long eval(unsigned long long k) {
	return a * k * k * k + b * k * k + c * k + d;
}

int main() {
	ios_base::sync_with_stdio(false);
	// dbg(ans);
	// sieve();
	cin >> n;
	cin >> a >> b >> c >> d;
	isPrime.set();
	
	// n++;
	for (unsigned long long i = 5, t = 2; i <= n; i += t, t = 6 - t) {
    if (isPrime [i/3]) {
      for (unsigned long long j = i * i, v = t; j <= n; j += v * i, v = 6 - v)
        isPrime [j/3] = false; 
			unsigned long long nr = i;
			unsigned long long cnt = 0;
			while((long long) nr <= n) {
				cnt += (unsigned long long)((long long)n / nr);
				nr *= (long long) i;
			}
			ans += cnt * eval(i);
    }
	}

	for(unsigned long long i = 2; i <= 3; i++) {
		unsigned long long nr = i;
		unsigned long long cnt = 0;
		while((long long)nr <= n) {
			cnt += (unsigned long long)((long long)n / nr);
			nr *= i;
		}
		ans += cnt * eval(i);
	}

	cout << (unsigned int) ans << '\n';
}