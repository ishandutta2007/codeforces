#include <bits/stdc++.h>
#define maxn 205

using namespace std;

int t;
int n, m;
char s[maxn][maxn];
bool a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		memset(a, 0, sizeof(a));
		int ans = 0;
		for(int i = n;i;i--){
			for(int j = m;j;j--){
				if(i == n && j == m){
					a[i][j] = true;
					continue;
				}
				if((s[i][j] == 'D' && !a[i + 1][j]) || (s[i][j] == 'R' && !a[i][j + 1])) ans++;
				a[i][j] = true;
			}
		}
		printf("%d\n", ans);
	}
}