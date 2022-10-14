#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 155;
const int MOD = 1000000007;

int n, m, sol;
int dp[MAXN] [MAXN] [5];
int sum[MAXN] [MAXN] [5];
int p[MAXN] [MAXN] [5];

int add (int a, int b) {
	if (a+b>=MOD) return a+b-MOD; return a+b;
}

int sub (int a, int b) {
	if (a-b<0) return a-b+MOD; return a-b;
}

inline get (int x1, int x2, int y1, int y2, int mask) {
	int res=sum[x2] [y2] [mask];
	res=sub(res, y1?sum[x2] [y1-1] [mask]:0);
	res=sub(res, x1?sum[x1-1] [y2] [mask]:0);
	res=add(res, (x1&&y1)?sum[x1-1] [y1-1] [mask]:0);
	return res;
}

int main () {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			for (int k=0; k<4; k++) {
				dp[i] [j] [k]=(i<=j);
				sum[i] [j] [k]=dp[i] [j] [k];
				if (i) sum[i] [j] [k]+=sum[i-1] [j] [k];
				if (j) sum[i] [j] [k]+=sum[i] [j-1] [k];
				if (i && j) sum[i] [j] [k]-=sum[i-1] [j-1] [k];
			}
			sol=add(sol, dp[i] [j] [3]);
		}
	}
	for (int r=n-2; r>=0; r--) {
		memset(p, 0, sizeof p);
		for (int i=0; i<m; i++) {
			for (int j=i; j<m; j++) {
				for (int mask=0; mask<4; mask++) {
					if ((mask & 2) && (mask & 1) && i && (j!=m-1)) {
						p[i] [j] [mask]=add(p[i] [j] [mask], get(0, i-1, j+1, m-1, 3));
					}
					if ((mask & 2) && i) {
						p[i] [j] [mask]=add(p[i] [j] [mask], get(0, i-1, j, j, mask));
					}
					if ((mask & 2) && i && (i!=j)) {
						p[i] [j] [mask]=add(p[i] [j] [mask], get(0, i-1, i, j-1, 2));
					}
					if ((mask & 1) && (j!=m-1)) {
						p[i] [j] [mask]=add(p[i] [j] [mask], get(i, i, j+1, m-1, mask));
					}
					if (1) {
						p[i] [j] [mask]=add(p[i] [j] [mask], get(i, i, j, j, mask));
					}
					if (i!=j) {
						p[i] [j] [mask]=add(p[i] [j] [mask], get(i, i, i, j-1, mask & 2));
					}
					if ((mask & 1) && (j!=m-1) && (i!=j)) {
						p[i] [j] [mask]=add(p[i] [j] [mask], get(i+1, j, j+1, m-1, 1));
					}
					if (i!=j) {
						p[i] [j] [mask]=add(p[i] [j] [mask], get(i+1, j, j, j, mask & 1));
					}
					if (i+1<=j-1) {
						p[i] [j] [mask]=add(p[i] [j] [mask], get(i+1, j-1, i+1, j-1, 0));
					}
				}
			}
		}
		for (int i=0; i<m; i++) {
			for (int j=0; j<m; j++) {
				for (int k=0; k<4; k++) {
					dp[i] [j] [k]=add(p[i] [j] [k], (i<=j));
					sum[i] [j] [k]=dp[i] [j] [k];
					if (i) sum[i] [j] [k]=add(sum[i] [j] [k], sum[i-1] [j] [k]);
					if (j) sum[i] [j] [k]=add(sum[i] [j] [k], sum[i] [j-1] [k]);
					if (i && j) sum[i] [j] [k]=sub(sum[i] [j] [k], sum[i-1] [j-1] [k]);
				}
				sol=add(sol, dp[i] [j] [3]);
			}
		}
	}
	cout << sol;
	return 0;
}