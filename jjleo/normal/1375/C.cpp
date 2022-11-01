#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		puts(a[1] < a[n] ? "YES" : "NO");
	}
}