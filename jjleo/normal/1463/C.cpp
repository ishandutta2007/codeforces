#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int tt;
int n;
ll t[maxn], X[maxn];

int main(){
	scanf("%d", &tt);
	while(tt--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%lld%lld", &t[i], &X[i]);
		ll x = 0, y = 0, T = 0, ans = 0;
		for(int i = 1;i <= n;i++){
			if(t[i] >= T){
				x = y;
				y = X[i];
				T = t[i] + abs(y - x);
				if(i == n || t[i + 1] >= T) ans++;
			}else{
				if(y > x){
					if(y - (T - t[i]) <= X[i] && y >= X[i] && (i == n || y - (T - t[i + 1]) >= X[i])) ans++;
				}else{
					if(y + (T - t[i]) >= X[i] && y <= X[i] && (i == n || y + (T - t[i + 1]) <= X[i])) ans++;
				}
			}
			//printf("%d %d %d %d--\n", x, y, T, ans);
		}
		printf("%lld\n", ans);
	}
}