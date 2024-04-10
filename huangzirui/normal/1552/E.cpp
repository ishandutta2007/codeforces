#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500010,mod=998244353;
int i,j,n,m,l,k,a[maxn],last[maxn],num[maxn],ans[maxn][2];
int main(){
    cin>>n>>m;
    int S=(n-1)/(m-1)+1;
    for(i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
        //cout<<num[a[i]]<<' '<<last[a[i]]<<endl;
        if(!last[a[i]])last[a[i]]=i,num[a[i]]=0;
        else{
            if(last[a[i]]==-1)continue;
            ans[a[i]][0]=last[a[i]];
            ans[a[i]][1]=i;
            last[a[i]]=-1;
            for(j=1;j<=n;j++){
                num[j]++;
                if(num[j]==S)last[j]=min(last[j],0),num[j]=0;
            }
        }
    }
    for(i=1;i<=n;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
}