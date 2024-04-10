#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll x0, y0, ax, ay, bx, by, xs, ys, t;
ll x[maxn], y[maxn];
int n;
bool vis[maxn];
int ans;

void dfs(ll X, ll Y, ll Z, int sum){
	ans = max(ans, sum);
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			if(abs(X - x[i]) + abs(Y - y[i]) + Z <= t){
				vis[i] = true;
				dfs(x[i], y[i], abs(X - x[i]) + abs(Y - y[i]) + Z, sum + 1);
				vis[i] = false;
			}
		}
	}
}

int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by, &xs, &ys, &t);
	ll X = x0, Y = y0;
	if(abs(X - xs) + abs(Y - ys) <= t) x[++n] = X, y[n] = Y;
	while(1){
		ll xx = X * ax + bx, yy = Y * ay + by;
		//if(abs(xx - xs) + abs(yy - ys) > t && (xx >= t || yy >= t)) break;
		if(xx > 2e16 || yy > 2e16) break;
		if(abs(xx - xs) + abs(yy - ys) <= t) x[++n] = xx, y[n] = yy;
		X = xx, Y = yy;
		//if(xx >= t || yy >= t) break;
	}
	//dfs(xs, ys, 0, 0);
	for(int i = 1;i <= n;i++){
		ll T = t - abs(x[i] - xs) - abs(y[i] - ys);
		int sum = 1;
		for(int j = i - 1;j;j--){
			T -= abs(x[j + 1] - x[j]) + abs(y[j + 1] - y[j]);
			if(T < 0) break;
			sum++;
			
		}
		if(T > 0 && i < n){
			T -= abs(x[1] - x[i + 1]) + abs(y[1] - y[i + 1]);
			if(T >= 0){
				sum++;
				for(int k = i + 2;k <= n;k++){
					T -= abs(x[k] - x[k - 1]) + abs(y[k] - y[k - 1]);
					if(T < 0) break;
					sum++;
				}
			}
		} 
		ans = max(ans, sum);
	} 
		/*
			if(i < n){
				ll tt = T - abs(x[j] - x[i + 1]);
				int s = sum;
				if(tt >= 0){
					s++;
					for(int k = i + 2;k <= n;k++){
						tt -= abs(x[k] - x[k - 1]) + abs(y[k] - y[k - 1]);
						if(tt < 0) break;
						s++;
					}
				}
				ans = max(ans, s);
			}
		}
	}
	reverse(x + 1, x + 1 + n), reverse(y + 1, y + 1 + n);
	for(int i = 1;i <= n;i++){
		ll T = t - abs(x[i] - xs) - abs(y[i] - ys);
		int sum = 1;
		for(int j = i - 1;j;j--){
			T -= abs(x[j + 1] - x[j]) + abs(y[j + 1] - y[j]);
			if(T < 0) break;
			sum++;
			if(i < n){
				ll tt = T - abs(x[j] - x[i + 1]);
				int s = sum;
				if(tt >= 0){
					s++;
					for(int k = i + 2;k <= n;k++){
						tt -= abs(x[k] - x[k - 1]) + abs(y[k] - y[k - 1]);
						if(tt < 0) break;
						s++;
					}
				}
				ans = max(ans, s);
			}
		}
	}*/
	printf("%d", ans);
}