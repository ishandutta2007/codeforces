#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int ans = 0, x = 0, y = 0;
		for(int i = 2;i <= n;i++){
			if(i == 2){
				ans++, y++;
				continue;
			}
			if(a[i] < a[i - 1]){
				if(x) x--, y++;
				else ans++, x = y - 1, y = 1;
			}else{
				y++;
			}
		}
		printf("%d\n", ans);
	}
}