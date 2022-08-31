#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<functional>
#include<string>
using namespace std;
int n;

struct str{
       string st;
       int i,t;
}a[200005];
int cmp(const str&a,const str&b){
    return a.st<b.st;
}
int ord[200005];
int x[200005][2];
int f[200005][2]={0};
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        cin>>a[i*2-1].st;
        cin>>a[i*2].st;
        a[i*2-1].i=a[i*2].i=i;
        a[i*2-1].t=0,a[i*2].t=1;
    }
    sort(a+1,a+1+2*n,cmp);
    for (int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        ord[x]=i;
    }
    for (int i=1;i<=2*n;i++){
        x[ord[a[i].i]][a[i].t]=i;
    }
    f[1][0]=f[1][1]=1;
    for (int i=2;i<=n;i++){
        if(x[i][0]>x[i-1][0] && f[i-1][0])f[i][0]=1;
        if(x[i][0]>x[i-1][1] && f[i-1][1])f[i][0]=1;
        if(x[i][1]>x[i-1][0] && f[i-1][0])f[i][1]=1;
        if(x[i][1]>x[i-1][1] && f[i-1][1])f[i][1]=1;
        }
    if(f[n][0]||f[n][1])printf("YES\n");
    else printf("NO\n");
    return 0;
}