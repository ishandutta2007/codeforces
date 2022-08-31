/*
Battle through with
Expertise and strength
Friendly fire, napalmed
Burning, blackened blood
Jesus lovers renege on
Promises of removal

Nobody there ever had a reason to kill
All we had was an obligation to live
When that reason becomes unobtainable
Survival is useless, we're unable

Den of disease, uncommon thieves
Thievery of a most devious kind
Of body and soul

Act as a marionette
Yellow puppetmaster's strings strangehold
Horrific tales untold, malarial chills unfold
From anopheles mosquitos relentless offensive
Emaciate

Prisoned, immoval veal
Tenderized husk of skin and bones
Fed fecal scraps that dogs won't even eat
Malnutrition amongst our people

So make way for the cage
A dishonorable stage

Where blood flood flows
Filth rats feast in swarms
Lifeforce warms
Their strychnine stomachs

Weaker than God
Paler than snow
Wilder than any animal knows
Fully understanding
No means for escape
Idealize the Star Spangled Banner rape
In a state
Of psychosis
Emaciate, emaciate

Blurry vision
Through sunken eyes
Pulsate drop
Idle heart stop
Thoughts becoming numb
Witness the final words i've spoken
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n,tests,qleft,qright,qd;
long tp;
long span1,span2;
long cp;
long dir;
long t[1000000];
long span,tp1,tp2;
long val,l,r;

long gett(long v,long tl,long tr,long l,long r)
{
 if (l>r)return 0;
 if (l==tl&&r==tr)return t[v];
 long tm=tl+tr;
 tm/=2;
 return gett(v*2,tl,tm,l,min(r,tm))+gett(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(long v,long tl,long tr,long ps,long val)
{
 if (tl==tr)
 {
  t[v]=val;
  return;
 }
 else
 {
     long tm=tl+tr;
     tm/=2;
     if (ps<=tm)update(v*2,tl,tm,ps,val);
     else update(v*2+1,tm+1,tr,ps,val);
     t[v]=t[v*2]+t[v*2+1];
 }
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>tests;
qleft=1;
qright=n;
qd=n;

for (int i=1;i<=n;i++)
 update(1,1,n,i,1);

for (;tests;--tests)
{
 cin>>tp;
 if (tp==1)
 {
  cin>>cp;
  span1=cp;
  span2=qd-span1;
  if (span1>span2)
  {
   swap(qleft,qright);
   swap(span1,span2);
  }
  
  if (qleft<qright)dir=1;else dir=-1;
  
  for (int i=0;i<span1;i++)
  {
      tp1=qleft+dir*i;
      tp2=qleft+dir*(span1*2-i-1);//-dir*(i+1);
     // cout<<tp1<<"^^ "<<tp2<<" "<<qleft<<" "<<qright<<endl;
      
      val=gett(1,1,n,tp1,tp1);
      val+=gett(1,1,n,tp2,tp2);
      update(1,1,n,tp2,val);
  }
  
  qleft+=dir*span1;
  qd=abs(qleft-qright)+1;
 }   
 else
 {
  cin>>l>>r;
  if (qleft<qright)dir=1;else dir=-1;
  long aa,bb;
  aa=qleft+dir*l;
  bb=qleft+dir*(r-1);
  if (aa>bb)swap(aa,bb);
  long res=gett(1,1,n,aa,bb);
  cout<<res<<endl;
 }
/* cout<<qleft<<"  "<<qright<<endl;
 for (int i=qleft;;i+=dir){
  cout<<gett(1,1,n,i,i)<<" ";if (i==qright)break;}
 cout<<endl;
 */
}

cin.get();cin.get();
return 0;}