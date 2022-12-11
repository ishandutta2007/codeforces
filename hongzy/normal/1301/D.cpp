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
#define mp make_pair
#define pb push_back 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;

int n, m, k;
vector< pair<string, int>  > ans;
void push(string s, int t) {
	if(t == 0) return ; 
	static int x;
	int sz = (int) s.size();
	if(x + (ll) sz * t >= k) {
		int d = k - x; string tmp;
		if(d / sz > 0) ans.pb(mp(s, d / sz));
		for(int i = 0; i < d % sz; i ++) tmp.pb(s[i]);
		if(d % sz > 0) ans.pb(mp(tmp, 1));
		printf("YES\n%d\n", (int) ans.size());
		for(auto y : ans) {
			printf("%d %s\n", y.sc, y.fs.c_str());
		}
		exit(0); 
	}
	ans.pb(mp(s, t)); x += sz * t;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i < n; i ++) {
		push("RDU", m - 1);
		push("L", m - 1);
		push("D", 1);
	}
	push("R", m - 1);
	push("L", m - 1);
	push("U", n - 1);
	puts("NO"); 
	return 0;
}