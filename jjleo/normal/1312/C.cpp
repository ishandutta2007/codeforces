#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n, k;
bool a[100], suc;
ll x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		memset(a, 0, sizeof(a)), suc = true;
		for(int i = 1;i <= n;i++){
			scanf("%lld", &x);
			if(!suc) continue;
			int y = 0;
			while(x){
				if(x % k){
					if(x % k != 1 || a[y]){
						suc = false;
						break;
					}else{
						a[y] = true;
					}
				}
				x /= k;
				y++;
			}
		}
		puts(suc ? "YES" : "NO");
	}
}