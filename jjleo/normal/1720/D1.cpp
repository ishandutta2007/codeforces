#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t, n;
int a[maxn];
int f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++){
			f[i] = 1;
			for(int j = max(1, i - 300);j < i;j++){
				if((a[j] ^ (i - 1)) < (a[i] ^ (j - 1))) f[i] = max(f[i], f[j] + 1);
			}
		}
		printf("%d\n", *max_element(f + 1, f + 1 + n));
	}	
}