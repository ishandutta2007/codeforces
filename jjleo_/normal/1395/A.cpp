#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int r, g, b, w;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &r, &g, &b, &w);
		if((r & 1) + (g & 1) + (b & 1) + (w & 1) <= 1) puts("Yes");
		else {
			if(r && g && b){
				r--, g--, b--, w++;
				if((r & 1) + (g & 1) + (b & 1) + (w & 1) <= 1) puts("Yes");
				else puts("No");
			}else{
				puts("No");	
			}
		}
	}
}