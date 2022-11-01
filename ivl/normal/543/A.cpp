#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >
#define all(x) (x).begin(), (x).end()

using namespace std;

int n, m, b, v;
int a[505];

int mat[505][505];

int main(){
	scanf("%d%d%d%d", &n, &m, &b, &v);
	FOR(0, n, i) scanf("%d", a + i);
	
	mat[0][0] = 1;
	FOR(0, n, i)
		FOR(0, 500, k)
			FOR(0, 501, t)
				if (t + a[i] <= b)
					mat[k + 1][t + a[i]] = (mat[k + 1][t + a[i]] + mat[k][t]) % v;
					
	ll R = 0;
	FOR(0, b + 1, i) R += mat[m][i];
	printf("%I64d\n", R % v);
	
	return 0;
}