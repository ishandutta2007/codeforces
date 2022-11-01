#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], b[maxn];


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
		bool tag = false;
		for(int i = 1;i <= n;i++) if(!(a[i] + 1 == b[i] || a[i] == b[i])) tag = true;
		puts(tag ? "NO" : "YES");
	}	
}