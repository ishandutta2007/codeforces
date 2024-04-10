#include <bits/stdc++.h>
using namespace std;

void ext_gcd(long long a,long long b,long long &X,long long &Y)
{
  if(b==0){
    X=1;
    Y=0;
  }
  else{
    long long x,y;
    ext_gcd(b,a%b,x,y);
    X=b-y;
    Y=a-x-(a/b)*y;
  }
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--){
    long long x,y,p,q;
    scanf("%lld%lld%lld%lld",&x,&y,&q,&p);
    if(q==0){
      printf("%d\n",x==0?0:-1);
      continue;
    }
    if(q==p){
      printf("%d\n",x==y?0:-1);
      continue;
    }
    long long a=p-q,b=q,D=-x*p+y*q;
    long long X,Y;
    ext_gcd(a,b,X,Y);
    if(D>=0){
      X*=D%b;
      X%=b;
      if(a*X<D){
	X+=(D-a*X+a*b-1)/(a*b)*b;
      }
      Y=(a*X-D)/b;
    }
    else{
      Y*=a-(-D)%a;
      Y%=a;
      if(b*Y<-D){
	Y+=(-D-b*Y+a*b-1)/(a*b)*a;
      }
      X=(b*Y+D)/a;
    }
    printf("%lld\n",X+Y);
  }
  return 0;
}