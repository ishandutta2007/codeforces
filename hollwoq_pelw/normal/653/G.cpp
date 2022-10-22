/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
        freopen(fileerr.c_str(), "w", stderr);
#endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
    FAST_IO("input.inp", "output.out", "error.err");
    auto start = chrono::steady_clock::now();
#else
    FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
#ifdef hollwo_pelw_local
    auto end = chrono::steady_clock::now();
    cout << endl;
    cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
    return 0;
}

#define int long long

const int N = 3e5 + 5, mod = 1e9 + 7;

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

inline int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

inline int sub(int a, int b) {
	return a - b < 0 ? a - b + mod : a - b;
}

int n, pr[N], fac[N], inv[N], preCn[N];

inline int C(int n, int k) {
	return mul(fac[n], mul(inv[n - k], inv[k]));
}

vector<int> p[N];

void Hollwo_Pelw() {
	for (int i = 1; i < N; i++) pr[i] = i;
	for (int i = 2; i < N; i++) {
		if (pr[i] == i)
			for (int j = 2 * i; j < N; j += i)
				pr[j] = i;
	}
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i < N; i++)
		inv[i] = mod - mul(mod / i, inv[mod % i]);
	for (int i = 2; i < N; i++)
		fac[i] = mul(fac[i - 1], i), inv[i] = mul(inv[i], inv[i - 1]);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		preCn[i] = (i == 0 ? 0 : add(preCn[i - 1], C(n - 1, i - 1)));
	
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		while (x > 1){
			int v = pr[x], c = 0;
			while (x % v == 0)
				c ++, x /= v;
			p[v].push_back(c);
		}
	}

	int ans = 0;
	for (int i = 2; i < N; i++) {
		if (p[i].empty()) continue ;
		int sz = p[i].size();
		sort(p[i].rbegin(), p[i].rend());
		for (int x = 0, y = n - 1; x < sz; x++, y--) {
			ans = add(ans, mul(sub(preCn[y], preCn[x]), p[i][x]));
		}
	}
	cout << ans;
}