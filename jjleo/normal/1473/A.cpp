#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, d;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &d);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		puts(a[1] + a[2] <= d || a[n] <= d ? "YES" : "NO");
	} 
}