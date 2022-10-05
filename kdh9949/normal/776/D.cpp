#include <bits/stdc++.h>
using namespace std;

int n, m, a[100010], p[200010];
vector<int> e[100010];

int fnd(int x){ if(x == p[x]) return x; p[x] = fnd(p[x]); return p[x]; }
void uni(int x, int y){ p[fnd(x)] = fnd(y); }

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1, t; i <= m; i++){
        scanf("%d", &t);
        for(int j = 0, x; j < t; j++){
			scanf("%d", &x);
			e[x].push_back(i);
        }
	}
	for(int i = 1; i <= 2 * m; i++) p[i] = i;
	for(int i = 1, x, y; i <= n; i++){
		x = e[i][0]; y = e[i][1];
		if(a[i]){
			uni(x, y);
			uni(x + m, y + m);
		}
		else{
			uni(x + m, y);
			uni(x, y + m);
		}
	}
	for(int i = 1; i <= m; i++) if(fnd(i) == fnd(i + m)){ puts("NO"); return 0; }
	puts("YES");
	return 0;
}