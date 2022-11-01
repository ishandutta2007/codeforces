#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i < n;i++){
			int cnt = min(a[i], k);
			k -= cnt;
			a[i] -= cnt;
			a[n] += cnt;
			if(!k) break;
		}
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts(""); 
	}
}