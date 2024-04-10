#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct atom{
    int l,r,where;
}x[200100];
int compare(atom k1,atom k2){
    return (k1.l<k2.l)||(k1.l==k2.l&&k1.r>k2.r);
}
int n,m,pd[200100];
int main(){
    scanf("%d%d",&n,&m); for (int i=1;i<=m;i++) {scanf("%d%d",&x[i].l,&x[i].r); x[i].r+=x[i].l-1; x[i].where=i;} 
    sort(x+1,x+m+1,compare); int now=0,ans=0,k=0;
    for (int i=1;i<=m;i++)
        if (x[i].l-1<=now){
            if (x[i].r>x[k].r) k=i;
        } else {
            if (k){ans+=1-pd[x[k].where]; pd[x[k].where]=1;}
            now=x[k].r;
            if (x[i].r>now) k=i;
            if (x[i].l-1>now){ans+=1-pd[x[i].where]; now=x[i].r; pd[x[i].where]=1;}
        }
    if (x[k].r>now){ans+=1-pd[x[k].where]; pd[x[k].where]=1;}
    printf("%d\n",m-ans);
    for (int i=1;i<=m;i++) if (pd[i]==0) printf("%d ",i); cout<<endl; return 0;
}