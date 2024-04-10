#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = 0;
		int x = 0;
		for(int i = 1;i <= n;i++) x = max(x, ++b[a[i]]);
		if(x > (n + 1) / 2){
			puts("-1"); 
			continue;
		}
		for(int i = 1;i <= n;i++) b[i] = 0;
		x = a[1];
		int k = 0;
		for(int i = 1;i <= n;i++){
			if(i == n || a[i] == a[i + 1]){
				b[x]++, b[a[i]]++;
				x = a[i + 1];
				k++;
			}
		}
		x = 0, k--;
		for(int i = 1;i <= n;i++) x = max(x, b[i]);
		printf("%d\n", k + max(0, x - (k + 2)));
	}
}