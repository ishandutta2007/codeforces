#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int l = 1, r = n;
		while(l <= r){
			if(l == r) printf("%d ", a[l++]);
			else printf("%d %d ", a[l++], a[r--]);
		}
		puts("");
	}
}