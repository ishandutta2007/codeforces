#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;

inline int check(int h, int w, int i1, int j1, int i2, int j2){
	printf("? %d %d %d %d %d %d\n", h, w, i1, j1, i2, j2), fflush(stdout);
	int x;
	scanf("%d", &x);
	return x; 
}

int main(){
	scanf("%d%d", &n, &m);
	int x = n, k = n, ans = 1;
	for(int i = 2;i <= n;i++){
		int cnt = 1;
		while(x % i == 0){
			if(i == 2){
				if(check(k / 2, m, 1, 1, 1 + k / 2, 1)) k /= 2, cnt++;
			}else{
				if(check(k / i * (i / 2), m, 1, 1, 1 + k / i * (i / 2), 1) && check(k / i * (i / 2), m, 1, 1, 1 + k / i * (i / 2 + 1), 1)) k /= i, cnt++;
			}
			x /= i;
		}
		ans *= cnt;
	}
	x = k = m;
	for(int i = 2;i <= m;i++){
		int cnt = 1;
		while(x % i == 0){
			if(i == 2){
				if(check(n, k / 2, 1, 1, 1, 1 + k / 2)) k /= 2, cnt++;
			}else{
				if(check(n, k / i * (i / 2), 1, 1, 1, 1 + k / i * (i / 2)) && check(n, k / i * (i / 2), 1, 1, 1, 1 + k / i * (i / 2 + 1))) k /= i, cnt++;
			}
			x /= i;
		}
		ans *= cnt;
	}
	printf("! %d\n", ans);
}