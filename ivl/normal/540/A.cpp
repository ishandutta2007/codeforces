#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(a, b, c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) FOR(0, n, _rep)

using namespace std;

int n;
char a[1005];
char b[1005];

int main(){
	scanf("%d", &n);
	scanf("%s%s", a, b);
	int R = 0;
	FOR(0, n, i){
		int x = a[i] - '0' + 10 - b[i] + '0';
		x %= 10;
		R += min(x, 10 - x);
	} printf("%d\n", R);
	return 0;
}