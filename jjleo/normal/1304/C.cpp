#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;

struct Node{
	int t, l, r;
}a[maxn];

inline bool cmp(Node x, Node y){
	return x.t < y.t;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%d%d%d", &a[i].t, &a[i].l, &a[i].r);
		sort(a + 1, a + 1 + n, cmp);
		long long l = m, r = m;
		for(int i = 1;i <= n;i++){
			l -= a[i].t - a[i - 1].t, r += a[i].t - a[i - 1].t;
			if(r < a[i].l || a[i].r < l){
				puts("NO");
				break;
			}
			l = max(l, (long long)a[i].l), r = min(r, (long long)a[i].r);
			if(i == n) puts("YES");
		}
	}
}