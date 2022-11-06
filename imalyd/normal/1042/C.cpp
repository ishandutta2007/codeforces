//Problem C
#include<bits/stdc++.h>
using namespace std;
const int N=200007;
int n,a[N],st[N],tp,rem,vis[N],St[N],Tp,pos,x;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<0)++x;
        if(a[i]<0&&(!pos||a[pos]<a[i]))pos=i;
        if(a[i]==0)St[++Tp]=i;
    }
    if(Tp+(pos!=0)==n)--Tp;
    if(pos&&(x&1))St[++Tp]=pos;
    for(int i=1;i<Tp;i++)printf("1 %d %d\n",St[i],St[i+1]),vis[St[i]]=1;
        rem=St[Tp];
    if(rem)printf("2 %d\n",rem),vis[rem]=1;
    for(int i=1;i<=n;i++)if(!vis[i])st[++tp]=i;
    for(int i=1;i<tp;i++)printf("1 %d %d\n",st[i],st[i+1]);
    return 0;
}