#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()


static const int inf = 0x3f3f3f3f;
template<class T>
struct MCMF{ // [0,n) , init!! , inf modify
    static const int N = 101010 , M = N * 10;
    int h[N] , ing[N] , pre[N] , to[M] , ne[M] , cost[M] , e , s , t , n;
    T dis[N] , cap[M];
    void ini(int _n){ fill(h , h + (n=_n) , -1);e = 0;}
    void liu(int u,int v,int c,int w){ to[e] = v;ne[e] = h[u];cap[e] = c;cost[e] = w;h[u] = e++;}
    void link(int u,int v,int c,int w){ liu(u,v,c,w);liu(v,u,0,-w); }
    bool spfa(){
        queue<int> Q;
        fill(ing , ing + n , 0);
        fill(pre , pre + n , -1);
        fill(dis , dis + n , inf);
        ing[s] = true , dis[s] = 0;
        Q.push(s);
        while(!Q.empty()){
            int c = Q.front();Q.pop();ing[c] = false;
            for(int k=h[c];~k;k=ne[k]){
                int v = to[k];
                if(cap[k] <= 0) continue;
                if(dis[c] + cost[k] < dis[v]){
                    dis[v] = dis[c] + cost[k];
                    pre[v] = k;
                    if(!ing[v]) Q.push(v) , ing[v] = true;
                }
            }
        }
        return dis[t] != inf;
    }
    int flow;T mincost;
    pair<int,T> run(int _s,int _t){
        s = _s , t = _t;
        flow = mincost = 0;
        while(spfa()){
            T pl = inf;int p , k;
            for(p=t;p!=s;p=to[k^1]) pl = min(pl , cap[k=pre[p]]);
            for(p=t;p!=s;p=to[k^1]){
                k = pre[p];
                cap[k] -= pl;
                cap[k^1] += pl;
            }
            mincost += pl * dis[t];
            flow += pl;
        }
        return make_pair(flow , mincost);
    }
};

MCMF<int> gao;

const int N = 105;
char s[N], T[N];
int c1[26], c2[26], cc[26];

int main() {
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++) c1[s[i] - 'a']++;
	int tot = len;
	int m;
	scanf("%d", &m);
	int s = 0, t = m + 26 + 1;
	gao.ini(t + 1);
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		int w;
		scanf("%s%d", T + 1, &w);
		gao.link(s, i, w, i);
		int len = strlen(T + 1);
		sum += i * len;
		memset(c2, 0, sizeof(c2));
		for (int j = 1; j <= len; j++) c2[T[j] - 'a']++, cc[T[j] - 'a']++;
		for (int j = 0; j < 26; j++) if (c2[j])
			gao.link(i, m + j + 1, c2[j], 0);
	}
	for (int i = 0; i < 26; i++) {
		if (cc[i] < c1[i]) {
			printf("-1\n");
			return 0;
		}
		if (c1[i])
			gao.link(m + i + 1, t, c1[i], 0);
	}
	pii tmp = gao.run(s, t);
	if (tmp.fi != tot) printf("-1\n");
	else printf("%d\n", tmp.se);
	return 0;
}