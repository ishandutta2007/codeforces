#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		long long ans = 1;
		for(int cnt = 2, i = n + 1;cnt;i++){
			bool tag = false; 
			for(int j = 2;j * j <= i && !tag;j++){
				if(i % j == 0 && j != i) tag = true; 
			}
			if(!tag) cnt--, ans *= i, i += n - 1;
		}
		printf("%lld\n", ans);
	}
}