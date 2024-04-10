#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n;
ll sum;
int x, y;


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		sum = y = 0;
		while(n--){
			scanf("%d", &x);
			if(!y){
				y = x;
				continue;
			}
			if(1ll * x * y > 0){
				y = max(y, x);
			}else{
				sum += y;
				y = x;
			}
		}
		sum += y;
		printf("%lld\n", sum);
	}
}