#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], b[maxn], c[maxn];
int ans[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i < n;i++) scanf("%d", &a[i]);
		for(int i = 0;i < n;i++) scanf("%d", &b[i]);
		for(int i = 0;i < n;i++) scanf("%d", &c[i]);
		for(int i = 0;i < n;i++){
			if(!i) ans[i] = a[i];
			else if(a[i] == ans[i - 1]) ans[i] = b[i];
			else ans[i] = a[i];
			if(i == n - 1){
				if(ans[i] == a[0]){
					if(a[i] != a[0] && a[i] != ans[i - 1]) ans[i] = a[i];
					else if(b[i] != a[0] && b[i] != ans[i - 1]) ans[i] = b[i];
					else ans[i] = c[i];
				}
			}
			printf("%d ", ans[i]);
		}
		puts("");
	}
}