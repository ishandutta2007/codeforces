#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mn=2e5+10;
bool p[mn],u[mn];
vector<pii>v;
int f;
int main()
{
    int n,i,j;
    scanf("%d",&n);
    memset(p,1,sizeof(p));
    p[0]=p[1]=0;
    for(i=2;i*i<=n;i++)if(p[i])for(j=i*i;j<=n;j+=i)p[j]=0;
    for(i=3;i<=n;i++){
        if(!p[i])continue;
        int num=0;
        for(j=i;j<=n;j+=i)if(!u[j])num++;
        if(num<2)continue;
        int f=i;
        u[f]=1;
        for(j=(num&1)?(3*i):(2*i);j<=n;j+=i){
            if(u[j])continue;
            u[j]=1;
            if(f)v.push_back({f,j}),f=0;
            else f=j;
        }
    }
    i=2;
    int f=i;
    u[f]=1;
    for(j=2*i;j<=n;j+=i){
        if(u[j])continue;
        u[j]=1;
        if(f)v.push_back({f,j}),f=0;
        else f=j;
    }
    printf("%d\n",v.size());
    for(pii p:v)printf("%d %d\n",p.first,p.second);
}