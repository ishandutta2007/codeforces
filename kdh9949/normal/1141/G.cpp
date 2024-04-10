#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

const int N = 200005;

int n, k, d[N], r[N];
vector<pii> e[N];

void f(int x, int y, int t, int z){
	int c = 0;
	for(pii i : e[x]){
		if(i.x == y) continue;
		c++;
		if(c == z) c++;
		c = min(c, t);
		r[i.y] = c;
		f(i.x, x, t, c);
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0, x, y; i < n - 1; i++){
		scanf("%d%d", &x, &y);
		d[x]++; d[y]++;
		e[x].emplace_back(y, i);
		e[y].emplace_back(x, i);
	}
	sort(d + 1, d + n + 1);
	reverse(d + 1, d + n + 1);
	int t = d[k + 1];
	printf("%d\n", t);
	f(1, 0, t, 0);
	for(int i = 0; i < n - 1; i++) printf("%d ", r[i]);
	puts("");
}