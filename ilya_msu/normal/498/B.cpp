#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;



void solve() {
	int n, T;
	cin >> n >> T;
	vector<int> p(n), t(n);
	vector<double> pr(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i] >> t[i];
		pr[i] = 0.01 * p[i];
	}
	vector<double> res(T + 1, 0);
	res[0] = 1;
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		//cerr << i << endl;
		vector<double> res2(T + 1, 0);
		double cur = 0;
		double qt = 1;
		double qpt = pr[i];
		double sum = 0;
		for (int j = 0; j < T + 1; ++j) {
			//cerr << i << " " << j << endl;
			ans += cur + sum * qt;
			res2[j] = cur + sum * qt;
			cur = cur * (1 - pr[i]);
			cur += pr[i] * res[j];
			//cerr << "!" << endl;
			if (j < t[i] - 1)
				qt *= (1 - pr[i]);
			if (j < t[i] - 1)
				qpt *= (1 - pr[i]);
			//cerr << "!" << endl;
			if (j + 1 >= t[i]) {
				//cerr << "!" << endl;
				cur -= qpt * res[j - t[i] + 1];
				//cur -= qt * (1 - pr[i]) * sum;
				sum = res[j - t[i] + 1];
				//cur += sum * qt;
			}
		}
		//cerr << "!" << endl;
		for (int j = 0; j < res.size(); ++j)
			res[j] = res2[j];
	}
	printf("%0.17lf\n", ans);
	
}



//#define LOCAL

int main() {
	ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();
	/*cout << 5000 << " " << 5000 << endl;
	for (int i = 0; i < 5000; ++i) {
		cout << 6 << " " << 4657 << endl;
	}*/
	


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}