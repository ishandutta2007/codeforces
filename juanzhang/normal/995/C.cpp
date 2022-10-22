#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
int read(){
  int x=0;char c=getchar();bool f=0;
  while(c<48)f|=c=='-',c=getchar();
  while(c>47)x=x*10+(c^48),c=getchar();
  return f?-x:x;
}

int n,ans[1<<17];
struct node{
  int x,y;
}A[1<<17];

mt19937 Rnd(time(0));

ll abso(ll x){
  return x<0?-x:x;
}

int main(){
  cin>>n;rep(i,1,n)A[i].x=read(),A[i].y=read();
  while(1){
    ll Sx[16],Sy[16];
    rep(i,0,15)Sx[i]=Sy[i]=0;
    rep(i,1,n){
      if(Rnd()&1){
        ans[i]=1;
        Sx[i&15]+=A[i].x,Sy[i&15]+=A[i].y;
      }else{
        ans[i]=-1;
        Sx[i&15]-=A[i].x,Sy[i&15]-=A[i].y;
      }
    }
    rep(S,0,65535){
      ll x=0,y=0;
      rep(i,0,15){
        if(S>>i&1){
          x+=Sx[i],y+=Sy[i];
        }else{
          x-=Sx[i],y-=Sy[i];
        }
      }
      ll lim=1.5e6;
      if(abso(x)<=lim&&abso(y)<=lim&&x*x+y*y<=lim*lim){
        rep(i,1,n){
          printf("%d ",ans[i]*(S>>(i&15)&1?1:-1));
        }
        return 0;
      }
    }
  }
  return 0;
}