#include <bits/stdc++.h>
#define maxn 1086
#define maxm 100086

using namespace std;

int t;
int n, m;
int a[maxn][maxn], b[maxn][maxn];
char s[maxm];

int A[5][5], B[5][5], C[5][5];

void mul(){
	memset(C, 0, sizeof(C));
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 4;j++){
			for(int k = 1;k <= 4;k++){
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % n;
			}
		}
	}
	for(int i = 1;i <= 4;i++) for(int j = 1;j <= 4;j++) A[i][j] = C[i][j];
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) scanf("%d", &a[i][j]);
		scanf("%s", s + 1);
		memset(A, 0, sizeof(A)), A[1][1] = A[2][2] = A[3][3] = A[4][4] = 1;
		for(int i = 1;i <= m;i++){
			switch(s[i]){
				case 'R':
					memset(B, 0, sizeof(B));
					B[1][1] = B[2][2] = B[3][3] = B[4][4] = 1;
					B[4][2] = 1;
					break;
				case 'L':
					memset(B, 0, sizeof(B));
					B[1][1] = B[2][2] = B[3][3] = B[4][4] = 1;
					B[4][2] = n - 1;
					break;
				case 'D':
					memset(B, 0, sizeof(B));
					B[1][1] = B[2][2] = B[3][3] = B[4][4] = 1;
					B[4][1] = 1;
					break;
				case 'U':
					memset(B, 0, sizeof(B));
					B[1][1] = B[2][2] = B[3][3] = B[4][4] = 1;
					B[4][1] = n - 1;
					break;
				case 'I':
					memset(B, 0, sizeof(B));
					B[1][1] = B[2][3] = B[3][2] = B[4][4] = 1;
					break;
				case 'C':
					memset(B, 0, sizeof(B));
					B[1][3] = B[2][2] = B[3][1] = B[4][4] = 1;
					break;
			}
			mul();
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				int k = a[i][j] - 1;
				int ii = (i * A[1][1] + j * A[2][1] + k * A[3][1] + A[4][1]) % n;
				int jj = (i * A[1][2] + j * A[2][2] + k * A[3][2] + A[4][2]) % n;
				int kk = (i * A[1][3] + j * A[2][3] + k * A[3][3] + A[4][3]) % n;
				b[ii][jj] = kk;
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++) printf("%d ", b[i][j] + 1);
			puts("");
		}
	}
}