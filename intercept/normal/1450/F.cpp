#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=1e5+9;
int n;
int a[M],b[M];
void work(){
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)b[i]=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        b[a[i]]++;
        if(a[i]==a[i-1])ans++;
    }
    int p=0;
    for(int i=1;i<=n;++i){
        if(b[p]<b[i])p=i;
    }
    if(b[p]>(n+1)/2)puts("-1");
    else{
        for(int i=1;i<=n;++i)b[i]=0;
        for(int i=1;i<=n;++i){
            if(a[i]==a[i-1])b[a[i]]+=2;
        }
        b[a[1]]++;
        b[a[2]]++;
        p=0;
        for(int i=1;i<=n;++i)if(b[p]<b[i])p=i;
        int x=0;
        for(int i=1;i<=n;++i){
            if(a[i]==a[i-1]){
                if(a[i]==p)x+=2;
                else x-=2;
            }
        }
        if(a[1]!=p)x--;
        else x++;
        if(a[n]!=p)x--;
        else x++;
        ans+=max(0,x/2-1);
        printf("%d\n",ans);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*   

*/