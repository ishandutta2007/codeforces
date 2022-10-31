#include <bits/stdc++.h>
using namespace std;

typedef long double cood;
const cood EPS=1e-9;
typedef complex<cood> point;
const point IU=point((cood)0,(cood)1);
namespace std{
  bool operator<(point P1,point P2){
    return abs(P1.real()-P2.real())>EPS?P1.real()<P2.real():P1.imag()<P2.imag();
  }
  bool operator>(point P1,point P2){
    return abs(P1.real()-P2.real())>EPS?P1.real()>P2.real():P1.imag()>P2.imag();
  } 
}
cood ep(point P1,point P2){return imag((conj(P1)*P2));}
cood ip(point P1,point P2){return real((conj(P1)*P2));}
int sign(cood s){return abs(s)<=EPS?0:s>0?1:-1;}
int ccw(point P0,point P1,point P2){return sign(ep(P1-P0,P2-P0));}
cood len(point P){return sqrt(norm(P));}
point uni(point P){return P/len(P);}
cood dis(point P1,point P2){return len(P1-P2);}
point cross_point(point P1,point P2,point P3,point P4){
  cood r=ep(P3-P1,P2-P1)/ep(P4-P3,P2-P1);
  return P3-r*(P4-P3);
}
point proj(point P,point P1,point P2){
  return P1+ip(P2-P1,P-P1)/norm(P2-P1)*(P2-P1);
}
cood sr(cood d){return sqrt(max(d,(cood)0));}


int cir2(point P1,point P2,cood r1,cood r2)
{
  cood d=dis(P1,P2);
  return abs(d-r1-r2)<EPS||abs(d-abs(r1-r2))<EPS?1:d>r1+r2||d<abs(r1-r2)?0:2;
}
void cross_pointCC(point P1,cood r1,point P2,cood r2,point &Q1,point &Q2){
  cood d=dis(P1,P2),rcs=(d*d+r1*r1-r2*r2)/(2*d);
  cood rsn=sr(r1*r1-rcs*rcs);
  point u1=uni(P2-P1),u2=IU*u1;
  Q1=P1+rcs*u1-rsn*u2,Q2=P1+rcs*u1+rsn*u2;
}

int main()
{
  int n;
  scanf("%d",&n);
  if(n==1){
    puts("2");
    return 0;
  }
  int x[3],y[3],r[3];
  point P[3];
  for(int i=0;i<n;i++){
    scanf("%d%d%d",x+i,y+i,r+i);
    P[i]=point(x[i],y[i]);
  }
  if(n==2){
    int q=cir2(P[0],P[1],r[0],r[1]);
    printf("%d\n",q==2?4:3);
    return 0;
  }
  int X=2,a=0,b=1,c=2;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int q=cir2(P[i],P[j],r[i],r[j]);
      if(X>q){
	a=i,b=j,c=3-i-j;
	X=q;
      }
    }
  }
  if(X==0){
    int ans=4;
    int q1=cir2(P[a],P[c],r[a],r[c]),q2=cir2(P[b],P[c],r[b],r[c]);
    ans=4;
    if(q1==2)ans++;
    if(q2==2)ans++;
    printf("%d\n",ans);
    return 0;
  }
  if(X==1){
    int ans=4;
    int q1=cir2(P[a],P[c],r[a],r[c]),q2=cir2(P[b],P[c],r[b],r[c]);
    point Q,Q2;
    cross_pointCC(P[a],r[a],P[b],r[b],Q,Q2);
    if(q1==1&&q2==1){
      ans++;
    }
    else if(q1==2&&q2==2){
      ans+=3;
    }
    else{
      ans+=2;
    }
    if(abs(dis(P[c],Q)-r[c])<EPS){
      ans--;
    }
    printf("%d\n",ans);
    return 0;
  }
  int ans=8;
  point Q1,Q2;
  cross_pointCC(P[a],r[a],P[b],r[b],Q1,Q2);
  if(abs(dis(P[c],Q2)-r[c])<EPS){
    ans--;
  }
  if(abs(dis(P[c],Q1)-r[c])<EPS){
    ans--;
  }
  printf("%d\n",ans);
  return 0;
}