#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define FOR(a, b, c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)

using namespace std;

double dp(int a, int b, int c){
	if (a < 0 || b < 0 || c < 0) return 0;
	static double memo[105][105][105];
	static bool bio[105][105][105];
	double &r = memo[a][b][c];
	if (bio[a][b][c]++) return r;
	if (a == 0) return r = 0;
	if (b == 0 && c == 0) return r = 1;
	
	r = 0;
	int Cnt = a * b + b * c + c * a;
	
	r += dp(a, b - 1, c) * a * b / Cnt;
	r += dp(a, b, c - 1) * b * c / Cnt;
	r += dp(a - 1, b, c) * c * a / Cnt;
	return r;
	
}

int main(){
	FOR(0, 100, i) FOR(0, 100, j) FOR(0, 100, k) dp(i, j, k);
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%.12lf %.12lf %.12lf\n", dp(a, b, c), dp(b, c, a), dp(c, a, b));
	return 0;
}