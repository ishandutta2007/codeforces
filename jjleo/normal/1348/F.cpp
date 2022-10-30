#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

struct Node{
	int sum, id;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	t[x].sum = max(t[ls(x)].sum, t[rs(x)].sum);
	t[x].id = t[x].sum == t[rs(x)].sum ? t[rs(x)].id : t[ls(x)].id;
}

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		t[x].sum = d, t[x].id = l;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x); 
}

Node query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x];
	int mid = l + r >> 1;
	if(mid < ll) return query(rs(x), mid + 1, r, ll, rr);
	if(mid >= rr) return query(ls(x), l, mid, ll, rr);
	Node L = query(ls(x), l, mid, ll, rr), R = query(rs(x), mid + 1, r, ll, rr);
	return (Node){max(L.sum, R.sum), R.sum >= L.sum ? R.id : L.id};
}


int n;
struct f{
	int l, r, i;
	
	inline friend bool operator < (f x, f y){
		return x.r ^ y.r ? x.r < y.r : x.l > y.l;
	}
}a[maxn];

inline bool cmp(f x, f y){
	return x.l < y.l;
}

multiset<f> st;//debug: multiset 

int ans[maxn], rnk[maxn];
bool suc;
int X, Y;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d", &a[i].l, &a[i].r), a[i].i = i;
	sort(a + 1, a + 1 + n, cmp);
	int x = 0;
	for(int i = 1;i <= n;i++){
		while(x + 1 <= n && a[x + 1].l <= i) st.insert(a[++x]);
		f b = *st.begin();
		//printf("%d %d %d--\n", b.l, b.r, b.i);
		st.erase(st.begin());
		ans[b.i] = i, rnk[i] = b.i;
		if(!suc){
			Node node = query(1, 1, n, b.l, i);
			if(node.sum >= i){
				suc = true, X = i, Y = node.id;
			}else{
				modify(1, 1, n, i, b.r);
			}
		}
	}
	if(suc){
		puts("NO");
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);puts("");
		swap(ans[rnk[X]], ans[rnk[Y]]);
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
	}else{
		puts("YES");
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
	}
}