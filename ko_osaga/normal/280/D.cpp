#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXT = 270005;
const int INF = 987654321;

int tree[MAXT][2][2][21];
int aux[2][2][21];

void merge(int p, int l, int r){
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<21; k++){
				aux[i][j][k] = -INF;
			}
		}
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				int p1 = 0;
				int p2 = 0;
				if(j > 0){
					if(tree[l][i][j][1] - tree[l][i][j][0] > tree[r][j][k][1] - tree[r][j][k][0]) p1++;
					else p2++;
				}
				aux[i][k][0] = max(aux[i][k][0], tree[l][i][j][p1] + tree[r][j][k][p2]);
				for(int x=1; x<21; x++){
					int d1 = -INF * 2;
					int d2 = -INF * 2;
					if(p1 + 1 < 21 && tree[l][i][j][p1+1] > -INF) d1 = tree[l][i][j][p1+1] - tree[l][i][j][p1];
					if(p2 + 1 < 21 && tree[r][j][k][p2+1] > -INF) d2 = tree[r][j][k][p2+1] - tree[r][j][k][p2];
					if(d1 > d2) p1++;
					else p2++;
					if(p1 >= 21 || p2 >= 21 || tree[l][i][j][p1] <= -INF || tree[r][j][k][p2] <= -INF) break;
					aux[i][k][x] = max(aux[i][k][x], tree[l][i][j][p1] + tree[r][j][k][p2]);
				}
			}
		}
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<21; k++){
				tree[p][i][j][k] = aux[i][j][k];
			}
		}
	}
}

void init(int s, int e, int p, int *arr){
	if(s == e){
		tree[p][0][0][1] = arr[s];
		tree[p][0][1][1] = arr[s];
		tree[p][1][0][1] = arr[s];
		tree[p][1][1][1] = arr[s];
		tree[p][0][0][0] = 0;
		return;
	}
	int m = (s+e)/2;
	init(s, m, 2*p, arr);
	init(m+1, e, 2*p+1, arr);
	merge(p, 2*p, 2*p+1);
}

void upd(int pos, int s, int e, int p, int v){
	if(s == e){
		tree[p][0][0][1] = v;
		tree[p][0][1][1] = v;
		tree[p][1][0][1] = v;
		tree[p][1][1][1] = v;
		tree[p][0][0][0] = 0;
		return;
	}
	int m = (s+e)/2;
	if(pos <= m) upd(pos, s, m, 2*p, v);
	else upd(pos, m+1, e, 2*p+1, v);
	merge(p, 2*p, 2*p+1);
}

void query(int s, int e, int ps, int pe, int p){
	if(e < ps || pe < s) return;
	if(s <= ps && pe <= e){
		merge(0, 0, p);
		return;
	}
	int pm = (ps+pe)/2;
	query(s, e, ps, pm, 2*p);
	query(s, e, pm+1, pe, 2*p+1);
}

int readInt(){ int x; scanf("%d",&x); return x; }

int main(){
	int n = readInt();
	int arr[MAXN];
	for(int i=0; i<MAXT; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++){
		for(int l=0; l<21; l++) tree[i][j][k][l] = -INF;
	}
	for(int i=0; i<n; i++) arr[i] = readInt();
	init(0, n - 1, 1, arr);
	int q = readInt();
	while(q--){
		int L[4];
		for(int i=0; i<3; i++) L[i] = readInt();
		if(L[0] == 0){
			upd(L[1] - 1, 0, n - 1, 1, L[2]);
		}
		else{
			L[3] = readInt();
			for(int i=0; i<2; i++){
				for(int j=0; j<2; j++){
					for(int k=0; k<21; k++){
						tree[0][i][j][k] = -INF;
					}
				}
			}
			tree[0][0][0][0] = 0;
			query(L[1] - 1, L[2] - 1, 0, n - 1, 1);
			int dap = 0;
			for(int i=0; i<=L[3]; i++){
				dap = max(dap, tree[0][0][0][i]);
			}
			printf("%d\n", dap);
		}
	}
}