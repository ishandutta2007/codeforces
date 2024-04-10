#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, l, r;
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &l, &r);
		int a[17] = {0};
		for(int i = l;i <= r;i++){
			scanf("%d", &x);
			for(int j = 0;j < 17;j++){
				if(x & (1 << j)) a[j]++;
				if(i & (1 << j)) a[j]--;
			}
		}
		int x = 0;
		for(int i = 0;i < 17;i++) if(a[i]) x += 1 << i;
		printf("%d\n", x);
	}
}