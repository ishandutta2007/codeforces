// Hydro submission #6356895a934cfadf848a86c1@1666615643130
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int MAXN = 1e6 + 10;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, M, S;
struct Edge {
    int u, v, nxt;
}E[MAXN];
int head[MAXN], num = 1;
inline void AddEdge(int x, int y) {
    E[num] = (Edge){x, y, head[x]};
    head[x] = num++;
}
stack<int>s;
int dfn[MAXN], low[MAXN], color[MAXN], colornum = 0, tot = 0, vis[MAXN], siz[MAXN];
void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    s.push(x);
    vis[x] = 1;
    for(int i = head[x]; i != -1; i = E[i].nxt) {
        int to = E[i].v;
        if(!dfn[to]) tarjan(to), low[x] = min(low[x], low[to]);
        else if(vis[to]) low[x] = min(low[x], dfn[to]);
    }
    if(dfn[x] == low[x]) {
        int h;
        colornum++;
        do {
            h = s.top(); s.pop();
            color[h] = colornum;
            vis[h] = 0;
        }while(h != x);
    }
}
bool happen[MAXN];
vector<int> v[MAXN];
int ans = 0;
int inder[MAXN];
int main() {
#ifdef WIN32
    //freopen("a.in", "r", stdin);
#endif    
    memset(head, -1, sizeof(head));
    N = read(); M = read(); S = read();
    for(int i = 1; i <= M; i++) {
        int x = read(), y = read();
        AddEdge(x, y);
    }
    for(int i = 1; i <= N; i++) 
        if(!color[i])
            tarjan(i);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= N; i++) 
        for(int j = head[i]; j != -1; j = E[j].nxt) 
            if(color[E[j].u] != color[E[j].v])
                inder[color[E[j].v]]++;
    for(int i = 1; i <= colornum; i++)
        if(inder[i] == 0)
            ans++;
    if(inder[color[S]] == 0) ans--;
    printf("%d", ans);
    return 0;
}