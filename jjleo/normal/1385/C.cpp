#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
		}
		int ans = n - 1;
		int x = 0;
		for(int i = n - 1;i;i--){
			if(!x){
				if(a[i] < a[i + 1]){
					x = 1;
				}
			}else{
				if(a[i] > a[i + 1]){
					break;
				}
			}
			ans = i - 1;
		}
		printf("%d\n", ans);
	}
}