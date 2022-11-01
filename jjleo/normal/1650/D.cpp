#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], b[maxn];
int ans[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = n;i;i--){
			int pos;
			for(int j = 1;j <= i;j++) if(a[j] == i) pos = j;
			ans[i] = 0;
			if(pos < i){
				ans[i] = pos;
				int cnt = 0;
				for(int j = pos + 1;j <= i;j++) b[++cnt] = a[j];
				for(int j = 1;j < pos;j++) b[++cnt] = a[j];
				for(int j = 1;j < i;j++) a[j] = b[j]; 
			}
		}
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
		puts("");
	}
}