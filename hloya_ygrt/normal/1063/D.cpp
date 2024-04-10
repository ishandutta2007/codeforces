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
const int maxn = (int)2e3 + 12, base = 1e9 + 7;
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

ll gcd (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}

void shift_solution (ll & x, ll & y, ll a, ll b, ll cnt) {
	x += cnt * b;
	y -= cnt * a;
}

ll be = -1;
 
void find_all_solutions (ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy, ll add) {
	ll x, y, g;
	if (! find_any_solution (a, b, c, x, y, g))
		return;
	a /= g;  b /= g;

	ll sign_a = a>0 ? +1 : -1;
	ll sign_b = b>0 ? +1 : -1;

	shift_solution (x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution (x, y, a, b, sign_b);
	if (x > maxx)
		return;
	ll lx1 = x;
 
	shift_solution (x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution (x, y, a, b, -sign_b);
	ll rx1 = x;

 
	shift_solution (x, y, a, b, - (miny - y) / a);
	if (y < miny)
		shift_solution (x, y, a, b, -sign_a);
	if (y > maxy)
		return;

	ll lx2 = x;
 
	shift_solution (x, y, a, b, - (maxy - y) / a);
	if (y > maxy)
		shift_solution (x, y, a, b, sign_a);
	ll rx2 = x;
	if (lx2 > rx2)
		swap (lx2, rx2);
	ll lx = max (lx1, lx2);
	ll rx = min (rx1, rx2);

	if (lx > rx)
		return;

	// cerr << b << endl;
	ll ly = (c - a * lx) / b; // check a , b, c
	ll ry = (c - a * rx) / b;

	if (lx + ly + add > be) be = lx + ly + add;
	if (rx + ry + add > be) be = rx + ry + add;
 
	return;
}

ll dist(ll l, ll r, ll n) {
	if (l <= r) return r - l + 1;
	return r - l + 1 + n;
}

int main() {
	// files1;
	fast_io;

	ll n, l, r, k;
	cin >> n >> l >> r >> k;

	ll d = dist(l, r, n);
	if (n <= 10000) {
		int be = -1;
		int N = n;
		int D = d;
		for (int a = 0; a <= D; a++)
			for (int b = 0; b <= N - D; b++) {
				if (k < a + D) break;
				if ((k - a - D) % (a + b + N) == 0) {
					if (be < a + b) be = a + b;
				}
			}
		for (int a = 0; a < D; a++)
			for (int b = 0; b <= N - D; b++) {
				if (k < a + D) break;
				if ((k - a - D) % (a + 1 + b + N) == 0) {					
					if (be < (a + b + 1)) be = a + b + 1;
				}
			}
		cout << be << "\n";
		return 0;
	}



	if (d <= k && 2 * d >= k) {
		ll a = min(d, k - d + 1);
		be = a + n - d;
	}

	// cout << d << endl;

	ll lmin = max(1ll, k / (2 * n) - 5);
	ll lmax = k / n + 5;

	// cout << lmin << ' ' << lmax << endl;

	for (ll l = lmin; l <= lmax; l++) {
		ll c = k - d - l * n;
		if (c < 0) break;
		find_all_solutions(l + 1, l, c, 0, d, 0, n - d, 0);

		c -= l;
		if (c >= 0) {
			find_all_solutions(l + 1, l, c, 0, d - 1, 0, n - d, 1);
		}
	}

	

	cout << be << endl;
	return 0;
}