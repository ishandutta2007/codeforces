#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n * 2;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n * 2);
		for(int i = 1;i <= n * 2;i++){
			if(i & 1) printf("%d ", a[(i + 1) / 2]);
			else printf("%d ", a[n * 2 + 1 - i / 2]);
		}
		puts("");
	}
}