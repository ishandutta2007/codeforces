/*
Silhouettes on the hills
And plains are closing in
As I try to escape
Enemies are looking to wipe me out
Hunted down for what I believe
For what I said
Now my fate seems sealed
They thought I'd never speak
But I am not a slave
And I will never ever swallow their lies
Fortified

A cover up
Ancient secrets
Well preserved
Shackling oppression
I hold the answers in my head
By any means
They will stay in control
An utopia for the chosen elite
I never will conform
Cause I am not a slave
I am a warrior and ready to die
To bring 'em down

[Chorus:]
Painted black by the guardians
My verdict has arrived
I follow my calling
The voice that beckons me

My legacy is rebellious chaos
A seed of hope is growing
As my final dusk ends in blood
By any means
They will stay in control
An utopia for the chosen elite
I will not die in vein
The impact that I've made
Is everlasting for the ones who rebels
Fortified!

[Chorus:]
Painted black by the guardians
My verdict has arrived
I follow my calling
The voice that beckons me
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
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 2e-5
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

double x[100],y[100],lx,rx,mid1,mid2,qx,qy;
long ans;
long er;
double ang1,ang2;
double l,r;

double gd(double x1,double y1,double x2,double y2)
{
 return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double ev(double tx,double ty)
{
 double z=gd(x[0],y[0],tx,ty);
 
 double res=0;
 for (int i=0;i<3;i++)
  res=max(res,fabs(z-gd(x[i],y[i],tx,ty)));
 return res;
}
 
double get(double tx)
{
 qx=tx;
 double l,r;
 l=-1000;
 r=1000;
 for (int iter=1;iter<=197;iter++)
 {
  double mid1,mid2;
  mid1=l*2+r;
  mid2=l+2*r;
  mid1/=3;
  mid2/=3;
  if (ev(tx,mid1)<ev(tx,mid2))
   r=mid2;
   else l=mid1;
 }
 qy=l;
 return ev(tx,qy);
}

pair<double, double> getcircle(double x1,double y1,double x2,double y2,double x3,double y3)
{
 if (x1==x2)
 {
  swap(x1,x3);
  swap(y1,y3);
 }
 if (x2==x3)
 {
  swap(x1,x2);
  swap(y1,y2);
 }
 pair<double, double> res;
 double ma=(y2-y1)/(x2-x1);
 double mb=(y3-y2)/(x3-x2);
 res.first=(ma*mb*(y1-y3)+mb*(x1+x2)-ma*(x2+x3))/(2*(mb-ma));

 if (fabs(ma)<eps)
 {
  res.second=-1.0/mb*(res.first-(x2+x3)/2)+(y2+y3)/2;
 }
 else
 {
  res.second=-1./ma*(res.first-(x1+x2)/2)+(y1+y2)/2;
 }
 return res;
}
             
int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<3;i++)
 cin>>x[i]>>y[i];

pair<double, double> p=getcircle(x[0],y[0],x[1],y[1],x[2],y[2]);

qx=p.first;
qy=p.second;

/*for (int i=0;i<3;i++)
 cout<<gd(x[i],y[i],qx,qy)<<"^"<<endl;
 */
//cout<<qx<<" "<<qy<<endl;
cout.precision(9);
for (int an=3;an<=100;an++)
{
 er=0;
 for (int i=0;i<3;i++)
  for (int j=0;j<3;j++)
  {
   ang1=atan2(y[i]-qy,x[i]-qx);
   ang2=atan2(y[j]-qy,x[j]-qx);
   ang1=fabs(ang1-ang2)/2;
   ang1*=an;
//   cout<<ang1<<" "<<i<<" "<<j<<" "<<an<<endl;
  // cout<<fixed<<fabs(sin(ang1))<<endl;
   if (fabs(sin(ang1))>eps)er=1;
  }
  if (er==0&&ans==0)
  {
   ans=an;
  }
}
//cout<<ans<<endl;

cout<<fixed<<ans*0.5*gd(x[0],y[0],qx,qy)*gd(x[0],y[0],qx,qy)*sin(2*M_PI/ans)<<endl;

cin.get();cin.get();
return 0;}