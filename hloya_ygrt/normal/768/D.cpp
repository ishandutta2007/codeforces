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

ld dp[7305][1001];

void calc(int k) {
	dp[0][0] = 1;
	for (int day = 0; day <= 7300; day++)
		for (int cnt = 0; cnt <= k; cnt++) {
			dp[day + 1][cnt] += dp[day][cnt] * (ld)cnt / (ld)k;
			if (cnt != k) {
				dp[day + 1][cnt + 1] += dp[day][cnt] * (ld)(k - cnt) / (ld)k;
			}
		}
}

int main() {
	// cout << (600 ^ 1000);
	// int ans = 0, ans1, ans2;
	// for (int i = 0; i <= 1000; i++)
	// 	for (int j = 0; j <= 1000; j++) {
	// 		if ((i ^ j) > ans) {
	// 			ans = i ^ j;
	// 			ans1 = i;
	// 			ans2 = j;
	// 		}
	// 	}
	// 	// cout << ans1 << ' ' << ans2;
	// 	cout << (23 ^ 1000);
	int k, q;
	//files1;
	cin >> k >> q;
	calc(k);
	// return 0;
	for (int i = 0; i < q; i++) {
		int p;
		cin >> p;
		// cout << solve(k, p);
		for (int x = 1;; x++) {
			// cout << fixed << setprecision(6) << dp[x][k] << ' ';
			if (dp[x][k] >= (ld)p / (ld)2000) {
				cout << x << endl;
				break;
			}
		}
	}
	return 0;
}