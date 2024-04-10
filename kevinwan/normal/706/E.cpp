#pragma GCC optimize "O3"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,mmx,popcnt,tune=native"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1e3+10;
int a[mn][mn];
pii l[mn][mn],r[mn][mn],u[mn][mn],d[mn][mn];
int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        l[i][j+1]=r[i][j-1]=u[i+1][j]=d[i-1][j]={i,j};
        l[i][j]={i,j-1};
        r[i][j]={i,j+1};
        u[i][j]={i-1,j};
        d[i][j]={i+1,j};
    }
    while(q--){
        int a,b,x,y,w,h;
        scanf("%d%d%d%d%d%d",&a,&b,&x,&y,&h,&w);
        pii p=d[0][1],q=d[0][1];
        for(int i=0;i<a-1;i++)p=d[p.first][p.second];
        for(int i=0;i<b-1;i++)p=r[p.first][p.second];
        for(int i=0;i<x-1;i++)q=d[q.first][q.second];
        for(int i=0;i<y-1;i++)q=r[q.first][q.second];
        for(int i=0;i<w;i++,p=r[p.first][p.second],q=r[q.first][q.second]){
            pii pp=u[p.first][p.second],qq=u[q.first][q.second];
            d[pp.first][pp.second]=q;
            d[qq.first][qq.second]=p;
            u[p.first][p.second]=qq;
            u[q.first][q.second]=pp;
        }
        p=l[p.first][p.second],q=l[q.first][q.second];
        for(int i=0;i<h;i++,p=d[p.first][p.second],q=d[q.first][q.second]){
            pii pp=r[p.first][p.second],qq=r[q.first][q.second];
            l[pp.first][pp.second]=q;
            l[qq.first][qq.second]=p;
            r[p.first][p.second]=qq;
            r[q.first][q.second]=pp;
        }
        p=u[p.first][p.second],q=u[q.first][q.second];
        for(int i=0;i<w;i++,p=l[p.first][p.second],q=l[q.first][q.second]){
            pii pp=d[p.first][p.second],qq=d[q.first][q.second];
            u[pp.first][pp.second]=q;
            u[qq.first][qq.second]=p;
            d[p.first][p.second]=qq;
            d[q.first][q.second]=pp;
        }
        p=r[p.first][p.second],q=r[q.first][q.second];
        for(int i=0;i<h;i++,p=u[p.first][p.second],q=u[q.first][q.second]){
            pii pp=l[p.first][p.second],qq=l[q.first][q.second];
            r[pp.first][pp.second]=q;
            r[qq.first][qq.second]=p;
            l[p.first][p.second]=qq;
            l[q.first][q.second]=pp;
        }
    }
    for(int i=1;i<=n;i++){
        pii p=r[i][0];
        for(int j=1;j<=m;j++,p=r[p.first][p.second]){
            printf("%d ",a[p.first][p.second]);
        }
        printf("\n");
    }
}