#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

struct Node{
	int son[2], sum;
}t[maxn << 6];

int cnt;

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1]) 

void add(int x, int l, int r, int pos){
	t[x].sum++;
	if(l == r) return;
	int mid = l + r >> 1, y = ++cnt;
	if(mid >= pos) t[y] = t[ls(x)], add(ls(x) = y, l, mid, pos);
	else t[y] = t[rs(x)], add(rs(x) = y, mid + 1, r, pos);
}

int query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr) return t[x].sum;
	int mid = l + r >> 1, sum = 0;
	if(mid >= ll) sum += query(ls(x), l, mid, ll, rr);
	if(mid < rr) sum += query(rs(x), mid + 1, r, ll, rr);
	return sum;
}

int n, q;
int x, y;

int main(){
	scanf("%d%d", &n, &q), cnt = n;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		int l = -1;
		if(x <= i){
			int r = n - 1, mid, y = i - 1, k = i - x;
			while(l < r){
				mid = l + r >> 1;
				if(t[rs(y)].sum < k) r = mid, k -= t[rs(y)].sum, y = ls(y);
				else l = mid + 1, y = rs(y);
			}
		}
		l = min(l, i - 1);
		//printf("%d %d %d--\n", i, l, query(i - 1, -1, n - 1, 1, n - 1));
		t[i] = t[i - 1];
		add(i, -1, n - 1, l);
	}
	//puts("--");
	while(q--){
		scanf("%d%d", &x, &y);
		printf("%d\n", query(n - y, -1, n - 1, x, n - 1));
	}
}