#include <bits/stdc++.h>
#define maxn 1005

using namespace std;

int n, k;
int a[maxn][maxn];
set<int> st;
int l[maxn * maxn], r[maxn * maxn], u[maxn * maxn], d[maxn * maxn];
int b[maxn][maxn];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++){
		scanf("%d", &a[i][j]);
		st.insert(a[i][j]);
	}
	if(st.size() <= k) return printf("%d", k - st.size()), 0;
	for(int i = 1;i <= n * n;i++) l[i] = u[i] = n + 1;
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++){
		l[a[i][j]] = min(l[a[i][j]], j);
		r[a[i][j]] = max(r[a[i][j]], j);
		u[a[i][j]] = min(u[a[i][j]], i);
		d[a[i][j]] = max(d[a[i][j]], i);
	}
	for(int len = 1;len <= n;len++){
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) b[i][j] = 0; 
		for(int i = 1;i <= n * n;i++) if(l[i] < n + 1){
			if(max(r[i] - l[i] + 1, d[i] - u[i] + 1) > len) continue;
			b[d[i]][r[i]]++;
			int x = d[i] + (len - (d[i] - u[i] + 1));
			int y = r[i] + (len - (r[i] - l[i] + 1));
			b[x + 1][r[i]]--;
			b[d[i]][y + 1]--;
			b[x + 1][y + 1]++;
		}
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++){
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			assert(b[i][j] <= st.size());
			if(i >= len && j >= len){
				if(st.size() - b[i][j] == k || st.size() - b[i][j] + 1 == k){
					return printf("1"), 0;
				}
			}
		}
	}
	printf("2");
}