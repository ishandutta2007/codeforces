#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int t, x, y;
int sum[2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		sum[0] = sum[1] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &y), sum[y & 1]++;
		bool suc = false;
		for(int i = 1;i <= x;i += 2) if(sum[1] >= i && sum[0] >= x - i){
			suc = true;
			break;
		}
		if(!suc) puts("NO");
		else puts("YES");
	}
}