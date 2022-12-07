
//Karol Kaszuba

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef double D;
typedef long double LD;
typedef vector<PII> VII;
typedef unordered_set<int> USI;
typedef unordered_set<LL> USLL;

#define FOR(i,x,y) for(auto i=(x);i<=(y);++i)
#define REP(i,x) FOR(i,0,(x)-1)
#define FORD(i,x,y) for(auto i=(x);i>=(y);--i)
#define VAR(i,c) __typeof(c) i=(c)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SIZE(c) (int)((c).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define MP make_pair
#define ST first
#define ND second
#define IOSYNC ios_base::sync_with_stdio(0)
#define FREOPEN(f) freopen(f, "r", stdin),freopen(f, "w", stdout)

const int k = 2;

VI vvvv;

int czek(VI v, VI w) {
	
	int n = SIZE(v) - 1, m = SIZE(w) - 1;
	REP(iterations, 151) {
		while (n >= 0 && v[n] == 0) n--;
		while (m >= 0 && w[m] == 0) m--;
		if (n < 0 || m < 0) return iterations;
		if (n < m) {
			swap(n, m);
			swap(v, w);
		}
		
		if (m != n - 1) return -1;
		//cerr << n << " " << m << "\n";
		//FOR(i, 0, n) cerr << v[i] << " "; cerr << "\n";
		//FOR(i, 0, m) cerr << w[i] << " "; cerr << "\n";
		
		int a = v[n], b = w[m];
		FORD(i, n, 0) {
			if (i - n + m >= 0) {
				v[i] = v[i] * b - a * w[i - n + m];
			}
			else {
				v[i] = v[i] * b;
			}
			v[i] = ((v[i] % k) + k) % k;
			if (v[i] == 2) v[i] = -1;
		}
		if (v[m] != 0) {
			a = v[m], b = w[m];
			FORD(i, m, 0) 
			{
				v[i] = v[i] * b - a * w[i];
				v[i] = ((v[i] %k) + k) % k;
				if (v[i] == 2) v[i] = -1;
			}
		}
	}
	return -1;
}

void bek(VI& v, VI& w) {
	int n = SIZE(v) - 1, m = SIZE(w) - 1;
	REP(i, n + 1) cerr << (v[i] + 3) % 3 << " "; cerr << "\n";
	REP(iterations, 151) {
		while (n >= 0 && v[n] == 0) n--;
		while (m >= 0 && w[m] == 0) m--;
		if (n < 0 || m < 0) return;
		if (n < m) {
			swap(n, m);
			swap(v, w);
		}
		
		if (m != n - 1) return;
		//cerr << n << " " << m << "\n";
		//FOR(i, 0, n) cerr << v[i] << " "; cerr << "\n";
		if (w[m] == -1) FOR(i, 0, m) w[i] = -w[i];
		FOR(i, 0, m) cerr << (w[i] + k) % k << " "; cerr << "\n";
		
		int a = v[n], b = w[m];
		FORD(i, n, 0) {
			if (i - n + m >= 0) {
				v[i] = v[i] * b - a * w[i - n + m];
			}
			else {
				v[i] = v[i] * b;
			}
			v[i] = ((v[i] % k) + k) % k;
			if (v[i] == 2) v[i] = -1;
		}
		if (v[m] != 0) {
			a = v[m], b = w[m];
			FORD(i, m, 0) 
			{
				v[i] = v[i] * b - a * w[i];
				v[i] = ((v[i] % k) + k) % k;
				if (v[i] == 2) v[i] = -1;
			}
		}
	}
}

void backtrack(VI& v, int pos, int myk, int m) {
	if (pos < (m + 1) / 2) {
		if (czek(vvvv, v) == m + 1) {
			int n = SIZE(v) - 1, m = n - 1;
			cout << n << "\n";
			REP(i, n) cout << 0 << " "; cout << "1 \n";
			cout << m << "\n";
			REP(i, m + 1) cout << v[i] << " "; cout << "\n";
			
			//bek(vvvv, v);
			
			exit(0);
		}
		return;
	}
	
	v[pos] = 1;
	backtrack(v, pos - myk, (myk == 0 ? 1 : 2 * myk), m);
	v[pos] = 0;
	backtrack(v, pos - 1, myk + 1, m);
	
}

void jebaj() {
	srand(13337);
	int n;
	cin >> n;
	int m = n - 1;
	VI v(n + 1), w(n + 1);
	v[n] = w[m] = 1;
	vvvv = v;
	
	
	w[0] = 1;
	backtrack(w, m - 1, 0, m);
	

}

int main() {
	IOSYNC;
	int t;
	t = 1;
	while(t--) jebaj();
	return 0;
}