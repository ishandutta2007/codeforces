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
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		int ans = 0;
		for(int j = 29;~j;j--){
			sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n, greater<int>());
			bool tag = false;
			for(int i = 1;i <= n && !tag;i++) if(!((a[i] ^ b[i]) & (1 << j))) tag = true;
			if(tag){
				for(int i = 1;i <= n;i++) a[i] |= 1 << j, a[i] ^= 1 << j, b[i] |= 1 << j, b[i] ^= 1 << j;
			}else{
				ans += 1 << j;
			}
		}
		printf("%d\n", ans);
	}
}