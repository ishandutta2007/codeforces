#include <bits/stdc++.h>
#define maxn 1000005 
#define maxm 500086
#define eps 1e-8
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const double pi = acos(-1);

using namespace std;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int n, m, w, q;
struct p{
	int u, v, nxt;
}e[200005];
int inde[50005], tot, c[50005];
vector<int> k[50005], P[50005];
void add(int u, int v){e[++tot] = p{u, v, inde[u]}, inde[u] = tot;}
int que[50005], h, t, dis[50005];
ll vis[50005], cnt;
struct sss{
	int p, k, dis;
	bool operator < (const sss & a)const{
		return p < a.p;
	}
}sp[500005];
int sp2;
void bfs(int u){
	sp2 = 0;
	int i, v;
	cnt++;
	que[h = t = 1] = u, dis[u] = 0;
	vis[u] = cnt;
	while(h <= t){
		u = que[h++];
		if(k[u].size()) {
			for(i = 0;i < k[u].size();i++) sp[++sp2] = sss{P[u][i], k[u][i], dis[u]};
		}
		for(i = inde[u];i;i = e[i].nxt){
			v = e[i].v;
			if(vis[v] == cnt) continue;
			dis[v] = dis[u] + 1, que[++t] = v, vis[v] = cnt;
		}
	}
	return ;
}
bool check(int R, int a, int T){
	int i;
	ll sum = 0;
	int now = 0;
	for(i = 1;i <= sp2;i++){
		if(sp[i].dis > T) continue;
		sum += 1ll * sp[i].p * min(sp[i].k, R - now);
		now += min(sp[i].k, R - now);
		if(now == R) break;
		if(sum > a) return 0;
	}
	if(now < R) return 0;
	if(sum > a) return 0;
	return 1;
}
int main(){
	int i, j, u, v, x, R, a;
	n = read(), m = read();
	for(i = 1;i <= m;i++) u = read(), v = read(), add(u, v), add(v, u);
	w = read(); 
	for(i = 1;i <= w;i++){
		u = read(), v = read(), x = read();
		k[u].push_back(v), P[u].push_back(x);
	}
	q = read();
	int l, r, mid, ans;
	while(q--){
		u = read(), R = read(), a = read();
		bfs(u);
		sort(sp + 1, sp + sp2 + 1);
		l = 0, r = 10000, ans = -1;
		while(l <= r){
			mid = l + r >> 1;
			if(check(R, a, mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n",ans);
	}
}
/*
6 4
4 2
5 4
1 2
3 2
2
4 1 2
3 2 3
4
3 1 2
4 3 8
5 2 5
6 1 10
*/