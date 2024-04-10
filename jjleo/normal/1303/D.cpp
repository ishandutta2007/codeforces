#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll n;
int m, x;
ll sum;
int num[100];
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%d", &n, &m);
		memset(num, 0, sizeof(num));
		sum = 0;
		while(m--){
			scanf("%d", &x);
			sum += x;
			int y = -1;
			while(x) x >>= 1, y++;
			++num[y];
			//printf("%d--\n", y);
		}
		if(sum < n){
			puts("-1");
			continue;
		}
		ans = 0;
		int y = 0;
		while(n){
			if(n & 1){
				if(!num[y]){
					for(int i = y + 1;;i++){
						ans++;
						if(num[i]){
							num[i]--;
							break;
						}
						num[i] = 1;
					}
					num[y] = 1;
				}else{
					num[y]--;
				}
			}
			num[y + 1] += num[y] >> 1;
			y++, n >>= 1;
		}
		printf("%d\n", ans); 
	}
}