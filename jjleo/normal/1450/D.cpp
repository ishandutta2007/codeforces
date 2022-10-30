#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int n;
int a[maxn], b[maxn], ans[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) b[i] = ans[i] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[a[i]]++;
		for(int i = 1;i <= n;i++){
			if(b[i] ^ 1) break;
			if(i == n) ans[n] = 1;
		}
		int l = 1, r = n;
		for(int i = 1;i <= n;i++){
			if(!b[i]) break;
			ans[i] = true;
			if(a[l] == i){
				b[a[l++]]--;
			}else if(a[r] == i){
				b[a[r--]]--;
			}else{
				break;
			}
			if(b[i]) break;
		}
		for(int i = n;i;i--) printf("%d", ans[i]);
		puts("");
	}
}