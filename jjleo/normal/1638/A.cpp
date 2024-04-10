#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) if(a[i] ^ i){
			for(int j = 1;j <= n;j++) if(a[j] == i){
				reverse(a + i, a + j + 1);
				break;
			}
			break;
		} 
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("");
	}
}