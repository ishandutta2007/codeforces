#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
const int N = 1e5 + 10;
int n, a[N];
int main() {
	cin >>n;
	rep(i,1,n) scanf("%d",a + i);
	LL s = 0, mx = 0, mn = 0, ans = 0;
	dep(i,n - 1,1) {
		if (i & 1) s += ab(a[i] - a[i + 1]); else s -= ab(a[i] - a[i + 1]);
		if (i & 1) ans = max(ans, s - mn); else ans = max(ans, mx - s);
		mn = min(mn, s), mx = max(mx, s);
	}
	cout <<ans<<endl;
	return 0;
}