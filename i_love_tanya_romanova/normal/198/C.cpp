/*
Troubled dreams of a wandering nomad
Damned to be all by myself
I traveled far following bright stars
Through the endless desert sands

Starring off into the sky, down on myself
Loneliness brings my demise, oh what a nightmare
Here we go

Leave me be, why must I please them
When I can't even please myself
Deep in thoughts but I still feel so
Lost in endless despair

Starring off into the sky, down on myself
Loneliness brings my demise, oh what a nightmare
Yeah here we go

As you soon realize
The night's so black I feel blind
Should I keep wandering on
On and on and on

There's just one thing you should know
I can't take it no more
Two wrongs don't make it right or wrong
I can't take it and in the end you will find me a peace of mind

Forever lost, severing my thoughts
From the dream I must seek
It's time to end this aggravation
The nomad spirit lives in me

Starring off into the sky, down on myself
Loneliness brings my demise, oh what a nightmare
Yeah here we go

As you soon realize
The night's so black, I feel blind
Should I keep wandering on
On and on and on

There's just one thing you should know
I can't take it no more
Two wrongs don't make it right or wrong
I can't take it and in the end you will find me a peace of mind
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

double xp,yp,vp,x,y,v,r,stang,rr,nang,tx,ty,l,rb,m;

double gett(double p)
{
 double qx=x+(tx-x)*p;
 double qy=y+(ty-y)*p;
 return sqrt(qx*qx+qy*qy);
}

pair<double, double> solve1(double x,double y)
{
 double gyp=x*x+y*y;
 double k1=gyp-rb*rb;
 pair<double, double> ans;
 ans.first=sqrt(k1);
 gyp=sqrt(gyp);
// k1=sqrt(k1);
 ans.second=acos(rb/gyp);
 return ans;
}

double solve()
{
 double l,r;
 double m1,m2;
 l=0;
 r=1;
 while (l<r-eps)
 {
  m1=l*2+r;
  m2=l+2*r;
  m1/=3;m2/=3;
  if (gett(m1)<gett(m2))r=m2;
  else l=m1;
 }
 
 //cout<<l<<" "<<gett(l)<<" "<<tx<<" "<<ty<<endl;
 if (gett(l)>=rb) return sqrt((x-tx)*(x-tx)+(y-ty)*(y-ty));// str8
 
 double ang1,ang2,spang;
 ang1=atan2(ty,tx);
 ang2=atan2(y,x);
 spang=fabs(ang1-ang2);
 
// cout<<spang<<endl;
 pair<double, double> p1,p2;
 
 if (2*M_PI-spang<spang)spang=2*M_PI-spang;
 p1=solve1(fabs(x),fabs(y));
 p2=solve1(fabs(tx),fabs(ty));
 spang-=p1.second;
 spang-=p2.second;
// cout<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<" "<<x<<" "<<y<<" "<<tx<<" "<<ty<<" "<<spang<<endl;
 return p1.first+p2.first+spang*rb;
 
}

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>xp>>yp>>vp;
cin>>x>>y>>v>>rb;

stang=atan2(yp,xp);
rr=xp*xp+yp*yp;
rr=sqrt(rr);

l=0;
r=1e7;

while (l<r-eps)
{
// cout<<l<<" "<<r<<endl;
 m=l+r;
 m/=2;
 nang=stang+(vp*m/rr);
 tx=rr*cos(nang);
 ty=rr*sin(nang);
// cout<<solve()<<" "<<m*v<<endl;
 if (solve()>m*v)l=m;
 else r=m;
}

cout.precision(10);
cout<<fixed<<l<<endl;

cin.get();cin.get();
return 0;}