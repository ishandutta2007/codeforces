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
const int maxn = (int)2e6 + 12, base = 1e9 + 7;
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

bool us[maxn];
int a[maxn], b[maxn], l[maxn], r[maxn];

int main() {
	fast_io;
	// files1;
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> l[i];
	for (int i = 0; i < n; i++) cin >> r[i];

	int cur_it = n;
	while (1) {
		int cnt_not_used = 0;
		int cnt_max = 0;

		for (int i = 0; i < n; i++) {
			b[i] = 0;
			if (!us[i]) {
				cnt_not_used += 1;
				if (l[i] == 0 && r[i] == 0) {
					cnt_max += 1;
					b[i] = 1;
					a[i] = cur_it;
					us[i] = true;
				}
			}
		}

		int pr = 0;
		for (int i = 0; i < n; i++) {
			pr += b[i];
			l[i] -= pr;
		}

		pr = 0;
		for (int i = n - 1; i >= 0; i--) {
			pr += b[i];
			r[i] -= pr;
		}

		if (cnt_not_used == 0) {
			break;
		}
		if (cnt_max == 0) {
			cout << "NO\n";
			return 0;
		}

		cur_it--;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << "\n";
	return 0;
}