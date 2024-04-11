#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

int n, m, deg[100005];
vector<int> odds;

multiset<int> graph[100005];
vector<pi> ret;

void dfs(int pa, int x){
    while (graph[x].size()) {
        int pos = *graph[x].begin();
        graph[pos].erase(graph[pos].find(x));
        graph[x].erase(graph[x].find(pos));
        dfs(x,pos);
    }
    if(pa != 0){
        ret.push_back(pi(pa,x));
    }
}

int main(){
    scanf("%d %d",&n,&m);
    int cnt = 0;
    for (int i=0; i<m; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        deg[x]++;
        deg[y]++;
        graph[x].insert(y);
        graph[y].insert(x);
        cnt++;
    }
    for (int i=1; i<=n; i++) {
        if(deg[i]%2 == 1) odds.push_back(i);
    }
    for (int i=0; i<odds.size(); i+=2) {
        cnt++;
        deg[odds[i]]++;
        deg[odds[i+1]]++;
        graph[odds[i]].insert(odds[i+1]);
        graph[odds[i+1]].insert(odds[i]);
    }
    odds.clear();
    if(cnt%2 == 1){
        graph[1].insert(1);
        graph[1].insert(1);
        deg[1]+=2;
    }
    dfs(0,1);
    printf("%d\n",(int)ret.size());
    int p = 0;
    for (auto &i : ret){
        if(p) printf("%d %d\n",i.first,i.second);
        else printf("%d %d\n",i.second,i.first);
        p ^= 1;
    }
}