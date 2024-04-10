#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
const ll mod=998244353;
int s[mn],g[mn];
int a[mn],b[mn];
int n;
bool check2(int g,int s){
    for(int i=1;i<=n;i++)g-=b[i]*(b[i]-1)*(b[i]-2)/6;
    if(g)return 0;
    for(int i=1;i+2<=n;i++)s-=b[i]*b[i+1]*b[i+2];
    if(s)return 0;
    return 1;
}
bool check(){
    bool ok=1;
    memcpy(b,a,sizeof(a));
    if(!check2(g[n],s[n]))return 0;
    for(int i=n-1;i>=0;i--){
        b[max(i,1)]++;
        if(!check2(g[i],s[i]))return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    scanf("%d%d",g+n,s+n);
    for(int i=n-1;i>=0;i--){
        int p;
        if(i>=3)p=i;
        else if(i==2)p=1;
        else if(i==1)p=2;
        else p=1;
        printf("+ %d\n",p);
        fflush(stdout);
        scanf("%d%d",g+i,s+i);
    }
    for(int i=0;i<=100;i++)if((g[0]-g[1])*6==(i+2)*(i+1)*i-(i+1)*i*(i-1))a[1]=i;
    a[3]=((s[0]-s[1])-(s[2]-s[3]))-1;
    a[2]=(s[2]-s[3])/(a[3]+1);
    a[4]=(s[1]-s[2]-(a[1]+1)*(a[3]+1))/(a[3]+1)-(4!=n);
    for (int j = 5; j <= n; j++) {
        int d=s[j-2]-s[j-1]-a[j-3]*a[j-4]-a[j-3]*(a[j-1]+1);
        a[j]=d/(a[j-1]+1)-(j!=n);
        if(a[j]<0)a[j]=0;
    }
    printf("!");
    for(int i=1;i<=n;i++)printf(" %d",a[i]);
    printf("\n");
    fflush(stdout);
}