#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

struct Node{
	int sum, pl;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = max(t[ls(x)].sum, t[rs(x)].sum);
} 

inline void add(int x, int y){
	t[x].sum += y ,t[x].pl += y;
}

inline void down(int x){
	if(t[x].pl){
		add(ls(x), t[x].pl);
		add(rs(x), t[x].pl);
		t[x].pl = 0;
	}
}

void modify(int x, int l, int r, int ll, int rr, int d){
	if(ll <= l && r <= rr){
		add(x, d);
		return;
	}
	down(x);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr, d);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr, d);
	up(x);
}

int n;
int x, q[maxn], pos[maxn];
int ans;

// i-nx -  

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &x), pos[x] = i;
	for(int i = 1;i <= n;i++) scanf("%d", &q[i]);
	ans = n;
	modify(1, 1, n, 1, pos[n], 1);
	printf("%d", ans);
	for(int i = 1;i < n;i++){
		modify(1, 1, n, 1, q[i], -1);//debug:1q[i] 
		while(t[1].sum <= 0) modify(1, 1, n, 1, pos[--ans], 1);
		printf(" %d", ans);
	}
}