#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }

ll n;
int m;

struct Matrix
{
	ll vals[100][100];

	Matrix()
	{
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < m; ++j)
				vals[i][j] = 0;
	}
};

Matrix idenitity()
{
	Matrix ret;

	for(int i = 0; i < m; ++i)
		ret.vals[i][i] = 1;

	return ret;
}

Matrix mult(const Matrix& A, const Matrix& B)
{
	Matrix mt;

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			mt.vals[i][j] = 0;

			for(int k = 0; k < m; ++k)
				mt.vals[i][j] = (mt.vals[i][j] + A.vals[i][k] * B.vals[k][j]) % mod;
		}
	}

	return mt;
}

Matrix binpow(const Matrix& A, ll p)
{
	if(p == 0)
		return idenitity();

	if(p == 1)
		return A;

	Matrix ret = binpow(A, p / 2);
	ret = mult(ret, ret);

	if(p % 2 == 1)
		ret = mult(ret, A);

	return ret;
}

void solve()
{
	cin >> n >> m;

	if(n < m)
	{
		cout << "1" << endl;
		return;
	}

	Matrix M0;
	M0.vals[0][0] = 1;
	M0.vals[0][m - 1] = 1;

	for(int i = 1; i < m; ++i)
	{
		M0.vals[i][i - 1] = 1;
	}

	Matrix M = binpow(M0, n - m + 1);

	ll ans = 0;

	for(int i = 0; i < m; ++i)
		ans = (ans + M.vals[0][i]) % mod;

#ifdef __LOCAL
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < m; ++j)
			cout << M.vals[i][j] << " ";

		cout << endl;
	}
#endif

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}