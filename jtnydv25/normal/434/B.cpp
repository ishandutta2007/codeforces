#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 1005;

int lft[N][N], rgt[N][N], up[N][N], down[N][N], nxt[N], lst[N], arr[N], a[N][N];
int n, m;	
void evalRow(int i){
	for(int j = 1; j <= m; j++){
		lft[i][j] = (a[i][j] == 1) ? lft[i][j - 1] + 1 : 0;
	}
	for(int j = m; j >= 1; j--){
		rgt[i][j] = (a[i][j] == 1) ? rgt[i][j + 1] + 1 : 0;
	}
}

void evalCol(int j){
	for(int i = 1; i <= n; i++)
		up[i][j] = (a[i][j] == 1) ? up[i - 1][j] + 1 : 0;
	for(int i = n; i >= 1; i--) down[i][j] = (a[i][j] == 1) ? down[i + 1][j] + 1 : 0;
}

int getMaxRectangle(int A[], int n, int I){
	int sz = 0;
	for(int i = 1; i <= n; i++){
		while(sz && A[arr[sz - 1]] >= A[i]){
			sz--;
		}
		lst[i] = sz ? arr[sz - 1] : 0;
		arr[sz++] = i;
	}
	sz = 0;
	for(int i = n; i >= 1; i--){
		while(sz && A[arr[sz - 1]] >= A[i]){
			sz--;
		}
		nxt[i] = sz ? arr[sz - 1] : n + 1;
		arr[sz++] = i;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(i <= I){
			if(nxt[i] > I){
				ans = max(ans, (nxt[i] - lst[i] - 1) * A[i]);
			}
		}
		if(i >= I && lst[i] < I){
			ans = max(ans, (nxt[i] - lst[i] - 1) * A[i]);
		}
	}
	// cerr << I << " " << ans << endl;
	return ans;
}

int A[N];
int main(){
	int q;
	sd(n); sd(m); sd(q);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			sd(a[i][j]);
	}
	for(int i = 1; i <= n; i++) evalRow(i);
	for(int i = 1; i <= m; i++) evalCol(i);

	while(q--){
		int i, j, type;
		sd(type); sd(i); sd(j);
		if(type == 1){
			a[i][j] ^= 1;
			evalRow(i);
			evalCol(j);
		}
		else{
			for(int i = 1; i <= n; i++) A[i] = lft[i][j];
			int a1 = getMaxRectangle(A, n, i);
			for(int i = 1; i <= n; i++) A[i] = rgt[i][j];
			int a2 = getMaxRectangle(A, n, i);
			int a3 = getMaxRectangle(up[i], m, j);
			int a4 = getMaxRectangle(down[i], m, j);
			printf("%d\n", max(a1, max(a2, max(a3, a4))));
		}
	}
}