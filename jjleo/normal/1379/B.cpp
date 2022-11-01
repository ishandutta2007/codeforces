#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int l, r;
ll m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%lld", &l, &r, &m);
		for(int i = l;i <= r;i++){
			int x = m % i;
			if(m / i && x <= r - l){
				printf("%d %d %d\n", i, r, r - x);
				break;
			}
			x = (i - x) % i;
			if(x <= r - l){
				printf("%d %d %d\n", i, r - x, r);
				break;
			}
		}
	}
}