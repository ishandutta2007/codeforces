#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1<<20;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn],b[mn];
vector<pii>g[mn];
vector<int>pth;
int n;
bool u[mn];
int ind[mn];
bool chk(int p){
    memset(u,0,sizeof(u));
    memset(ind,0,sizeof(ind));
    for(int i=0;i<1<<p;i++)g[i].clear();
    for(int i=0;i<n;i++){
        g[a[i]%(1<<p)].push_back({b[i]%(1<<p),i});
        g[b[i]%(1<<p)].push_back({a[i]%(1<<p),i});
    }
    for(int i=0;i<1<<p;i++)if(g[i].size()&1)return 0;
    pth.clear();
    stack<pii>s;
    int beg=0;
    for(int i=1;i<1<<p;i++)if(g[i].size())beg=i;
    s.push({beg,-1});
    while(s.size()){
        int x=s.top().first,i=s.top().second;
        while(ind[x]<g[x].size()&&u[g[x][ind[x]].second])ind[x]++;
        if(ind[x]!=g[x].size()){
            u[g[x][ind[x]].second]=1;
            s.push(g[x][ind[x]++]);
        }
        else{
            s.pop();
            if(i==-1)break;
            if(a[i]%(1<<p)==x)pth.push_back(2*i),pth.push_back(2*i+1);
            else pth.push_back(2*i+1),pth.push_back(2*i);
        }
    }
    return pth.size()==2*n;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    int cur=0;
    for(int i=16;i;i>>=1){
        if(cur+i>20)continue;
        if(chk(cur+i))cur+=i;
    }
    int p=cur;
    chk(p);
    printf("%d\n",p);
    for(int x:pth)printf("%d ",x+1);
}