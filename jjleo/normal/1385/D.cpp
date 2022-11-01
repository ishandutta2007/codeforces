#include <bits/stdc++.h>
#define maxn 140086

using namespace std;

int t;
int n;
char s[maxn];
int f[maxn][26];

int dfs(int l, int r, int c){
	if(l == r) return s[l] != c + 'a';
	int mid = l + r >> 1;
	return min(dfs(l, mid, c + 1) + r - mid - (f[r][c] - f[mid][c]), dfs(mid + 1, r, c + 1) + mid - l + 1 - (f[mid][c] - f[l - 1][c]));
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < 26;j++){
				f[i][j] = f[i - 1][j] + (s[i] == j + 'a');
			}
		}
		printf("%d\n", dfs(1, n, 0));
	}
}