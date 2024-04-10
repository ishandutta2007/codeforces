#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=5e5+10;
vector<int> g[mn];
ll s[mn],bes[mn];
int n;
unordered_map<ll,ll> m;
ll ans;
void dfs(int x,int p){
    s[x]=1;
    bes[x]=n-1;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        s[x]+=s[y];
    }
    m.clear();
    for(int y:g[x]){
        if(y==p)continue;
        bes[x]=max(bes[x],bes[y]+(s[x]-s[y])*(n-s[x]));
        ans=max(ans,m[s[y]]+bes[y]-s[y]*s[y]);
        m[s[y]]=max(m[s[y]],bes[y]);
    }
    for(auto i=m.begin();i!=m.end();i++){
        for(auto j=i;j!=m.end();j++){
            if(j==i)continue;
            ans=max(ans,i->second+j->second-i->first*j->first);
        }
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    if(n==2){
        printf("2");
        return 0;
    }
    for(i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(i=1;g[i].size()==1;i++);
    dfs(i,0);
    printf("%lld",ans+1LL*n*(n-1)/2);
}