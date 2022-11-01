#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int d, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &d, &k);
		int x;
		for(int i = 0;i <= d;i += k){
			if(2ll * i * i > 1ll * d * d) break;
			x = i;
		}
		if(1ll * (x + k) * (x + k) + 1ll * x * x > 1ll * d * d) puts("Utkarsh");
		else puts("Ashish");
	}
}