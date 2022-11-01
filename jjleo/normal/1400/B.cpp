#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int p, f, cnts, cntw, s, w;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d%d", &p, &f, &cnts, &cntw, &s, &w);
		if(s > w) swap(s, w), swap(cnts, cntw);
		int ans = 0;
		for(int i = 0;i <= cnts;i++){
			if(1ll * i * s > p) break;
			int sum = i;
			int j = min(cntw, (p - i * s) / w);
			sum += j;
			ans = max(ans, sum + min(cnts - i, f / s) + min(cntw - j, (f - min(cnts - i, f / s) * s) / w));
		}
		printf("%d\n", ans);
	}	
}