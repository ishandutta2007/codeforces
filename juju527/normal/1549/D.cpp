#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll a[maxn],b[maxn];
int lg[maxn];
ll g[maxn][18];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
ll get(int l,int r){
    int len=lg[r-l+1];
    return gcd(g[l][len],g[r-(1<<len)+1][len]);
}
int main(){
    int T;
    T=read();
    while(T--){
        int n;
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++)g[i][0]=abs(a[i]-a[i-1]);
        lg[0]=-1;for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
        for(int j=1;j<=lg[n];j++)
            for(int i=1;i<=n-(1<<j)+1;i++)
                g[i][j]=gcd(g[i][j-1],g[i+(1<<j-1)][j-1]);
        int res=1;
        for(int i=1;i<n;i++){
            int l=i,r=n+1,mid;
            while(l+1<r){
                mid=l+((r-l)>>1);
                if(get(i+1,mid)>1)l=mid;
                else r=mid;
            }
            res=max(res,l-i+1);
        }
        printf("%d\n",res);
    }
    return 0;
}