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

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 18;
const int OFF = (1 << LOG);

int cen[N], siz[N], n, k;
vector < int > cur, za[2], v[N];
vector < pii > edg;

void bojaj(int x, int lst, int koj){
	za[koj].PB(x);
	for(int y : v[x])
		if(y != lst && !cen[y])
			bojaj(y, x, !koj);
}

void dfs(int x, int lst){
	siz[x] = 1; cur.PB(x);
	for(int y : v[x]){
		if(!cen[y] && y != lst){
			dfs(y, x);
			siz[x] += siz[y];
		}
	}
}

bool cmp(int x, int y){
	return siz[x] > siz[y];
}

void nadi(int root){
	cur.clear(); dfs(root, root);
	int nw = root;
	int ja = (int)cur.size();
	for(int x : cur){
		if(2 * siz[x] >= ja && siz[x] < siz[nw])
			nw = x;
	}
	root = nw; cen[root] = 1;
	//printf("CENTROID = %d\n", root);
	cur.clear(); dfs(root, root);
	vector < int > dalje;
	for(int y : v[root])
		if(!cen[y])
			dalje.PB(y);
	sort(dalje.begin(), dalje.end(), cmp);
	for(int i = 0;i < (int)dalje.size();i++){
		za[0].clear(); za[1].clear();
		bojaj(dalje[i], dalje[i], 0);
		if((int)za[0].size() > (int)za[1].size())
			swap(za[0], za[1]);
		for(int x : za[0])
			edg.PB({root, x});
		if(i)
			for(int x : za[1])
				edg.PB({root, x});
	}
	for(int x : dalje)
		nadi(x);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y), v[y].PB(x);
	}
	nadi(1);
	printf("%d\n", (int)edg.size());
	for(pii tmp : edg)
		printf("%d %d\n", tmp.X, tmp.Y);
}