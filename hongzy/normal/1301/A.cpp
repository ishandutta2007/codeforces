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
		char a[110], b[110], c[110];
		scanf("%s%s%s", a, b, c);
		int n = strlen(a), tag = 1;
		for(int i = 0; i < n; i ++) {
			if(a[i] == c[i] || b[i] == c[i]) {
				
			} else {
				tag = 0; break ;
			}
		}
		puts(tag ? "YES" : "NO");
	}
	return 0;
}