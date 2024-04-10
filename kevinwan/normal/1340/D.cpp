#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e5+10;
const ll mod=1e9+7;
vector<int>g[mn];
vector<pii>ans;
int mo=-1;
void dfs(int x,int p,int com){
    ans.push_back({x,com});
    vector<int>np;
    for(int y:g[x])if(y!=p)np.push_back(y);
    int cur=com;
    for(int i=0;i<np.size();i++){
        cur++;
        if(cur>mo){
            ans.push_back({x,com-(np.size()-i)-1});
            cur=com-(np.size()-i);
        }
        dfs(np[i],x,cur);
        ans.push_back({x,cur});
    }
    if(cur!=com-1)ans.push_back({x,com-1});
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)mo=max(mo,(int)g[i].size());
    ans.push_back({1,0});
    int cur=0;
    for(int y:g[1])dfs(y,1,++cur),ans.push_back({1,cur});
    printf("%d\n",ans.size());
    for(pii p:ans)printf("%d %d\n",p.first,p.second);
}