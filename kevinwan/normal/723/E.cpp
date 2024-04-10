#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mn=210;
vector<pii>e;
vector<int>g[mn];
bool use[mn*mn],vis[mn];
int in[mn];
inline why(int i,int x){return e[i].first^e[i].second^x;}
set<pii>hail;
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)g[i].clear(),vis[i]=0,in[i]=0;
        for(int i=0;i<e.size();i++)use[i]=0;
        e.clear();
        hail.clear();
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(i);
            g[b].push_back(i);
            e.push_back({a,b});
            hail.insert({min(a,b),max(a,b)});
        }
        vector<int>v;
        for(int i=1;i<=n;i++){
            if(g[i].size()&1)v.push_back(i);
        }
        printf("%d\n",n-v.size());
        for(int i=0;i<v.size();i+=2)g[v[i]].push_back(e.size()),g[v[i+1]].push_back(e.size()),e.push_back({v[i],v[i+1]});
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            stack<int>s;
            s.push(i);
            vector<int>p;
            while(s.size()){
                int x=s.top();
                vis[x]=1;
                while(in[x]<g[x].size()&&use[g[x][in[x]]])in[x]++;
                if(in[x]<g[x].size())use[g[x][in[x]]]=1,s.push(why(g[x][in[x]++],x));
                else p.push_back(x),s.pop();
            }
            reverse(p.begin(),p.end());
            for(int i=0;i<p.size()-1;i++){
                if(hail.find({min(p[i],p[i+1]),max(p[i],p[i+1])})!=hail.end()){
                    printf("%d %d\n",p[i],p[i+1]);
                }
                hail.erase({min(p[i],p[i+1]),max(p[i],p[i+1])});
            }
        }
    }
}