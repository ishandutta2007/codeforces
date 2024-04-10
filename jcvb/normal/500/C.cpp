#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int n,m;
int w[1005];
int seq[1005];
int ord[1005];
int fir[1005]={0};
int cmp(int i,int j){return fir[i]<fir[j];}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf("%d",&w[i]);
    for (int i=1;i<=m;i++){
        scanf("%d",&seq[i]);
        if(!fir[seq[i]])fir[seq[i]]=i;
    }
    for (int i=1;i<=n;i++)ord[i]=i;
    for (int i=1;i<=n;i++)if(!fir[i])fir[i]=10000000;
    sort(ord+1,ord+1+n,cmp);
    ll ans=0;
    for (int i=1;i<=m;i++){
        int x=seq[i];
        int pos=0;
        for (int j=1;j<=n;j++)if(ord[j]==x){pos=j;break;}
        for (int j=pos-1;j>=1;j--){ord[j+1]=ord[j];ans+=w[ord[j]];}
        ord[1]=x;
    }
    cout<<ans<<endl;
    return 0;
}