#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = a[i];
		sort(a + 1, a + 1 + n);
		bool tag = false;
		for(int i = 1;i <= n;i++) tag |= a[i] != b[i];
		puts(tag ? "YES" : "NO"); 
	}
}