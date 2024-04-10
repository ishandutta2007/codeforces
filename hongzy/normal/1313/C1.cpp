#include <algorithm>
#include <iostream>
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

const int N = 5e5 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
struct node {
	int x, cnt;
	bool operator < (const node &b) const {
		return x < b.x;
	}
};
priority_queue<node> S1, S2; 
int n, a[N];
ll l[N], r[N];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	ll cur = 0;
	for(int i = n; i >= 1; i --) {
		int cnt = 1;
		while(S1.size() && S1.top().x >= a[i]) {
			node tmp = S1.top(); S1.pop();
			cur -= tmp.x * (ll) tmp.cnt;
			cnt += tmp.cnt;
		}
		cur += a[i] * (ll) cnt;
		S1.push((node) {a[i], cnt});
		r[i] = cur;
	}
	cur = 0;
	for(int i = 1; i <= n; i ++) {
		int cnt = 1;
		while(S2.size() && S2.top().x >= a[i]) {
			node tmp = S2.top(); S2.pop();
			cur -= tmp.x * (ll) tmp.cnt;
			cnt += tmp.cnt;
		}
		cur += a[i] * (ll) cnt;
		S2.push((node) {a[i], cnt});
		l[i] = cur;
	}
	int y = 1;
	for(int i = 1; i <= n; i ++)
		if(l[i] + r[i] - a[i] > l[y] + r[y] - a[y]) y = i;
	for(int i = y + 1; i <= n; i ++) a[i] = min(a[i], a[i - 1]); 
	for(int i = y - 1; i >= 1; i --) a[i] = min(a[i], a[i + 1]);
	for(int i = 1; i <= n; i ++) printf("%d ", a[i]);
	return 0;
}