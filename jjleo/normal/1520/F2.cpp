#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, t;
int k, x;

int a[maxn];
int cnt;

inline void add(int x, int y){
	for(;x < maxn;x += x & -x) a[x] += y;
}

inline int query(int x){
	int ans = 0;
	for(;x;x -= x & -x) ans += a[x];
	return ans;
}

inline int get(int l, int r){
	cnt++;
	if(cnt > 6e4) while(1);
	printf("? %d %d\n", l, r), fflush(stdout);
	int x;scanf("%d", &x);
	return r - l + 1 - x;
}

const int m = 10;

int main(){
	scanf("%d%d", &n, &t);
	for(int T = 1;T <= t;T++){
		scanf("%d", &k);
		if(T == 1) for(int i = 1;i <= (n + m - 1) / m;i++) add(i, get((i - 1) * m + 1, min(i * m, n)));
		int l = 0, r = (n + m - 1) / m - 1, mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(query(mid) < k) l = mid;
			else r = mid - 1;
		}
		int id = l + 1;
		add(id, -1);
		l = (id - 1) * m, r = min(id * m, n) - 1;
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(get(1, mid) < k) l = mid;
			else r = mid - 1;
		}
		printf("! %d\n", l + 1);
		fflush(stdout);
	}	
}