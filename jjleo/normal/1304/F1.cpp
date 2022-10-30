#include <bits/stdc++.h>
#define maxn 60
#define maxm 20086

using namespace std;

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

struct SegmentTree{
	struct Node{
		int sum;
	}t[maxm << 2];
	
	int a[maxm];
	
	inline void up(int x){
		t[x].sum = max(t[ls(x)].sum, t[rs(x)].sum);
	}
	
	void build(int x, int l, int r){
		if(l == r){
			t[x].sum = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(ls(x), l, mid), build(rs(x), mid + 1, r), up(x); 
	}
	
	int query(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr) return t[x].sum;
		int mid = l + r >> 1, sum = -2e9;
		if(mid >= ll) sum = max(sum, query(ls(x), l, mid, ll, rr)) ;
		if(mid < rr) sum = max(sum, query(rs(x), mid + 1, r, ll, rr));
		return sum;
	}
}F, X, Y;


int n, m, k, M;
int sum[maxn][maxm];
int f[maxn][maxm];
int ans;

int main(){
	scanf("%d%d%d", &n, &m, &k), M = m - k + 1;
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &sum[i][j]), sum[i][j] += sum[i][j - 1];
	for(int i = 1;i <= n;i++){
		if(i ^ 1){//debug:  
			for(int j = 1;j <= M;j++) F.a[j] = f[i - 1][j];F.build(1, 1, M);
			for(int j = 1;j <= M;j++) X.a[j] = f[i - 1][j] - sum[i][j + k - 1];X.build(1, 1, M);
			for(int j = 1;j <= M;j++) Y.a[j] = f[i - 1][j] + sum[i][j - 1];Y.build(1, 1, M);
		} 
		for(int j = 1;j <= M;j++){
			if(i ^ 1){//debug:  
				f[i][j] = max(X.query(1, 1, M, j - k + 1, j) + sum[i][j - 1], Y.query(1, 1, M, j, j + k - 1) - sum[i][j + k - 1]);
				if(j - k + 1 > 1) f[i][j] = max(f[i][j], F.query(1, 1, M, 1, j - k));
				if(j + k - 1 < M) f[i][j] = max(f[i][j], F.query(1, 1, M, j + k, M));// 
			}
			f[i][j] += sum[i][j + k - 1] - sum[i][j - 1] + sum[i + 1][j + k - 1] - sum[i + 1][j - 1];//debug:j-1 j 
			//printf("%d %d %d--\n", i, j, f[i][j]);
			if(i == n) ans = max(ans, f[i][j]);
		}
	}
	printf("%d", ans);
	
}