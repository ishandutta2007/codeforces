#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

int t;
int n;
int x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int j = 1;j <= 100;j++) printf("%c", a[j] + 'a');
		puts("");
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			for(int j = 1;j <= 100;j++){
				if(j > x) a[j] ^= 1;
				printf("%c", a[j] + 'a');
			}
			puts("");
		} 
	}
}