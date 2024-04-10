#include <bits/stdc++.h>
#define maxn 3000

using namespace std;

int t;
int n, k;
char s[maxn];
int a[30];

inline bool check(int x, int y){
	memset(a, 0, sizeof(a));
	for(int i = 1;i <= n;i++) a[s[i] - 'a']++;
	while(x--){
		int id = 0;
		for(int i = 1;i < 26;i++){
			if(a[i] > a[id]) id = i;
		}
		if(a[id] < y) return false;
		a[id] -= y;
	}
	return true;
		
}

int main(){
	scanf("%d", &t);
	while(t--){
		int ans = 0;
		scanf("%d%d", &n, &k);
		scanf("%s", s + 1);
		for(int i = 1;i <= k;i++){
			if(k % i == 0){
				int l = 0, r = n / i, mid;
				while(l < r){
					mid = (l + r >> 1) + 1;
					if(check(i, mid)) l = mid;
					else r = mid - 1;
				}
				//printf("%d %d--\n", i, l);
				ans = max(ans, l * i);
			}
		}
		printf("%d\n", ans);
	}
}