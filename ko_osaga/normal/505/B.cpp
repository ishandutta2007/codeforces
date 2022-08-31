#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

vector<int> graph[100005];
set<int> room;
vector<int> cls[100005];
struct edge{int s,e,c;}a[100005];
bool cmp(edge a, edge b){return a.c < b.c;}
bool cmp2(int a, int b){return cls[a].size() > cls[b].size();}

int sz,n,m;
int qnum[100005], renum[100005];

void dfs(int x, int piv){
    if(room.find(x) != room.end()) return;
    cls[x].push_back(piv);
    room.insert(x);
    for (int i=0; i<graph[x].size(); i++) {
        dfs(graph[x][i],piv);
    }
}

int dp[400][400];

int query(int s, int e){
    int ns = renum[s]; // ?
    int ne = renum[e]; // ?
    if(ns > ne) swap(ns,ne), swap(s,e);
    if(ne < 400 && ~dp[ns][ne]) return dp[ns][ne];
    int cnt = 0;
    for (int i=0; i<cls[e].size(); i++) {
        vector<int> ::iterator it =lower_bound(cls[s].begin(),cls[s].end(),cls[e][i]);
        if(it == cls[s].end()) continue;
        if(*it == cls[e][i]) cnt++;
    }
    if(ne < 400) dp[ns][ne] = cnt;
    return cnt;
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].c);
    }
    sort(a,a+m,cmp);
    for (int i=0; i<m; ) {
        int e = i;
        while(e < m && a[i].c == a[e].c) e++;
        for (int j=i; j<e; j++) {
            graph[a[j].s].push_back(a[j].e);
            graph[a[j].e].push_back(a[j].s);
        }
        sz++;
        room.clear();
        for (int j=i; j<e; j++) {
            if(room.find(a[j].s) == room.end()){
                sz++;
                dfs(a[j].s,sz);
            }
        }
        for (int j=i; j<e; j++) {
            graph[a[j].s].clear();
            graph[a[j].e].clear();
        }
        i = e;
    }
    for (int i=1; i<=n; i++) {
        qnum[i] = i;
        sort(cls[i].begin(),cls[i].end());
    }
    sort(qnum+1,qnum+n+1,cmp2);
    for (int i=1; i<=n; i++) {
        renum[qnum[i]] = i;
    }
    int q;
    scanf("%d",&q);
    while (q--){
        int s,e;
        scanf("%d %d",&s,&e);
        printf("%d\n",query(s,e));
    }
}