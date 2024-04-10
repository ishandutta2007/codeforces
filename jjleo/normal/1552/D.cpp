#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, a[maxn];
int sum[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		bool tag = false;
		for(int i = 0;i < n;i++) scanf("%d", &a[i]), tag |= a[i] == 0;
		if(tag){
			puts("YES");
			continue;
		}
		for(int i = 0;i < (1 << n);i++){
			sum[i] = 0;
			for(int j = 0;j < n;j++) if(i & (1 << j)) sum[i] += a[j];
		}
		for(int i = 0;i < (1 << n) && !tag;i++){
			for(int j = 0;j < (1 << n) && !tag;j++){
				if(!(i & j) && sum[i] == sum[j] && (i | j)) tag = true;
			}
		}
		puts(tag ? "YES" : "NO");
	}
}