#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];
int f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum ^= a[i];
		if(!sum){
			puts("YES");
			continue;
		}
		f[0] = 1;
		for(int i = 1;i <= n;i++){
			int x = 0;
			f[i] = 0;
			for(int j = i;j;j--){
				if(j == 1 && i == n) continue;
				x ^= a[j];
				if(x == sum) f[i] |= f[j - 1];
			}
		}
		puts(f[n] ? "YES" : "NO");
	} 
}