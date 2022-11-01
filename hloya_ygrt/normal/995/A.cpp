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
  
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <assert.h>
#include <fstream>
#include <map>
#include <cstring>
#include <queue>
#include <iomanip>
#include <time.h>
// #Include
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out2.txt","w",stdout)
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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-15;
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

int c[4][51];

int n, k;

void nxt(int& x, int& y) {
	if (x == 1) {
		if (y == n - 1)
			x++;
		else
			y++;
	} else if (x == 2) {
		if (y == 0)
			x--;
		else
			y--;
	} else assert(0);
}

void prv(int& x, int& y) {
	if (x == 1) {
		if (y == 0)
			x++;
		else
			y--;
	} else if (x == 2) {
		if (y == n - 1)
			x--;
		else
			y++;
	} else assert(0);
}

vector<pair<int, pair<int, int> > > ans;
void mv(int x, int y, int x1, int y1) {
	c[x1][y1] = c[x][y];
	c[x][y] = 0;
	ans.pb(mp(c[x1][y1], mp(x1 + 1, y1 + 1)));
}

int main() {
	// files1;
	fast_io;
	cin >> n >> k;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}

	int x = -1, y = -1;
	if (k == 2 * n)
		for (int i = 0; i < n; i++) {
			if (c[0][i] == c[1][i]) {
				mv(1, i, 0, i);
				k--;
				x = 1, y = i;
				break;
			}
			if (c[3][i] == c[2][i]) {
				mv(2, i, 3, i);
				k--;
				x = 2, y = i;
				break;
			}
		}
	else {
		for (int i = 0; i < n; i++)
			if (c[1][i] == 0) {
				x = 1, y = i;
				break;
			} else if (c[2][i] == 0) {
				x = 2, y = i;
				break;
			}
	}
	if (x == -1) {
		cout << -1 << endl;
		return 0;
	}


	int x1 = x, y1 = y;
	prv(x1, y1);

	vector<pair<int, int> > ord;
	while (x1 != x || y1 != y) {
		if (c[x1][y1] != 0)
			ord.pb(mp(x1, y1));
		prv(x1, y1);
	}

	while (ord.size()) {
		for (int i = 0; i < ord.size();) {
			int x = ord[i].first, y = ord[i].second;
			if (x == 1) {
				if (c[0][y] == c[x][y]) {
					mv(x, y, 0, y);
					k--;
					ord.erase(ord.begin() + i);
				} else {
					int x1 = x, y1 = y;
					nxt(x1, y1);
					mv(x, y, x1, y1);
					ord[i] = mp(x1, y1);
					i++;
				}
			} else {
				if (c[3][y] == c[x][y]) {
					mv(x, y, 3, y);
					k--;
					ord.erase(ord.begin() + i);
				} else {
					int x1 = x, y1 = y;
					nxt(x1, y1);
					mv(x, y, x1, y1);
					ord[i] = mp(x1, y1);
					i++;
				}
			}
		}
		// for (int i = 0; i < 4 ;i++)
		// 	for (int j = 0; j < n; j++)
		// 		cout << c[i][j] << " \n"[j == n - 1];
		// break;
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << ' ' << ans[i].second.first << ' ' << ans[i].s.s << endl;
	}
	return 0;
}