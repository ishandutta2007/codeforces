#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long LL;

struct Node{
	LL sum;
	int mn, pl;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum;
	t[x].mn = min(t[ls(x)].mn, t[rs(x)].mn);
}

inline void add(int x, int l, int r, int y){
	t[x].pl += y, t[x].mn += y, t[x].sum += 1ll * (r - l + 1) * y;
}

inline void down(int x, int l, int r){
	if(t[x].pl){
		int mid = l + r >> 1;
		add(ls(x), l, mid, t[x].pl), add(rs(x), mid + 1, r, t[x].pl);
		t[x].pl = 0;
	}
}

void modify(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr){
		add(x, l, r, 1);
		return;
	}
	down(x, l, r);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr);
	up(x);
}

int n;
char s[maxn];
LL ans;

int main(){
	scanf("%d%s", &n, s + 1);
	int len = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '1'){
			len++;
			int l = 1, r = n, mid, x = 1;
			while(l < r){
				down(x, l, r);
				mid = l + r >> 1;
				if(t[ls(x)].mn <= len - 1) x = ls(x), r = mid;
				else x = rs(x), l = mid + 1;
			} 
			modify(1, 1, n, l, i);
		}else{
			len = 0;
		}
		ans += t[1].sum;
	}
	printf("%lld", ans);
}