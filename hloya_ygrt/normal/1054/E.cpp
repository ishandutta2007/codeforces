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
#define eb emplace_back
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

deque<char> q[301][301];

vector<tuple<int, int, int, int> > res;

void move(int x1, int y1, int x2, int y2) {
	res.eb(x1 + 1, y1 + 1, x2 + 1, y2 + 1);
	// cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
	q[x2][y2].push_front(q[x1][y1].back());
	q[x1][y1].pop_back();
}

int has[301][301];
string dest[301][301];

int main() {
	// files1;
	fast_io;
	int n, m;
	cin >> n >> m;

	res.reserve(maxn);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string s;
			cin >> s;
			for (char c : s)
				q[i][j].push_back(c);
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> dest[i][j];

	for (int i = 1; i < n; i++) {
		while (!q[i][0].empty())
			move(i, 0, 0, 0);
	}
	for (int j = 1; j < m; j++) {
		while (!q[0][j].empty())
			move(0, j, 0, 0);
	}


	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			while (!q[i][j].empty()) {
				char c = q[i][j].back();
				if (c == '0') {
					has[i][0] += 1;
					move(i, j, i, 0);
				}
				else {
					has[0][j] += 1;
					move(i, j, 0, j);
				}
			}
		}

	while (!q[0][0].empty()) {
		char c = q[0][0].back();
		if (c == '0') {
			has[1][0] += 1;
			move(0, 0, 1, 0);
		}
		else {
			has[0][1] += 1;
			move(0, 0, 0, 1);
		}
	}

	int fi = n - 1, fj = m - 1;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			for (int k = (int)dest[i][j].size() - 1; k >= 0; k--) {
				if (dest[i][j][k] == '0') {
					while (fi > 0 && has[fi][0] == 0)
						fi--;
					has[fi][0]--;
					assert(fi > 0);

					if (fi != i) {
						move(fi, 0, i, 0);
					}
					move(i, 0, i, j);
				} else {
					while (fj > 0 && has[0][fj] == 0)
						fj--;
					has[0][fj]--;
					assert(fj > 0);
					if (fj != j) {
						move(0, fj, 0, j);
					}
					move(0, j, i, j);
				}
			}
		}
	// cout << "----\n";
	for (int i = n - 1; i >= 1; i--) {
		int j = 0;
		for (int k = (int)dest[i][j].size() - 1; k >= 0; k--) {
			if (dest[i][j][k] == '0') {
				while (fi > 0 && has[fi][0] == 0)
					fi--;
				assert(fi > 0);
				has[fi][0]--;

				if (fi == i) {
					move(fi, 0, 0, 0);
					move(0, 0, i, 0);
				} else {
					move(fi, 0, i, 0);
				}
			} else {
				while (fj > 0 && has[0][fj] == 0)
					fj--;
				assert(fj > 0);
				has[0][fj]--;

				move(0, fj, 0, 0);
				move(0, 0, i, 0);
			}
		}
	}

	for (int j = m - 1; j >= 1; j--) {
		int i = 0;
		for (int k = (int)dest[i][j].size() - 1; k >= 0; k--) {
			if (dest[i][j][k] == '0') {
				while (fi > 0 && has[fi][0] == 0)
					fi--;
				assert(fi > 0);
				has[fi][0]--;

				move(fi, 0, 0, 0);
				move(0, 0, 0, j);
			} else {
				while (fj > 0 && has[0][fj] == 0)
					fj--;
				assert(fj > 0);
				has[0][fj]--;

				if (fj == j) {
					move(0, fj, 0, 0);
					move(0, 0, 0, j);
				} else {
					move(0, fj, 0, j);
				}
			}
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		// for (char k : q[i][j])
	// 		// 	cout << k;
	// 		// cout << ' ';
	// 		// cout << has[i][j] << ' ';
	// 		// cout << q[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// return 0;

	// cout << fi << ' ' << fj << endl;
	// return 0;

	for (int k = (int)dest[0][0].size() - 1; k >= 0; k--) {
		// cout << dest[0][0][k] << 'b' << endl;;
		if (dest[0][0][k] == '0') {
			while (fi > 0 && has[fi][0] == 0)
				fi--;
			assert(fi > 0);
			has[fi][0]--;

			move(fi, 0, 0, 0);
		} else {
			while (fj > 0 && has[0][fj] == 0)
				fj--;
			assert(fj > 0);
			has[0][fj]--;

			move(0, fj, 0, 0);
		}
	}

	cout << res.size() << "\n";
	for (auto e : res) {
		int a, b, c, d;
		tie(a, b, c, d) = e;
		cout << a << ' ' << b << ' ' << c << ' ' << d << "\n";
	}
	return 0;
}