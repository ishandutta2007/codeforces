#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int l = k, r = k;
		ll now = a[k];
		while(1){
			if(l == 1 || r == n){
				puts("YES");
				break;
			}
			bool tag = false;
			ll val = 0;
			for(int j = l - 1;j;j--){
				val += a[j];
				if(val + now < 0) break;
				if(val >= 0 || j == 1){
					now += val;
					l = j;
					tag = true;
					break;
				}
			}
			if(tag) continue;
			val = 0;
			for(int j = r + 1;j <= n;j++){
				val += a[j];
				if(val + now < 0) break;
				if(val >= 0 || j == n){
					now += val;
					r = j;
					tag = true;
					break;
				}
			}
			if(tag) continue;
			puts("NO");
			break;
		}
	}
}