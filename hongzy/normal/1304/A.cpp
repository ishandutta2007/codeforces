#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1e5 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}

int main() {
	int t; scanf("%d", &t);
	while(t --) {
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b); y -= x;
		printf("%d\n", y % (a + b) == 0 ? (y / (a + b)) : -1);
	}
	return 0;
}