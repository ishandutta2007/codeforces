#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
long long k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int mx = -1e9;
		for(int i = 1;i <= n;i++) mx = max(mx, a[i]);
		for(int i = 1;i <= n;i++) a[i] = mx - a[i];
		if(k % 2 == 0){
			int mx = -1e9;
			for(int i = 1;i <= n;i++) mx = max(mx, a[i]);
			for(int i = 1;i <= n;i++) a[i] = mx - a[i];
		}
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);
		puts("");
	} 
}