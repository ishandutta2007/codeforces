#include<bits/stdc++.h>
using namespace std;
const int MAXL=500000,LgL=20,MAXN=200000;
int Next[MAXL][LgL];
int n,m;
pair<int,int>a[MAXN];
int main(){
    memset(Next,-1,sizeof(Next));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+n,[](const pair<int,int>&a,const pair<int,int>&b){return a.second>b.second;});
    for(int i=0,j=a[0].second-1;i<n;++i){
        j=min(j,a[i].second-1);
        for(;j>=a[i].first;--j)
            Next[j][0]=a[i].second;
    }
    for(int j=1;j<LgL;++j)
        for(int i=0;i<MAXL;++i)
            if(Next[i][j-1]!=-1&&Next[i][j-1]!=MAXL)
                Next[i][j]=Next[Next[i][j-1]][j-1];
    for(;m>0;--m){
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=0;
        for(int i=LgL-1;i>=0&&l<r;--i)
            if(Next[l][i]!=-1&&Next[l][i]<r){
                ans+=1<<i;
                l=Next[l][i];
            }
        if(l!=-1&&Next[l][0]>=r)
            printf("%d\n",ans+1);
        else
            puts("-1");
    }
    return 0;
}