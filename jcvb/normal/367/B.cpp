#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int n,m,p;
int a[400005];
int b[400005];
map<int,int> ma;
int tot=0;
int dif[400005]={0},notok=0;
int addn(int x){
    if(dif[x]==0)notok++;
    dif[x]--;
    if(dif[x]==0)notok--;
}
int deln(int x){
    if(dif[x]==0)notok++;
    dif[x]++;
    if(dif[x]==0)notok--;
}
int ans[400005];int anstot=0;
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]),ma[a[i]];
    for (int i=1;i<=m;i++)scanf("%d",&b[i]),ma[b[i]];
    for (map<int,int>::iterator it=ma.begin();it!=ma.end();it++)it->second=++tot;
    for (int i=1;i<=n;i++)a[i]=ma[a[i]];
    for (int i=1;i<=m;i++)dif[b[i]=ma[b[i]]]++;
    for (int i=1;i<=tot;i++)if(dif[i])notok++;
    for (int st=1;st<=p;st++){
        for (int q=st;q+1ll*(m-1)*p<=n;q+=p){
            if(q==st){
                for (int qq=q;qq<=q+1ll*(m-1)*p;qq+=p)addn(a[qq]);
            }else{
                deln(a[q-p]);
                addn(a[q+1ll*(m-1)*p]);
            }
            if(!notok)ans[anstot++]=q;
        }
        for (int q=st;q+1ll*(m-1)*p<=n;q+=p){
            if(q==st){
                for (int qq=q;qq<=q+1ll*(m-1)*p;qq+=p)deln(a[qq]);
            }else{
                addn(a[q-p]);
                deln(a[q+1ll*(m-1)*p]);
            }
        }
    }
    sort(ans,ans+anstot);
    printf("%d\n",anstot);
    for (int i=0;i<anstot;i++)printf("%d ",ans[i]);
    return 0;
}