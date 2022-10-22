#include<bits/stdc++.h>
using namespace std;
const int maxr=55,mod=1e9+7;
int r,p1,p2,p3,p4,s;
bool vis[2*maxr][2*maxr],tag[2*maxr][2*maxr];
int f[2*maxr][2*maxr][2*maxr];
int a[2*maxr][2*maxr];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){
    if(x>=mod)x-=mod;
    return x;
}
inline int sub(int x){
    if(x<0)x+=mod;
    return x;
}
int power(int x,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        b>>=1;
    }
    return ans;
}
double dist(int x,int y){
    return sqrt(x*x+y*y);
}
int F(int i,int j,int k){
    if(dist(i,j)>r)return 0;
    return f[i+r][j+r][k];
}
void solve(int n){
    for(int i=1;i<=n;i++){
        int p=i;
        for(int j=i+1;j<=n;j++)if(a[j][i]>a[p][i])p=j;
        swap(a[p],a[i]);
        int iv=power(a[i][i],mod-2);
        for(int j=i+1;j<=n+1;j++)a[i][j]=1ll*iv*a[i][j]%mod;
        a[i][i]=1ll*a[i][i]*iv%mod;
        for(int j=i+1;j<=n;j++){
            int v=a[j][i];
            for(int k=i;k<=n+1;k++)
                a[j][k]=sub(a[j][k]-1ll*v*a[i][k]%mod);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=i-1;j>=1;j--){
            a[j][n+1]=sub(a[j][n+1]-1ll*a[i][n+1]*a[j][i]%mod);
            a[j][i]=0;
        }
    }
    return ;
}
int main(){
    r=read();p1=read();p2=read();p3=read();p4=read();
    s=power(p1+p2+p3+p4,mod-2);
    p1=1ll*p1*s%mod;p2=1ll*p2*s%mod;p3=1ll*p3*s%mod;p4=1ll*p4*s%mod;
    int id=0;
    for(int i=-r;i<r;i++){
        for(int j=r;j>=-r;j--){
            if(dist(i,j)<=r){
                id++;
                vis[i+r][j+r]=1;
                f[i+r][j+r][id]=1;
                break;
            }
        }
    }
    id++;
    int iv=power(p2,mod-2);
    for(int j=r;j>=-r;j--){
        for(int i=-r;i<=r;i++){
            if(vis[i+r][j+r]||dist(i,j)>r)continue;
            if(dist(i,j+1)<=r){
                tag[i+r][j+1+r]=1;
                for(int k=1;k<=id;k++)
                    f[i+r][j+r][k]=1ll*iv*sub(sub(F(i,j+1,k)-1ll*p1*F(i-1,j+1,k)%mod)-add(1ll*p3*F(i+1,j+1,k)%mod+1ll*p4*F(i,j+2,k)%mod))%mod;
                f[i+r][j+r][id]=sub(f[i+r][j+r][id]-iv);
            }
            else{
                tag[i+r][j+r]=1;
                for(int k=1;k<=id;k++)
                    f[i+r][j+r][k]=add(add(1ll*p1*F(i-1,j,k)%mod+1ll*p2*F(i,j-1,k)%mod)+add(1ll*p3*F(i+1,j,k)%mod+1ll*p4*F(i,j+1,k)%mod));
                f[i+r][j+r][id]=add(f[i+r][j+r][id]+1);
            }
        }
    }
    int m=0;
    for(int j=r;j>=-r;j--){
        for(int i=-r;i<=r;i++){
            if(tag[i+r][j+r]||dist(i,j)>r)continue;
            m++;
            for(int k=1;k<=id;k++){
                int val;
                val=add(add(1ll*p1*F(i-1,j,k)%mod+1ll*p2*F(i,j-1,k)%mod)+add(1ll*p3*F(i+1,j,k)%mod+1ll*p4*F(i,j+1,k)%mod));
                a[m][k]=sub(F(i,j,k)-val);
            }
            a[m][id]=sub(a[m][id]-1);
        }
    }
    a[++m][id]=1;a[m][id+1]=1;
    solve(id);
    int res=0;
    for(int i=1;i<=id;i++)res=add(res+1ll*f[r][r][i]*a[i][id+1]%mod);
    printf("%d\n",res);
    return 0;
}