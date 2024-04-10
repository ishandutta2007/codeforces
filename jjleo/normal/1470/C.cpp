#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	int x;
	mt19937 mt(time(0));
	uniform_int_distribution<int> I(1, n);
	for(int j = 1;j <= 500;j++){
		int i = I(mt);
		printf("? %d\n", i);
		fflush(stdout);
		scanf("%d", &x);
		if(x == k - 1){
			x = i;
			break;
		}
		x = 0;
	}
	if(!x){
		int sn = (int)sqrt(n);
		for(int i = 1;i <= n;i += sn){
			printf("? %d\n", i);
			fflush(stdout);
			scanf("%d", &x);
			if(x == k - 1){
				x = i;
				break;
			}
		}
	}
	int l = x, r = l + n / 2, mid;
	while(l < r){
		mid = l + r >> 1;
		printf("? %d\n", mid > n ? mid - n : mid);
		fflush(stdout);
		scanf("%d", &x);
		if(x >= k) r = mid;
		else l = mid + 1;
	} 
	printf("! %d\n", l > n ? l - n : l);
}