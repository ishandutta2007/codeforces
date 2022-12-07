#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
int a[maxn], b[maxn];
int ans;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
	for(int i = 1 << 8;i;i >>= 1){
		bool tag = false;
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= m;k++){
				if(((a[j] & b[k]) & (ans ^ ((1 << 9) - 1))) >= i){
					if(k == m) tag = true;
				}else{
					break;
				}
			}
			if(tag) break;
		}
		if(tag) ans += i;
	}
	printf("%d", ans);
}