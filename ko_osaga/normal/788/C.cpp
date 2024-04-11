#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, q, chk[1005];
int dis[2005], vis[2005];

int main(){
	scanf("%d %d",&n,&q);
	while(q--){
		int x;
		scanf("%d",&x);
		chk[x] = 1;
	}
	if(chk[n]){
		puts("1");
		return 0;
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i=0; i<=1000; i++){
		if(chk[i]){
			dis[i - n + 1000] = 1;
		}
	}
	while(1){
		int minv = 1e9, minp = -1e9;
		for(int i=0; i<=2000; i++){
			if(!vis[i] && dis[i] < minv){
				minv = dis[i];
				minp = i;
			}
		}
		if(minp < 0){
			puts("-1");
			return 0;
		}
		if(minp == 1000){
			printf("%d\n", dis[1000]);
			return 0;
		}
		vis[minp] =1;
		for(int i=0; i<=1000; i++){
			if(chk[i] && minp + i - n <= 2000 && minp + i - n >= 0){
				dis[minp + i - n] = min(dis[minp + i - n], dis[minp] + 1);
			}
		}
	}
	puts("-1");
}