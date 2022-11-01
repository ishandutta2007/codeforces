// hloya template v20

// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

//clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
#define ld long double
#define pii pair<int,int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("moocast.out","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}

template<typename T>
string bin(T x, int st = 2){
	string ans = "";
	while (x > 0){
		ans += char('0' + x % st);
		x /= st;
	}
	reverse(ans.begin(), ans.end());
	return ans.empty() ? "0" : ans;
}

template<typename T>
T input(){
	T ans = 0, m = 1;
	char c = ' ';

	while (!((c >= '0' && c <= '9') || c == '-')) {
		c = getchar();
	}

	if (c == '-')
		m = -1, c = getchar();
	while (c >= '0' && c <= '9'){
		ans = ans * 10 + (c - '0'), c = getchar();
	}
	return ans * m;
}

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 1e3 + 44, base = 1e9 + 7;
const ll llinf = 4e18 + 5;

template<typename T>
T binpow(T n, T s)
{
	if (s <= 0)
		return 1LL;
	if (s % 2 == 0){
		T b = binpow(n, s / 2);
		return ( 1LL * b * b ) % base;
	} else {
		return (1LL* binpow(n, s - 1) * n) % base;
	}
}

struct event {
	int type, Time;
	pair<int, int> param;

	event(){}
	event(int type, int Time, pii param):type(type), Time(Time), param(param) {}

	bool operator < (const event & T) const {
		return Time < T.Time || (Time == T.Time && type < T.type) ||
			   (Time == T.Time && type == T.type && param < T.param);
	}
};

set<event> E;
#define free Free

set<int> free;

int main() {
	int n, q;
	read(n, q);

	for (int i = 1; i <= n; i++)
		free.insert(i);
	for (int i = 0; i < q; i++) {
		int t, k, d;
		read(t, k, d);
		E.insert(event(1, t, mp(k, d)));
	}

	event T;
	while (!E.empty()) {
		T = *E.begin();
		E.erase(E.begin());

		if (T.type == 0) {
			free.insert(T.param.f);
		} else {
			int needCnt = T.param.f, needTime = T.param.s;
			// cout << needCnt << ' ' << needTime << endl;
			// cout << free.size() << endl;
			
			if (free.size() >= needCnt) {
				ll sum = 0;
				for (int i = 0; i < needCnt; i++) {
					sum += *free.begin();
					E.insert(event(0, T.Time + needTime, mp(*free.begin(), 0)));
					free.erase(free.begin());
				}
				printf("%lld\n", sum);
			} else { 
				puts("-1");
			}
		}
	}
	return 0;
}