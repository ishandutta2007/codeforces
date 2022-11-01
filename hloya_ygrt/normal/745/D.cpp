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

#define files1 freopen("moocast.in","r",stdin)
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

void reads(string & s) {
	string ans = "";
	char c = endl;
	while (c == endl || c == ' ')
		c = getchar();
	while (c != endl && c != ' ' && c)
		ans += c, c = getchar();
	s = ans;
}

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

int ans[maxn];
int used1[maxn], used2[maxn];

int main() {
	int n;
	cin >> n;
	// n = 3;

	// ofstream crr("output.txt");

	vector<pair<int, pair<int, int> > > old, newQ;

	vector<int> to_ask1, to_ask2;

	int realN = n;
	while (n & (n - 1))
		n++;

	old.pb(mp(1, mp(1, n)));
	memset(ans, 63, sizeof(ans));

	while (!old.empty()) {
		to_ask1.clear();
		to_ask2.clear();

		memset(used1, 0, sizeof(used1));
		memset(used2, 0, sizeof(used2));

		// cout << newQ.size() << endl;
		for (auto mda:old) {
			int x = mda.f, y = mda.s.f, len = mda.s.s;
			if (len == 1)
				continue;
			int tm = (x + x + len - 1) / 2;
			for (int i = x; i <= tm; i++) {
				to_ask1.pb(i);
				used1[i] = 1;
			}
			for (int i = tm + 1; i <= x + len - 1; i++) {
				to_ask2.pb(i);
				used2[i] = 1;
			}

			newQ.pb(mp(x, mp(y, len / 2)));
			newQ.pb(mp(x + len / 2, mp(y + len / 2, len / 2)));
		}
		// cout << newQ.size() << endl;
		// return 0;
		old = newQ;
		newQ.clear();

		while (!to_ask1.empty() && to_ask1.back() > realN)
			to_ask1.pop_back();
		if (!to_ask1.empty()) {
			cout << to_ask1.size() << endl;
			for (int i:to_ask1)
				cout << i << ' ';
			cout << endl;
			cout.flush();

			for (int i = 1; i <= realN; i++) {
				int x;
				scanf("%d", &x);
				if (!used1[i])
					ans[i] = min(ans[i], x);
			}
		}

		while (!to_ask2.empty() && to_ask2.back() > realN)
			to_ask2.pop_back();

		if (!to_ask2.empty()) {
			cout << to_ask2.size() << endl;
			for (int i:to_ask2)
				cout << i << ' ';
			cout << endl;
			cout.flush();

			for (int i = 1; i <= realN; i++) {
				int x;
				scanf("%d", &x);
				if (!used2[i])
					ans[i] = min(ans[i], x);
			}
		}				
	}
	cout << -1 << endl;
	for (int i = 1; i <= realN; i++)
		cout << ans[i] << ' ';
	return 0;
}