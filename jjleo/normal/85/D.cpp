#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

typedef long long ll;

struct Node{
	ll sum[5];
	int siz;
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline void up(int x){
	for(int i = 0;i < 5;i++) t[x].sum[i] = t[ls(x)].sum[i] + t[rs(x)].sum[(i + 5 - t[ls(x)].siz % 5) % 5];
	t[x].siz = t[ls(x)].siz + t[rs(x)].siz;
} 

int a[maxn];

void modify(int x, int l, int r, int pos, int d){
	if(l == r){
		t[x].sum[0] += a[l] * d;
		t[x].siz += d;
		return;
	}
	int mid = l + r >> 1;
	if(mid >= pos) modify(ls(x), l, mid, pos, d);
	else modify(rs(x), mid + 1, r, pos, d);
	up(x);
}

char s[5];
int n, n0;
int q[maxn][2];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%s", s);
		switch(s[0]){
			case 'a':
				q[i][0] = 1, scanf("%d", &q[i][1]), a[++n0] = q[i][1];
				break;
			case 'd':
				q[i][0] = 2, scanf("%d", &q[i][1]), a[++n0] = q[i][1];
				break;	
			case 's':
				q[i][0] = 3;
				break;	
		}
	}
	sort(a + 1, a + 1 + n0);
	n0 = unique(a + 1, a + 1 + n0) - (a + 1);
	for(int i = 1;i <= n;i++){
		switch(q[i][0]){
			case 1:
				modify(1, 1, n0, lower_bound(a + 1, a + 1 + n0, q[i][1]) - a, 1);
				break;
			case 2:
				modify(1, 1, n0, lower_bound(a + 1, a + 1 + n0, q[i][1]) - a, -1);
				break;	
			case 3:
				printf("%lld\n", t[1].sum[2]);//debug:1 1 
				break;	
		}
	}
}