#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long c[1100][1100],h[1100],s[1100];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%I64d",&c[i][j]);
    memset(h,0x00,sizeof h);
    memset(s,0x00,sizeof s);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) h[i]+=c[i][j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) s[i]+=c[j][i];
    long long num=5e17,x,y,ans=0;
    for (long long i=0;i<=n;i++){
        long long d=i*4-2,now=0;
        for (int j=1;j<=n;j++) {now=now+d*d*h[j]; d-=4;}
        if (now<num){num=now; x=i;}
    } 
    ans=num; num=5e17;
    for (long long i=0;i<=m;i++){
        long long d=i*4-2,now=0;
        for (int j=1;j<=m;j++) {now=now+d*d*s[j]; d-=4;}
        if (now<num){num=now; y=i;}
    } 
    ans+=num; printf("%I64d\n%I64d %I64d\n",ans,x,y);
    return 0;
}