#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int l = a[1] + 1, r = a[1] + 1;
		bool tag = false;
		for(int i = 2;i <= n && !tag;i++){
			l -= k - 1, r += k - 1;
			l = max(l, a[i] + 1), r = min(r, a[i] + k);
			//printf("%d %d %d--\n", i, l, r);
			if(l > r) tag = true;
		}
		if(!(l <= a[n] + 1 && a[n] + 1 <= r)) tag = true;
		puts(tag ? "No" : "Yes");
	}
}