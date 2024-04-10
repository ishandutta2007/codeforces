// hloya template v24

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

clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out1.txt","w",stdout)
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

const int inf = 2e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 2e5 + 12, base = 1e9 + 7;
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

int inv(int x) {
	return binpow(x, base - 2);
}

int fact[maxn];
int c(int n, int k) {
	if (n < 0 || k < 0 || k > n) return 0;
	return 1ll * fact[n] * inv(1ll * fact[k] * fact[n - k] % base) % base;
}

int F(int x, int c) {
	x -= c;
	if (x < 0) return 0;
	return ::c(x + c - 1, c - 1);
}

void add(int& x, int y) {
	x += y;
	if (x >= base)
		x -= base;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < maxn; i++)
		fact[i] = 1ll * fact[i - 1] * i % base;

	int f, w, h;
	// files1;
	cin >> f >> w >> h;
	if (w == 0) {
		cout << 1;
		return 0;
	}
	if (h == 0) {
		cout << 1;
		return 0;
	}

	int ans = 0;
	for (int k = 1; w - k * h > 0; k++) {
		int cur_res = F(w - k * h, k);
		int cur_sum2 = F(f, k + 1);
		add(cur_sum2, F(f, k));
		add(cur_sum2, F(f, k));
		add(cur_sum2, F(f, k - 1));

		ans += 1ll * cur_res * cur_sum2 % base;
		if (ans >= base)
			ans -= base;
	}
	ans = 1ll * ans * inv(c(f + w, f)) % base;
	cout << ans;
	return 0;
}