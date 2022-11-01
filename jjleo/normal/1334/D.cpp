#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
ll l, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld%lld", &n, &l, &r);
		ll cnt = 0;
		int j = 2 * (n - 1);
		
		for(int i = 1;i < n;i++, j -= 2){
			if((cnt + 1 <= l && l <= cnt + j) || (cnt + 1 <= r && r <= cnt + j) || (l <= cnt + 1 && cnt + j <= r)){
				int a = 1, b = i;
				for(ll k = cnt + 1;k <= cnt + j;k++, a ^= 1){
					if(!a) ++b;
					if(l <= k && k <= r){
						printf("%d ", a ? i : b);
					}
				}
			}
			cnt += j;
		}
		++cnt;
		if(r == cnt) printf("1");
		puts("");
	}
}