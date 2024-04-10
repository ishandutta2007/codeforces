#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

int main(){
	int n, k;
	sd(n); sd(k);
	int cnt = 0;
	int ans = 0;
	for(int i = 1; i <= k; i++){
		int m, first;
		sd(m); sd(first);
		int x, prev = first;
		for(int j = 2; j <= m; j++){
			sd(x);
			if(first == 1){
				if(x == prev + 1) ans += 2;
				else{
					printf("%d", n - 1 + n - k - ans);	
					return 0;				
				}
			}
			prev = x;
		}
	}
	printf("%d", n - 1 + n - k - ans);	
}