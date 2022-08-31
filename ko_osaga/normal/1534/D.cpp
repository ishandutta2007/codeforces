#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 3000005;
const int mod = 1e9 + 7;

struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int chk[2222];
int d[2222][2222];

int main(){
	int n; scanf("%d",&n);
	vector<pair<int, int>> v;
	vector<int> gph[2222];
	disj.init(n);
	int qr = 0;
	for(int i = 1; i <= n; i++){
		if(qr > (n + 1) / 2) break;
		if(sz(gph[i]) == 0){
			qr++;
			printf("? %d\n", i);
			fflush(stdout);
			for(int j = 1; j <= n; j++){
				scanf("%d",&d[i][j]);
				if(d[i][j] == 1){
					disj.uni(i, j);
					gph[i].push_back(j);
					gph[j].push_back(i);
					v.emplace_back(i, j);
				}
			}
			if(sz(gph[i]) == 1){
				int r = gph[i][0];
				for(int j = 1; j <= n; j++){
					if(j == i) d[r][j] = 1;
					else d[r][j] = d[i][j] - 1;
					if(d[r][j] == 1 && disj.uni(r, j)){
						gph[r].push_back(j);
						gph[j].push_back(r);
						v.emplace_back(r, j);
					}
				}
				chk[r] = 1;
			}
			chk[i] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!chk[i] && !chk[j] && disj.find(i) != disj.find(j)){
				int r0 = gph[i][0];
				int r1 = gph[j][0];
				if(d[r0][j] == 2 && d[r1][i] == 2){
					disj.uni(i, j);
					v.emplace_back(i, j);
				}
			}
		}
	}
	puts("!"); fflush(stdout);
	for(auto &[x, y] : v){
		printf("%d %d\n", x, y);
		fflush(stdout);
	}
}