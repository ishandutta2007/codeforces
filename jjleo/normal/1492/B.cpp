#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], p[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			p[i] = p[i - 1];
			if(a[i] > a[p[i]]) p[i] = i;
		}
		for(int i = n;i;i--){
			for(int j = p[i];j <= i;j++) printf("%d ", a[j]);
			i = p[i];
		}
		puts("");
	} 
}