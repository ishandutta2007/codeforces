//#pragma comment(linker, "/STACK:206777216")

#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <ctime>
#include <complex>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;
typedef long double ld;
#define NAME "change me please\n"

//int timer=0;

clock_t start;

int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	//cout<<NAME<<endl;
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);
	int t = 1;
	//cin>>t;
#ifdef _DEBUG
	start = clock();
#endif
	while (t--)
		solve();
		
#ifdef _DEBUG
	printf ("\n\ntime = %.10lf\n", (double)(clock()-start)/CLOCKS_PER_SEC);
#endif
	return 0;
}

#define int li

int n, m, k;

int mod = 1000000007;

int dp1[111][111 * 111];
int dp2[111][111 * 111];

int c[111][111];

int step1[111][111];

int step2[111][111];

int pow (int q, int w){
	if (!w)
		return 1;
	if (w % 2)
		return (q * pow(q, w - 1)) % mod;
	return pow( (q * q) % mod, w / 2 );
}

void solve(){
	cin>>n>>m>>k;
	for (int i = 0; i < 111; ++i){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			c[i][j] %= mod;
		}
	}
	int A1 = m / n;
	int A2 = m / n + 1;
	for (int i = 0; i < 111; ++i)
		for (int j = 0; j <= i; ++j)
			step1[i][j] = pow(c[i][j], A1);

	for (int i = 0; i < 111; ++i)
		for (int j = 0; j <= i; ++j)
			step2[i][j] = pow(c[i][j], A2);

	int r = m % n;

	dp1[0][0] = 1;
	for (int pos = 0; pos < n - r; ++pos)
		for (int got = 0; got <= k; ++got)
			for (int cur = 0; cur <= n && cur + got <= k; ++cur){
				dp1[pos + 1][got + cur] += dp1[pos][got] * step1[n][cur];
				dp1[pos + 1][got + cur] %= mod;
			}

	dp2[0][0] = 1;
	for (int pos = 0; pos < r; ++pos)
		for (int got = 0; got <= k; ++got)
			for (int cur = 0; cur <= n && cur + got <= k; ++cur){
				dp2[pos + 1][got + cur] += dp2[pos][got] * step2[n][cur];
				dp2[pos + 1][got + cur] %= mod;
			}

	int ans = 0;

	for (int i = 0; i <= k; ++i){
		ans += dp2[r][i] * dp1[n - r][k - i];
		//cout<<m % n<<' '<<i<<' '<<dp2[m % n][i]<<' '<<dp1[n - (m % n)][k - i]<<endl;
		ans %= mod;
	}

	cout<<ans;

}