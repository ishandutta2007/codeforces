#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

inline int read(){
	int x = 0, f = 1;char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

struct Node{
	int son[2], siz;
}t[maxn * 150];

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

int cnt;

int T, n, q;
int a[maxn], tot;

int main(){
	T = read();
	while(T--){
		n = read();
		cnt = n;
		for(int i = 1;i <= n;i++){
			int val;
			val = read();
			t[i] = t[i - 1];
			int x = i;
			t[x].siz++;
			for(int j = 29;~j;j--){
				int k = (val & (1 << j)) != 0;
				t[++cnt] = t[t[x].son[k]];
				t[x].son[k] = cnt;
				x = t[x].son[k];
				t[x].siz++;
			}
		}
		q = read();
		while(q--){
			int l, r;
			l = read(), r = read();
			l--;
			int ans = 0;
			tot = 0;
			for(int j = 29;~j;j--){
				int sum = t[ls(r)].siz - t[ls(l)].siz;
				for(int k = 1;k <= tot;k++) sum += (a[k] & (1 << j)) == 0;
				if(sum >= 2){
					int Tot = 0;
					for(int k = 1;k <= tot;k++) if((a[k] & (1 << j)) == 0) a[++Tot] = a[k];
					tot = Tot;
					l = ls(l), r = ls(r);
					continue;
				}
				if(sum == 1){
					if(t[ls(r)].siz - t[ls(l)].siz){
						int val = 0;
						int x = ls(l), y = ls(r);
						for(int k = j - 1;~k;k--){
							if(t[ls(y)].siz - t[ls(x)].siz) x = ls(x), y = ls(y);
							else val += 1 << k, x = rs(x), y = rs(y);
						}
						a[++tot] = val;
					}
					ans += 1 << j;
					l = rs(l), r = rs(r);
					continue;
				}
				ans += 1 << j;
				l = rs(l), r = rs(r);
			}
			printf("%d\n", ans);
		}
	}
}