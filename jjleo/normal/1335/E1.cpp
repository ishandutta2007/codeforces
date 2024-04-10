#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int tot[205], cnt[205];
int num[maxn];
int a[maxn];
int mx, ans, sum;

inline void remove(int i){
	num[cnt[i]]--;
	num[--cnt[i]]++;
	if(!num[mx]) mx--;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(tot, 0, sizeof(tot));
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), ++tot[a[i]];
		ans = 0;	
		for(int k = 1;k <= 200;k++){
			memcpy(cnt, tot, sizeof(tot));
			sum = mx = 0;
			for(int i = 1;i <= n;i++) num[i] = 0;
			for(int i = 1;i <= 200;i++) num[cnt[i]]++, mx = max(mx, cnt[i]);
			ans = max(ans, mx);
			for(int i = 1, j = n;i < j;i++, j--){
				while(a[i] != k && i < j) remove(a[i++]);
				while(a[j] != k && i < j) remove(a[j--]);
				if(i >= j) break;
				sum += 2;
				remove(a[i]), remove(a[j]);
				//printf("%d %d %d %d--\n", k, sum, mx, num[mx]);
				ans = max(ans, sum + mx);
			}
		}
		printf("%d\n", ans); 
	}
}