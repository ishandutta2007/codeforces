#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

int n;
int a[maxn], cnt, x;
bool tag[maxn];
int f[maxn][maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &tag[i]);
		if(tag[i]) a[++cnt] = i;
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= cnt;j++){
			f[i][j] = f[i - 1][j];
			if(j && !tag[i]) f[i][j] = min(f[i][j], f[i - 1][j - 1] + abs(i - a[j]));
		}
	}
	printf("%d", f[n][cnt]);
}