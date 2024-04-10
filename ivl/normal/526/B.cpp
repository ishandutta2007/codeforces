#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long

using namespace std;

int n;
int a[10000];

int main(){
	scanf("%d", &n);
	FOR(2, 1 << (n + 1), i) scanf("%d", a + i);
	int R = 0;
	for (int i = (1 << n) - 1; i >= 1; --i){
		int a = ::a[i * 2], b = ::a[i * 2 + 1];
		R += abs(a - b);
		::a[i] += max(a, b);
	}
	printf("%d\n", R);
	return 0;
}