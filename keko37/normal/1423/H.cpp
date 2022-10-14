#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 5e5 + 500;
const int LOG = 19;
const int OFF = (1 << LOG);

set < pii > S[N];
map < int, int > met[N];
int n, q, k, dan = 1, u[N], v[N], cur;
int tko[N], kol, ans[N], par[N], siz[N];

vector < int > T[2 * OFF], pit[OFF];
vector < pii > mkni[OFF];

void add(int i, int a, int b, int lo, int hi, int brd){
	if(lo <= a && b <= hi){
		T[i].PB(brd); return;
	}
	if(a > hi || b < lo) return;
	add(2 * i, a, (a + b) / 2, lo, hi, brd);
	add(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, brd);
}

vector < int > revert;

int pr(int x){
	if(x == par[x]) return x;
	return pr(par[x]);
}

bool mrg(int x, int y){
	x = pr(x), y = pr(y);
	if(x == y) return 0;
	if(siz[x] < siz[y]){
		x ^= y, y ^= x, x ^= y;
	}
	siz[x] += siz[y];
	par[y] = x; revert.PB(y);
	return 1;
}

void makni(){
	if((int)revert.size() == 0){
		printf("OPASNO\n");
		return;
	}
	int cur = revert.back();
	siz[par[cur]] -= siz[cur];
	par[cur] = cur;
	revert.pop_back();	
}

void dfs(int i){
	int mor = 0;
	for(int bla : T[i])
		mor += mrg(u[bla], v[bla]);
	if(i < OFF){
		dfs(2 * i); dfs(2 * i + 1);
	}
	else{
		for(int cur : pit[i - OFF]){
			ans[cur] = siz[pr(tko[cur])];
		}
	}
	for(;mor--;) makni();
}

int main(){
	scanf("%d%d%d", &n, &q, &k);
	for(int i = 1;i <= n;i++)
		par[i] = i, siz[i] = 1;
	for(int i = 0;i < q;i++){
		int ty; scanf("%d", &ty);
		if(ty == 3) {
			dan++;
			for(pii jos : mkni[dan]){
				add(1, 0, OFF - 1, jos.Y, i, jos.X);
			}
		}
		if(ty == 1){
			scanf("%d%d", u + cur, v + cur);
			mkni[dan + k].PB({cur, i});
			cur++;
		}
		if(ty == 2){
			int z; scanf("%d", &z);
			tko[kol] = z;
			pit[i].PB(kol);
			kol++;
		}
	}
	for(dan++;dan < OFF;dan++){
		for(pii jos : mkni[dan]){
			add(1, 0, OFF - 1, jos.Y, q, jos.X);
		}
	}
	dfs(1);
	for(int i = 0;i < kol;i++)
		printf("%d\n", ans[i]);
	return 0;
}