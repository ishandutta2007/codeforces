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

int main() {
	ll n;
	ll l, r;
	//files1;
	cin >> n >> l >> r;
	ll ans = 0;
	// cout << bin(10) << endl;
	int cntBits = 0;
	ll x = n;
	while (x > 1) {
		cntBits++;
		x /= 2;
	}

	for (int j = 0; j < 50; j++) {
		int i = cntBits - j;
		if (n & (1ll << i)) {
			// cout << i << endl;
			ll ls = l - (1ll << j);
			ll rs = r - (1ll << j);
			// cout << ls << ' ' << rs << ' ' << i << endl;
			if (rs < 0) continue;
			amax(ls, 0ll);
			// if (ls < )
			// amax(ls, 0ll
			ll sh = 1ll << (j + 1);
			ll mn_x = (ls + sh - 1) / sh;
			ll mx_x = rs / sh;
			// cout << rs << endl;
			// amax(mn_x, 1ll);
			// amin
			// cout << ls << endl;
			// cout << sh << endl;
			// cout << mn_x << ' ' << mx_x << endl;
			ans += max(0ll, mx_x - mn_x + 1);
		}
	}
	cout << ans;
	return 0;
}