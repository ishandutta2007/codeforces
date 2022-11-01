#include <bits/stdc++.h>
#define maxn 5000086

using namespace std;

int t, h, g;
int sup;
int a[maxn], siz[maxn];
int ans[maxn], cnt;
long long sum;

bool check(int x){
	if(!a[x << 1] && !a[x << 1 | 1]) return siz[x] == 1;
	return check(a[x << 1] > a[x << 1 | 1] ? (x << 1) : (x << 1 | 1));
}

void erase(int x){
	siz[x]--;
	if(!a[x << 1] && !a[x << 1 | 1]){
		a[x] = 0;
		return;
	}
	a[x] = a[x << 1] > a[x << 1 | 1] ? a[x << 1] : a[x << 1 | 1];
	erase(a[x << 1] > a[x << 1 | 1] ? (x << 1) : (x << 1 | 1));
}


void dfs(int x){
	while(1){
		if(check(x)){
			sum -= a[x], ans[++cnt] = x, erase(x);
		}else{
			if(!a[x << 1] && !a[x << 1 | 1]) return;
			if(a[x << 1] > a[x << 1 | 1]){
				if(check(x << 1)){
					sum -= a[x << 1], ans[++cnt] = x << 1, erase(x << 1);
				}else{
					break;
				}
			}else{
				if(check(x << 1 | 1)){
					sum -= a[x << 1 | 1], ans[++cnt] = x << 1 | 1, erase(x << 1 | 1);
				}else{
					break;
				}
			}
		}
	}
	if(siz[x << 1]) dfs(x << 1);
	if(siz[x << 1 | 1]) dfs(x << 1 | 1);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &h, &g);
		cnt = sum = 0;
		sup = (1 << h) - 1;
		for(int i = 1;i <= sup;i++){
			scanf("%d", &a[i]), sum += a[i];
			siz[i] = i > (1 << g) - 1;//debug:  
		}
		for(int i = sup;i > 1;i--) siz[i >> 1] += siz[i];
		sup = (1 << (h + 2)) - 1;
		for(int i = 1 << h;i <= sup;i++) a[i] = siz[i] = 0;
		dfs(1);
		/*for(int i = 1;i < (1 << g);i++){
			if(!a[i]){
				printf("%d-----\n", i);
				return 0;
			}
		}*/
		printf("%lld\n", sum);
		for(int i = 1;i <= cnt;i++) printf("%d ", ans[i]);
		puts("");
	}
}