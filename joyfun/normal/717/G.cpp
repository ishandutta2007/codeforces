#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second


const int inf = 0x3f3f3f3f;
template<class U,class V>
struct ZKW{ // [0,n) , init!! , inf modify
    static const int N = 1010 , M = 1004040;
    int h[N] , ing[N] , v[N] , to[M] , ne[M] , e , s , t , n;
    U cap[M];V dis[N] , cost[M];
    void ini(int _n = N){ fill(h , h + (n=_n) , -1);e = 0;}
    void liu(int u,int v,U c,V w){ to[e] = v;ne[e] = h[u];cap[e] = c;cost[e] = w;h[u] = e++;}
    void link(int u,int v,U c,V w){ liu(u,v,c,w);liu(v,u,0,-w); }
    void spfa(){
        queue<int> Q;
        fill(dis,dis+n,inf);
        ing[t] = true , dis[t] = 0;
        Q.push(t);
        while(!Q.empty()){
            int c = Q.front();Q.pop();ing[c] = false;
            for(int k=h[c];~k;k=ne[k]){
                int v = to[k];
                if(cap[k^1] <= 0) continue;
                if(dis[c] + cost[k^1] < dis[v]){
                    dis[v] = dis[c] + cost[k^1];
                    if(!ing[v]) Q.push(v) , ing[v] = true;
                }
            }
        }
    }
    U flow;V mincost;
    bool modlable(){
        V Min = inf;
        rep(c,0,n) if(v[c])
            for(int k=h[c];~k;k=ne[k]){
                int t=to[k];
                if(!v[t] && cap[k] > 0)
                    Min = min(Min , dis[t] + cost[k] - dis[c]);
            }
        if(Min == inf) return false;
        rep(i,0,n) if(v[i]) dis[i] += Min;
        return true;
    }
    U dfs(int c,U mx){
        if(c == t) return flow += mx , mincost += mx * dis[s] , mx;
        v[c] = true;U ret = 0;
        for(int k=h[c];~k;k=ne[k]){
            int t = to[k];
            if(!v[t] && cap[k] > 0 && dis[c] - cost[k] == dis[t]){
                U tmp = dfs(t , min(cap[k] , mx - ret));
                cap[k] -= tmp , cap[k^1] += tmp;
                ret += tmp;
                if(ret == mx) return ret;
            }
        }
        return ret;
    }
    pair<U,V> run(int _s,int _t){
        s = _s , t = _t;
        spfa();
        flow = mincost = 0;
        do do memset(v,0,sizeof(v[0])*n);
            while(dfs(s,inf));
        while(modlable());
        return make_pair(flow , mincost);
    }
};
ZKW<int, int> gao;

const int N = 505;
int n, m;
char a[N], b[N];

int jump[N];

int main() {
	scanf("%d", &n);
	scanf("%s", a + 1);
	scanf("%d", &m);
	int p;
	gao.ini(n + 2);
	while (m--) {
		scanf("%s%d", b + 1, &p);
		int len = strlen(b + 1);
		int j = 0;
		for (int i = 2; i <= len; i++) {
			while (j && b[i] != b[j + 1]) j = jump[j];
			if (b[i] == b[j + 1]) j++;
			jump[i] = j;
		}
		j = 0;
		for (int i = 1; i <= n; i++) {
			while (j && a[i] != b[j + 1]) j = jump[j];
			if (a[i] == b[j + 1]) j++;
			if (j == len) {
				gao.link(i - len + 1, i + 1, 1, -p);
				j = jump[j];
			}
		}
	}
	int x;
	scanf("%d", &x);
	for (int i = 0; i <= n; i++) gao.link(i, i + 1, x, 0);
	printf("%d\n", -gao.run(0, n + 1).second);
	return 0;
}