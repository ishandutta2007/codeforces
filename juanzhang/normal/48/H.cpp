#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

int n,m,A,B,C;
char str[205][205];
int cp[105],tmp[2][105],ans[105][105];

int main() {
  cin>>n>>m>>A>>B>>C;
  int tl=0,ci=1,cj=1;
  rep(T,1,A){
    cp[cj]=ci,tl=cj,ans[ci][cj]=1;cj==m?ci++,cj=1:cj++;
  }
  per(j,tl,1)ans[cp[j]+1][j]=(tl-j)&1?3:6;
  rep(j,tl+1,m)ans[cp[j]+1][j]=(j-tl)&1?6:3;
  ci++;
  rep(T,1,B){
    ans[ci][cj]=2;cj==m?ci++,cj=1:cj++;
  }
  rep(j,1,cj-1)tmp[0][j]=(cj-j)&1?6:3,tmp[1][j]=(cj-j)&1?5:4;
  rep(j,cj,m)tmp[0][j]=ans[ci][j]=(j-cj)&1?5:4,tmp[1][j]=(j-cj)&1?6:3;
  rep(i,ci+1,n)rep(j,1,m)ans[i][j]=tmp[(i-ci)&1][j];
  rep(i,1,n)rep(j,1,m){
    char &c1=str[(i-1)*2+1][(j-1)*2+1],&c2=str[(i-1)*2+1][j*2],&c3=str[i*2][(j-1)*2+1],&c4=str[i*2][j*2];int t=ans[i][j];
    if(t==1)c1=c2=c3=c4='#';
    if(t==2)c1=c2=c3=c4='.';
    if(t==3)c1=c4='\\',c2='#',c3='.';
    if(t==4)c2=c3='/',c1='.',c4='#';
    if(t==5)c1=c4='\\',c2='.',c3='#';
    if(t==6)c2=c3='/',c1='#',c4='.';
  }
  rep(i,1,n*2){
    rep(j,1,m*2)putchar(str[i][j]);puts("");
  }
  return 0;
}