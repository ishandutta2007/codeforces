#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

int n;
ll a[maxn], b[maxn];
char ans[maxn];
ll cnt, tot;

inline void add(char c, ll x){//debug:xlonglong 
	if(c == 'P') tot += x;
	for(;x && cnt < 5e5;x--){
		ans[++cnt] = c;
	}
	cnt += x;
}

inline void print(){
	if(tot > 2e5){
		printf("BIG\n%lld", tot);
	}else{
		printf("SMALL\n%lld\n", cnt);
		for(int i = cnt;i;i--) printf("%c", ans[i]);
	}
}

void solve(ll x, ll y){
	if(x > y) swap(x, y), add('R', 1);
	if(!x) return;
	if(a[1] == x && y >= a[2] && (y - a[2]) % x == 0){
		add('P', (y - a[2]) / x), print(), exit(0);
	}
	if(a[2] == x && y >= a[1] && (y - a[1]) % x == 0){
		add('P', (y - a[1]) / x), add('R', 1), print(), exit(0);
	}
	add('P', y / x);
	solve(x, y % x);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%lld", &b[i]);
	if(n == 1){
		if(a[1] == b[1]){
			printf("SMALL\n0\n");
		}else{
			printf("IMPOSSIBLE");
		}
		return 0;
	}
	if(n == 2){
		solve(b[1], b[2]);
		printf("IMPOSSIBLE");
		return 0;
	}
	while(1){
		for(int i = 1;i <= n;i++){
			if(a[i] ^ b[i]) break;
			if(i == n) return print(), 0;
		}
		for(int i = 1;i <= n;i++){
			if(a[n + 1 - i] ^ b[i]) break;
			if(i == n) return add('R', 1), print(), 0;
		}
		int x = 0, y = 0;
		for(int i = 2;i <= n;i++){
			if(b[i] > b[i - 1]) x++;
			else if(b[i] < b[i - 1]) y++;
			else return printf("IMPOSSIBLE"), 0;
		}
		if(x && y) return printf("IMPOSSIBLE"), 0;
		if(y) reverse(b + 1, b + 1 + n), add('R', 1);
		add('P', 1);
		for(int i = n;i;i--) b[i] -= b[i - 1];
	}
	
}