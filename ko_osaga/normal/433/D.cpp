#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, m, a[1005][1005];
int lx[1005][1005], hx[1005][1005];
int ly[1005][1005], hy[1005][1005];
int aux[1005], sz;

void constx(int j){
	for(int i=1; i<=n; i++){
		if(a[i][j] == 0) lx[i][j] = i;
		else lx[i][j] = lx[i-1][j];
	}
	hx[n+1][j] = n+1;
	for(int i=n; i; i--){
		if(a[i][j] == 0) hx[i][j] = i;
		else hx[i][j] = hx[i+1][j];
	}
}

void consty(int i){
	ly[i][0] = 0;
	for(int j=1; j<=m; j++){
		if(a[i][j]==0) ly[i][j] = j;
		else ly[i][j] = ly[i][j-1];
	}
	hy[i][m+1] = m+1;
	for(int j=m; j; j--){
		if(a[i][j] == 0) hy[i][j] = j;
		else hy[i][j] = hy[i][j+1];
	}
}

int solve(int mid){
	int p = mid-1, q = mid+1, cnt = 1;
	aux[0] = -1, aux[sz+1] = -1;
	int hi = aux[mid], ret = aux[mid];
	while(cnt < sz){
		if(aux[p] <= aux[q]){
			hi = min(hi, aux[q]);
			q++;
		}
		else{
			hi = min(hi, aux[p]);
			p--;
		}
		cnt++;
		ret = max(ret, hi * cnt);
	}
	return ret;
}

int main(){
	int q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1; i<=n; i++) consty(i);
	for(int j=1; j<=m; j++) constx(j);
	while(q--){
		int t; scanf("%d",&t);
		if(t == 1){
			int x, y;
			scanf("%d %d",&x, &y);
			a[x][y] ^= 1;
			consty(x);
			constx(y);
		}
		else{
			int x, y, ret = 0;
			scanf("%d %d",&x,&y);
			for(int i=1; i<=n; i++){
				aux[i] = y - ly[i][y];
			}
			sz = n;
			ret = max(ret, solve(x));
			for(int i=1; i<=n; i++){
				aux[i] = hy[i][y] - y;
			}
			ret = max(ret, solve(x));
			for(int i=1; i<=m; i++){
				aux[i] = hx[x][i] - x;
			}
			sz = m;
			ret = max(ret, solve(y));
			for(int i=1; i<=m; i++){
				aux[i] = x - lx[x][i];
			}
			ret = max(ret, solve(y));
			printf("%d\n", ret);
		}
	}
}