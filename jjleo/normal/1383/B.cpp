#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int t;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		bool tag = false;
		for(int i = 1 << 30;i;i >>= 1){
			int cnt = 0;
			for(int j = 1;j <= n;j++) if(a[j] & i) cnt++;
			//printf("%d %d--\n", i, cnt);
			if(cnt & 1){
				//if(cnt == 1 || ((n & 1) && (cnt - 1) % 4 == 0) || (!(n & 1) && (cnt - 1) % 4 != 0)) puts("WIN");
				if((cnt - 1) % 4 == 0 || ((cnt - 1) % 4 != 0 && !(n & 1))) puts("WIN");
				else puts("LOSE");
				tag = true;
				break;
			}
		}
		if(!tag) puts("DRAW");
	} 
}