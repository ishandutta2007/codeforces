#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500010,mod=998244353;
int i,j,n,m,l,k,a[maxn],id,SUM,ANS;
void dfs(int now){
    if(now==id){dfs(now+1);return;}
    if(now>n){
        if(SUM==a[id])ANS=1;
        return;
    }
    SUM+=a[now];
    dfs(now+1);
    SUM-=a[now];
    SUM-=a[now];
    dfs(now+1);
    SUM+=a[now];
    dfs(now+1);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;ANS=0;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)id=i,dfs(1);
        if(ANS)puts("YES");
        else puts("NO");
    }
}