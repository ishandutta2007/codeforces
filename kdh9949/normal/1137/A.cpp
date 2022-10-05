#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, a[N][N], b[N], r[N][N], c[N][N], rm[N], cm[N];

void cp(int n, int a[], int &mx){
	for(int i = 0; i < n; i++) b[i] = a[i + 1];
	sort(b, b + n);
	int j = 0;
	for(int i = 0; i < n; i++){
		if(j && b[i] == b[j - 1]) continue;
		b[j++] = b[i];
	}
	mx = j;
	for(int i = 1; i <= n; i++) a[i] = int(lower_bound(b, b + j, a[i]) - b + 1);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%d", a[i] + j);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
		r[i][j] = a[i][j];
		c[j][i] = a[i][j];
	}
	for(int i = 1; i <= n; i++) cp(m, r[i], rm[i]);
	for(int i = 1; i <= m; i++) cp(n, c[i], cm[i]);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int rt = r[i][j], ct = c[j][i];
			int rr;
			if(rt < ct) rr = max(cm[j], rm[i] + ct - rt);
			else rr = max(rm[i], cm[j] + rt - ct);
			printf("%d ", rr);
		}
		puts("");
	}
}