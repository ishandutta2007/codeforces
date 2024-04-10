#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int x, a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x]++;
		for(int i = 0;;i++){
			if(!a[i]) break;
			a[i]--;
			printf("%d ", i); 
		}
		for(int i = 0;i <= 100;i++){
			for(int j = 1;j <= a[i];j++) printf("%d ", i);
			a[i] = 0;
		}
		puts("");
	}
}