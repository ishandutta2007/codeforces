#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;

int ans[2 * N], n;
int yy(int x) {
	return x % 2 == 0 ? x - 1 : x + 1;
}
int main() {
	cin >> n;
	if(n % 2 == 0) puts("NO");
	else {
		n *= 2;
		puts("YES"); int x = 1, y = n;
		for(int i = 1; i <= n / 2; i ++) {
			if(i & 1) {
				ans[i] = x; ans[i + n / 2] = yy(x); x += 2;
			} else {
				ans[i] = y; ans[i + n / 2] = yy(y); y -= 2;
			}
		}
		for(int i = 1; i <= n; i ++) printf("%d ", ans[i]);
	}
	return 0;
}