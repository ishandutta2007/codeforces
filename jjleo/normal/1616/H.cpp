#include <bits/stdc++.h>
#define maxn 150086

using namespace std;

const int p = 998244353;

struct Node{
	int son[2], siz;
}t[maxn * 30];

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

int n, m, x;
int cnt = 1;
int pw[maxn];

int g(int x, int y, int bit){
	if(!x || !y) return 0;
	if(bit == -1) return 1ll * (pw[t[x].siz] + p - 1) * (pw[t[y].siz] + p - 1) % p;
	if(m & (1 << bit)){
		int a = g(ls(x), rs(y), bit - 1), b = g(rs(x), ls(y), bit - 1);
		int ans = 1ll * a * b % p;
		ans = (ans + a * (1ll * pw[t[rs(x)].siz] + pw[t[ls(y)].siz] + p - 1)) % p;
		ans = (ans + b * (1ll * pw[t[ls(x)].siz] + pw[t[rs(y)].siz] + p - 1)) % p;
		ans = (ans + 1ll * (pw[t[ls(x)].siz] + p - 1) * (pw[t[ls(y)].siz] + p - 1)) % p;
		ans = (ans + 1ll * (pw[t[rs(x)].siz] + p - 1) * (pw[t[rs(y)].siz] + p - 1)) % p;
		return ans;
	}
	return (g(ls(x), ls(y), bit - 1) + g(rs(x), rs(y), bit - 1)) % p;
}

int f(int x, int bit){
	if(!x) return 0;
	if(bit == -1) return (pw[t[x].siz] + p - 1) % p;
	if(m & (1 << bit)) return (1ll * g(ls(x), rs(x), bit - 1) + pw[t[ls(x)].siz] + p - 1 + pw[t[rs(x)].siz] + p - 1) % p;
	return (f(ls(x), bit - 1) + f(rs(x), bit - 1)) % p;
}

int main(){
	scanf("%d%d", &n, &m);
	t[1].siz = n; 
	pw[0] = 1;for(int i = 1;i <= n;i++) pw[i] = (pw[i - 1] + pw[i - 1]) % p;
	while(n--){
		scanf("%d", &x);
		int now = 1;
		for(int i = 29;~i;i--){
			int k = (x & (1 << i)) != 0;
			if(!t[now].son[k]) t[now].son[k] = ++cnt;
			now = t[now].son[k], t[now].siz++;
		}
	}
	printf("%d", f(1, 29));
}