#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
const ll LLINF = (ll)8 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int N = 100 * 1000 + 1;
const ll MOD = 1000 * 1000 * 1000 + 7;


vector<double> logFact(N);
vector<vector<double> > c(601, vector<double>(601, 0));

void init() {
	c[0][0] = 1;
	for (int i = 1; i < c.size(); ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	logFact[0] = 0;
	for (int i = 1; i < N; ++i)
		logFact[i] = logFact[i - 1] + log(1.0 * i);
}

void solve() {
	init();
	int n, m, k;
	cin >> n >> m >> k;
	vector<double> logPr(k + 1), Pr(k + 1);
	Pr[0] = 1;
	for (int i = 1; i <= k; ++i) {
		Pr[i] = Pr[i - 1] * (k - i + 1) / (m - i + 1);
	}
	for (int i = 0; i < logPr.size(); ++i) {
		logPr[i] = logFact[m - i] + logFact[k] - logFact[m] - logFact[k - i];
	}
	vector<vector<double> > p(n + 1, vector<double> (n + 1));
	vector<double> FinP(2 * n + 1, 0);

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (n * i + n * j - i * j <= k) {
				//p[i][j] = 2 * logFact[n] - logFact[i] - logFact[j] - logFact[n - i] - logFact[n - j] + logPr[n * i + n * j - i * j];
				//FinP[i + j] += exp(logPr[n * i + n * j - i * j]) * c[n][i] * c[n][j];
				FinP[i + j] += Pr[n * i + n * j - i * j] * c[n][i] * c[n][j];

			}
		}
	}
	/*double res = pow(2.0, 2 * n) * FinP[2 * n];
	for (int s = 2 * n - 1; s >= 0; --s) {
		for (int i = s + 1; i <= 2 * n; ++i)
			FinP[s] -= FinP[i] * c[i][s];
		if (res > 1e99) {
			cout << 1e99 << endl;
			return;
		}
		cerr << s << endl;
		res += pow(2.0, s) * FinP[s];
	}*/
	double res = 0;
	for (int i = 0; i <= 2 * n; ++i)
		res += FinP[i];
	if (res > 1e99)
		cout << 1e99 << endl;
	else
		printf("%0.18f\n", res);	
}


//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	solve();
	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}