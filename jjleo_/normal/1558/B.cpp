#include <bits/stdc++.h>
#define maxn 4000086

using namespace std;

int n, p;
int a[maxn];

inline void add(int x, int y){
	for(;x <= n;x += x & -x){
		a[x] += y;
		if(a[x] >= p) a[x] -= p;
	}
}

inline int query(int x){
	int ans = 0;
	for(;x;x -= x & -x){
		ans += a[x];
		if(ans >= p) ans -= p;
	}
	return ans;
}

int main(){
	scanf("%d%d", &n, &p);
	//n = 4e6, p = 998244353;
	int sum = 1;
	add(n, 1);
	for(int i = n - 1;i;i--){
		int val = sum;
		for(int j = 2, k = i + i;k <= n;j++, k += i){
			val += query(min(n, k + j - 1));
			if(val >= p) val -= p;
			val += p - query(k - 1);
			if(val >= p) val -= p;
		}
		if(i == 1) return printf("%d", val), 0;
		sum += val;
		if(sum >= p) sum -= p;
		add(i, val);
		//printf("%d %d--\n", i, val);
	}
}