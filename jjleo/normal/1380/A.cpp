#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int x = 0;
		for(int i = 2;i < n;i++){
			if(a[i - 1] < a[i] && a[i] > a[i + 1]){
				x = i;
				break;
			}
		}
		if(!x) puts("NO");
		else{
			puts("YES");
			printf("%d %d %d", x - 1, x, x + 1);
			puts(""); 
		}
	}
}