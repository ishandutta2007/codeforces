#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

struct Node{
	int sum, tag;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = min(t[ls(x)].sum, t[rs(x)].sum);
} 

inline void add(int x, int y){
	t[x].sum += y, t[x].tag += y;
}

inline void down(int x){
	if(t[x].tag){
		add(ls(x), t[x].tag), add(rs(x), t[x].tag);
		t[x].tag = 0;
	}
}

void modify(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr){
		add(x, -1);
		return;
	}
	down(x);
	int mid = l + r >> 1;
	if(mid >= ll) modify(ls(x), l, mid, ll, rr);
	if(mid < rr) modify(rs(x), mid + 1, r, ll, rr);
	up(x);
}

void build(int x, int l, int r){
	t[x].tag = 0;
	if(l == r){
		t[x].sum = l;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	up(x);
}

int T;
int n;
int a[maxn], b[maxn];
int l[maxn], r[maxn];
int nxt[maxn], id[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = b[i - 1] + (a[i] == 0);
		for(int i = 1;i <= n;i++) l[i] = r[i] = 0;
		int x = 0;
		for(int i = 1;i <= n;i++){
			if(!a[i]){
				if(b[i] > b[n] - b[i]){
					if(!x) x = i;
				}
			}else{
				if(b[i] > b[n] - b[i]){
					if(!r[a[i]]) r[a[i]] = i; 
				}else l[a[i]] = i;
			}
		}
		int sum = 0;
		for(int i = 1;i <= n;i++) if(l[i] || r[i]) sum++;
		if(!x || !sum){
			puts("0");
			continue;
		}
		nxt[n + 1] = 0;
		for(int i = n;i;i--){
			if(a[i]) nxt[i] = nxt[i + 1];
			else nxt[i] = i;
		}
		int cnt = 0;
		for(int i = n;i >= x;i--){
			if(!a[i]) id[i] = ++cnt;
		}
		build(1, 0, cnt);
		for(int i = n;i >= x;i--){//debug:0  0 
			if(a[i] && r[a[i]] == i && !l[a[i]]) modify(1, 0, cnt, id[nxt[i]], cnt);
		}
		int ans = min(b[n] / 2, sum + t[1].sum);
		for(int i = 1;i < x;i++){
			if(!a[i]) sum++;
			else if(l[a[i]] == i){
				if(r[a[i]]){
					modify(1, 0, cnt, id[nxt[r[a[i]]]], cnt);//debug:0  0 
				}else sum--;
			}
			ans = min(ans, sum + t[1].sum);
		}
		printf("%d\n", ans);
	}
}