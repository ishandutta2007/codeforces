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
typedef pair<int, int> pii;
#define x first
#define y second
const int N = 1e5 + 10;
int n, d0[N], d1[N]; //O(10^9)

struct edge{ int to, pre, c; }e[N << 1]; int u[N], l = 0;
void ins(int a, int b, int c) { e[++l] = (edge){b, u[a], c}, u[a] = l; }
#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)
int k;
void dfs(int x, int f) {
	reg(i,x) if (v != f) dfs(v, x);
	d0[x] = d1[x] = 0;
	static pii a[N]; int l = 0;
	
	reg(i,x) if (v != f) a[++l] = mp(d0[v] + ec, d1[v] + ec);
	if (l < k) { 
		rep(i,1,l) d0[x] += a[i].x; 
		rep(i,1,l) d1[x] = max(d1[x], d0[x] - a[i].x + a[i].y);
	} else {
		sort(a + 1, a + l + 1); reverse(a + 1, a + l + 1);
		rep(i,1,k - 1) d0[x] += a[i].x;
		rep(i,1,k - 1) d1[x] = max(d1[x], d0[x] - a[i].x + a[i].y + a[k].x);
		rep(i,k,l) d1[x] = max(d1[x], d0[x] + a[i].y);
	}
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n - 1) {
		int a, b, c; scanf("%d%d%d",&a,&b,&c);
		a++, b++; ins(a, b, c), ins(b, a, c);
	}
	dfs(1,0);
	cout <<d1[1]<<endl;
	return 0;
}