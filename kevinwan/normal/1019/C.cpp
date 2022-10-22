#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef pair<int,int>pii;
const int mn=1e6+10;
const ll mod=1e9+7;
vector<int>g[mn],rg[mn];
bool ans[mn],imp[mn];
bool cons[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);rg[b].push_back(a);
    }
    memset(cons,1,sizeof(cons));
    for(int i=1;i<=n;i++)if(cons[i]){
        for(int j:g[i])cons[j]=0;
        cons[i]=0;
        imp[i]=1;
    }
    for(int i=n;i>=1;i--)if(imp[i]){
        ans[i]=1;
        for(int j:rg[i])ans[i]&=!ans[j];
    }
    int num=0;
    for(int i=1;i<=n;i++){
        num+=ans[i];
    }
    printf("%d\n",num);
    for(int i=1;i<=n;i++)if(ans[i])printf("%d ",i);
}