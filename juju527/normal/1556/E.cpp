#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
int lg[maxn];
ll mn[maxn][17],mx[maxn][17];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll Mn(int l,int r){
    int len=lg[r-l+1];
    return min(mn[l][len],mn[r-(1<<len)+1][len]);
}
ll Mx(int l,int r){
    int len=lg[r-l+1];
    return max(mx[l][len],mx[r-(1<<len)+1][len]);
}
int main(){
    int n,q;
    n=read();q=read();
    for(int i=1;i<=n;i++)a[i]=-read();
    for(int i=1;i<=n;i++)a[i]+=read();
    for(int i=1;i<=n;i++)a[i]+=a[i-1],mn[i][0]=mx[i][0]=a[i];
    lg[0]=-1;for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
    for(int j=1;j<17;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]),
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
        }
    }
    for(int i=1;i<=q;i++){
        int l,r;
        l=read();r=read();
        if(a[r]-a[l-1]!=0||Mn(l,r)-a[l-1]<0){puts("-1");continue;}
        printf("%lld\n",Mx(l,r)-a[l-1]);
    }
    return 0;
}