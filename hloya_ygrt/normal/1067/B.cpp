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
const int maxn = (int)1e5 + 12, base = 1e9 + 7;
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

	int n, k;

	vector<int> g[maxn];
int d[maxn], p[maxn];
pii bfs(int v) {
	for (int i = 0; i < n; i++)
		d[i] = inf;
	d[v] = 0;
	p[v] = -1;

	queue<int > q;
	q.push(v);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int to : g[v]) {
			if (d[to] == inf) {
				d[to] = d[v] + 1;
				p[to] = v;
				q.push(to);
			}
		}
	}


	pii res = mp(-inf, 0);
	for (int i = 0; i < n; i++)
		res = max(res, mp(d[i], i));
	return mp(res.s, res.f);
}

void dfs (int v, int k, int p = -1) {
	if (p == -1) {
		if (g[v].size() < 3) {
			cout << "No\n";
			exit(0);
		}
	} else {
		if (k == 0) {
			if (g[v].size() != 1) {
				cout << "No\n";
				exit(0);
			}
		} else {
			if (g[v].size() < 4) {
				cout << "No\n";
				exit(0);
			}
		}
	}
	for (int to : g[v])
		if (to != p)
			dfs(to, k - 1, v);
}

int main() {
	// files1;
	cin >> n >> k;

	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}

	pii u = bfs(0);
	// cout << u.s << endl;
	// exit(0);
	pii z = bfs(u.f);
	int len = z.s;

	if (len != 2 * k) {
		cout << "No\n";
		return 0;
	}

	int v = z.f;
	for (int i = 0; i < k; i++) {
		v = p[v];
	}

	dfs(v, k);

	cout << "Yes\n";
	return 0;
}