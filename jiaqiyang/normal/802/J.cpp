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
int n, d[N]; //O(10^9)

struct edge{ int to, pre, c; }e[N << 1]; int u[N], l = 0;
void ins(int a, int b, int c) { e[++l] = (edge){b, u[a], c}, u[a] = l; }
#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

void dfs(int x, int f) {
	d[x] = 0;
	reg(i,x) if (v != f) dfs(v, x), d[x] = max(d[x], d[v] + ec);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n - 1) {
		int a, b, c; scanf("%d%d%d",&a,&b,&c);
		a++, b++;
		ins(a, b, c), ins(b, a, c);
	}
	dfs(1,0);
	cout <<d[1]<<endl;
	return 0;
}