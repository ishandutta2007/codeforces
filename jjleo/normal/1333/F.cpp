#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n;
int prm[maxn], cnt, tag[maxn];
int a[maxn], tot;

int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++){
		if(!tag[i]) prm[++cnt] = i, a[++tot] = 1;
		for(int j = 1;j <= cnt && prm[j] * i <= n;j++){
			tag[prm[j] * i] = 1, a[++tot] = i;
			if(i % prm[j] == 0) break;
		}
	}
	sort(a + 1, a + 1 + tot);
	for(int i = 1;i <= tot;i++) printf("%d ", a[i]);
}