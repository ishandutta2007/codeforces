// hloya template v25
  
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
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
  
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
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
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

ll gcd (ll a, ll b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)5e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
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

bool isd = 0;

string ask(int x, int y) {
	if (isd) {
		return rand() % 2 ? "black" : "white";
	}

	cout << x << ' ' << y << endl;
	cout.flush();
	string s;
	cin >> s;
	return s;
}

void solve(int n) {
	int l = 1, r = (int)1e9;

	string s = ask(0, 1);

	int on_left = 0, on_right = 1;
	if (s == "black")
		swap(on_left, on_right);

	vector<int> kek[2];
	kek[0].pb(0);

	for (int i = 1; i < n; i++) {
		assert(l <= r);
		int m = (l + r) >> 1;
		string s = ask(m, 1);

		int cur = on_left;
		if (s == "black")
			cur ^= 1;
		kek[cur].pb(m);

		if (!cur)
			l = m + 1;
		else
			r = m - 1;
	}

	sort(all(kek[0]));
	sort(all(kek[1]));

	if (kek[0].empty() || kek[1].empty()) {
		cout << "0 2 1 2\n";
		cout.flush();
		exit(0);
	}
	cout << kek[0].back() << ' ' << 2 << ' ' << kek[1].front() << ' ' << 0 << endl;
	cout.flush();
}

int main() {
	int n;
	cin >> n;
	srand(time(0));

	solve(n);
	return 0;
}