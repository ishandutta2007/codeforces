#include <bits/stdc++.h>
using namespace std;

const int N = 1005, M = 55, K = 128;

int n, a, b, d[N][M][M], mp[M][K], mq[M][K];
char s[N], p[M], q[M];

int mat(int t, int x, char c){
	int &r = (t ? mq[x][c] : mp[x][c]);
	char *s = (t ? q : p);
	if(~r) return r;
	if(s[x + 1] == c) return r = x + 1;
	for(int i = x - 1; i >= 0; i--){
		int val = 1;
		for(int j = 1; j <= i; j++) if(s[j] != s[j + (x - i)]) val = 0;
		if(val && s[i + 1] == c) return r = i + 1;
	}
	return r = 0;
}

int main(){
	scanf("%s%s%s", s + 1, p + 1, q + 1);
	n = strlen(s + 1);
	a = strlen(p + 1);
	b = strlen(q + 1);
	memset(mp, -1, sizeof(mp));
	memset(mq, -1, sizeof(mq));
	memset(d, 0x80, sizeof(d));
	d[0][0][0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= a; j++) for(int k = 0; k <= b; k++){
			for(char t = 'a'; t <= 'z'; t++){
				if(s[i + 1] != t && s[i + 1] != '*') continue;
				int nj = mat(0, j, t), nk = mat(1, k, t);
				int nd = d[i][j][k] + (nj == a) - (nk == b);
				d[i + 1][nj][nk] = max(d[i + 1][nj][nk], nd);
			}
		}
	}
	int r = -int(1e9);
	for(int i = 0; i <= a; i++) for(int j = 0; j <= b; j++) r = max(r, d[n][i][j]);
	printf("%d\n", r);
}