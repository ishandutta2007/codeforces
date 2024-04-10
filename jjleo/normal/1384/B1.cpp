#include <bits/stdc++.h>

using namespace std;

int t;
int n, k, l, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &k, &l);
		bool suc = true, down = true;
		int x = k;
		for(int i = 1;i <= n;i++){
			scanf("%d", &d);
			if(!suc) continue;
			if(d + k <= l){
				x = k, down = true;
				continue;
			}
			if(d > l){
				suc = false;
				continue;
			}
			if(down){
				x = min(x - 1, l - d);
				if(x == 0) down = false;
			}else{
				x++;
				if(d + x > l){
					suc = false;
					continue;
				}
			}
		}
		puts(suc ? "Yes" : "No");
	}
}