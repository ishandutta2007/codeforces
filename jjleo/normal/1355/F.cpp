#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

const int sup = 631;

int t;
int n;

int prm[maxn], cnt;
bool tag[maxn];

inline int query(ll x){
	printf("? %lld\n", x), fflush(stdout);
	int y;
	scanf("%d", &y);
	return y;
}

int main(){
	scanf("%d", &t);
	for(int i = 2;i <= sup;i++){
		if(!tag[i]) prm[++cnt] = i;
		for(int j = 1;j <= cnt && i * prm[j] <= sup;j++){
			tag[i * prm[j]] = true;
			if(i % prm[j] == 0) break;
		}
	}
	while(t--){
		int x = 0, ans = 1;
		int gcd;
		double X = 1e9;
		bool suc = false;
		while(x < cnt){
			ll sum = 1;
			int y = x;
			while(y < cnt && 1.0 * sum * prm[y + 1] <= 1e18){
				sum *= prm[++y];
			}
			gcd = query(sum);
			for(int i = x + 1;i <= y;i++){
				if(gcd % prm[i] == 0){
					ll p = prm[i];
					while(p < 1e9) p *= prm[i];
					int a = query(p), b = 0;
					while(a ^ 1) a /= prm[i], X /= prm[i], b++;
					ans *= b + 1;
				}
			}
			x = y;
			if(1ll * prm[y] * prm[y] * prm[y] > X){//debug: sum y 
				printf("! %d\n", ans << 1), suc = true;
				fflush(stdout);
				break;
			}
		}
		if(suc) continue;
		if(ans <= 2) puts("! 8");
		else printf("! %d\n", X > prm[cnt] * prm[cnt] * prm[cnt] ? (ans << 1) : ans);
		fflush(stdout);
	}
}