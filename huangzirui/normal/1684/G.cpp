#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn=1010;
int i,j,k,n,m,w1[maxn],w2[maxn],cnt1,cnt2;
int is[maxn],chs[maxn],uchs[maxn];
int a[maxn];
vector<int>V[maxn];
bool dfs(int now){
    if(is[now])return false;
    is[now]=1;
    for(int u:V[now])
        if(!uchs[u] || dfs(uchs[u])){
            uchs[u]=now;
            chs[now]=u;
            return true;
        }
    return false;
}
multiset<int>S;
vector<pii>Ans;
int main(){
    cin>>n>>m;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        S.insert(a[i]);
    }
    sort(a+1,a+1+n);
    if(2*a[n]>=m){
        puts("-1");
        return 0;
    }
    for(i=1;i<=n;i++)
        if(3*a[i]>m)
            w1[++cnt1]=a[i];
        else w2[++cnt2]=a[i];
    for(i=1;i<=cnt1;i++)
        for(j=1;j<=cnt2;j++)
            if(w1[i]%w2[j]==0 && w1[i]+w1[i]+w2[j]<=m)V[i].push_back(j);
    for(i=1;i<=cnt1;i++){
        memset(is,0,sizeof(is));
        if(!dfs(i)){puts("-1");exit(0);}
    }
    for(i=1;i<=cnt1;i++){
        Ans.push_back(make_pair(w1[i]+w2[chs[i]],w1[i]+w1[i]+w2[chs[i]]));
        // cerr<<"i="<<i<<" erase "<<w1[i]<<' '<<w2[chs[i]]<<endl;
        S.erase(S.find(w1[i]));S.erase(S.find(w2[chs[i]]));
    }
    for(auto w:S)Ans.push_back(make_pair(2*w,3*w));
    cout<<Ans.size()<<endl;
    for(auto P:Ans)
        printf("%d %d\n",P.second,P.first);
}