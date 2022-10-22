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
const int M=5009;

int n,m;
int a[M],cnt[M],b[M][M],c[M][M];
vector<int>g[M];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        cnt[a[i]]++;
        b[a[i]][cnt[a[i]]]=i;
    }
    for(int i=1;i<=n;++i)cnt[i]=0;
    for(int i=n;i>=1;--i){
        cnt[a[i]]++;
        c[a[i]][cnt[a[i]]]=i;
    }
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        g[x].eb(y);
    }
    
    int ma=0,ans=0;
    for(int i=1;i<=n;++i){
        for(auto o:g[i]){
            if(b[i][o]==0)continue;
            int x=b[i][o],y=0,sum=0,cn=1;
            for(auto p:g[i]){
                if(c[i][p]>x)y++;
            }
            y-=(c[i][o]>x);
            if(y){
                cn=1ll*cn*y%mod;
                sum=2;
            }
            else sum=1;
            for(int j=1;j<=n;++j){
                if(j==i)continue;
                int xx=0,yy=0,zz=0;
                for(auto o:g[j]){
                    if(b[j][o]<x&&b[j][o])xx++;
                    if(c[j][o]>x&&c[j][o])yy++;
                    if(b[j][o]<x&&c[j][o]>x&&b[j][o]&&c[j][o])zz++;
                }
                if(xx*yy-zz>0){
                    sum+=2;
                    cn=1ll*cn*(xx*yy-zz)%mod;
                }
                else{
                    if(xx+yy){
                        sum++;
                        cn=1ll*cn*(xx+yy)%mod;
                    }
                }
            }
            if(sum>ma)ma=sum,ans=cn;
            else if(sum==ma)ans=(ans+cn)%mod;
        }
    }
    int sum=0,cn=1;
    for(int i=1;i<=n;++i){
        int y=0;
        for(auto o:g[i]){
            if(c[i][o]){
                y++;
            }
        }
        sum+=(y>0);
        if(y)cn=1ll*cn*y%mod;
    }
    if(sum>ma)ma=sum,ans=cn;
    else if(sum==ma)ans=(ans+cn)%mod;
    cout<<ma<<" "<<ans<<endl;
    return 0;
}