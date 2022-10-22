#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define i128 __int128_t
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
const int M=509;
int n,m,q,cnt;
int a[M],d[M][M];
char s[M];
bool vis[M];
int inv[9];
int main(){
    inv[0]=1;
    inv[1]=1;
    inv[2]=3;
    inv[3]=2;
    inv[4]=4;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%s",s+1);
        for(int j=1;j<=m;++j){
            a[j]=s[j]-'a';
        }
        for(int j=1;j<=m;++j){
            if(a[j]>0){
                if(vis[j]==0){
                    vis[j]=1;
                    for(int k=j;k<=m;++k){
                        d[j][k]=a[k];
                    }
                    cnt++;
                    break;
                }
                int t=a[j]*inv[d[j][j]]%5;
                for(int k=j;k<=m;++k)a[k]=(a[k]-t*d[j][k]%5+5)%5;
            }
        }
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        scanf("%s",s+1);
        for(int j=1;j<=m;++j){
            a[j]=s[j]-'a';
        }
        bool flag=0;
        for(int j=1;j<=m;++j){
            if(a[j]>0){
                if(vis[j]==0)continue;
                int t=a[j]*inv[d[j][j]]%5;
                for(int k=j;k<=m;++k)a[k]=(a[k]-t*d[j][k]%5+5)%5;
            }
        }
        for(int j=1;j<=m;++j)flag|=a[j]>0;
        printf("%d\n",flag?0:kpow(5,n-cnt));
    }
    return 0;
}
/*
2 2
ec
be
1
eb

2 4
aaaa
bbbb
1
cccc

3 3
313
034
100

120
*/