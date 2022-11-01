#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		for(int i = 1;i <= n * 2;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n * 2);
		bool tag = false;
		for(int i = 1;i <= n;i++) if(a[i] + x > a[i + n]) tag = true;
		puts(tag ? "NO" : "YES");
	}
}