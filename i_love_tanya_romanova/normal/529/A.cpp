/*
This time no light will shine through when skies are falling
The age of bloodlust is dawning my soul is seeking solace
No god above us
Our bones are feeding the fire
Knights of doom
Blades cut deep
Knights of doom
At the gates

Through the night
Set our bodies ablaze
Turn the darkness to light
We are feeding the fire
We carry on

This time I stand alone amongst the demons
The battle for hope is calling
My eyes ablazed by fury
I'm armed with despair
I kill for the grace of my loves ones
A battle for honour
A battle for grace
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

string st;
long bal[1<<20];
long minsuf[1<<20],minpref[1<<20];
long val1,val2;
long n;
long s[1<<20];
long p[1<<20],pn[1<<20],cnt[1<<20],c[1<<20],cn[1<<20];
long classes,mid1,mid2;
long ans,k;
long open,clos;
long blen,bc,tlen,nopen;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;

n=st.size();
for (int i=0;i<n;i++)
if (st[i]=='(')s[i]=0;
else s[i]=1;

 
for (int i=0;i<n;i++)
 ++cnt[s[i]];

for (int i=1;i<100;i++)
 cnt[i]+=cnt[i-1];

for (int i=0;i<n;i++)
{
 p[--cnt[s[i]]]=i;
}

c[p[0]]=0;
classes=1;

for (int i=1;i<n;i++)
{
 if (s[p[i]]!=s[p[i-1]])++classes;
 c[p[i]]=classes-1;
}
/*
for (int i=0;i<n;i++)
 cout<<c[i]<<" ";
 cout<<endl;
 */
for (int h=0;(1<<h)<n;++h)
{
 for (int i=0;i<n;i++)
 {
  pn[i]=p[i]-(1<<h);
  if (pn[i]<0)pn[i]+=n;
 }   
 for (int i=0;i<=classes;i++)
  cnt[i]=0;
 for (int i=0;i<n;i++)
  cnt[c[pn[i]]]++;
 for (int i=1;i<classes;i++)
  cnt[i]+=cnt[i-1];
 for (int i=n-1;i>=0;--i)
  p[--cnt[c[pn[i]]]]=pn[i];
 cn[p[0]]=0;
 classes=1;
 for (int i=1;i<n;i++){
 mid1=p[i]+(1<<h);
 mid2=p[i-1]+(1<<h);
 mid1%=n;mid2%=n;
 if (c[p[i]]!=c[p[i-1]]||c[mid1]!=c[mid2])
  ++classes;
  cn[p[i]]=classes-1;}
  
 for (int i=0;i<=n;i++)
 c[i]=cn[i];
}

//-------------------------- end sufar

for (int i=0;i<st.size();i++)
{
 if (st[i]=='(')
 bal[i+1]=bal[i]+1;
 else bal[i+1]=bal[i]-1;
 minpref[i+1]=min(minpref[i],bal[i+1]);
 if (st[i]=='(')
  ++open;
 else
  ++clos;
}

minsuf[st.size()]=bal[st.size()];
for (int i=st.size()-1;i+1;--i)
{
 minsuf[i]=min(minsuf[i+1],bal[i]);
}
/*
for (int i=0;i<=st.size();i++)
 cout<<minpref[i]<<" ";
 cout<<endl;
for (int i=0;i<=st.size();i++)
 cout<<minsuf[i]<<" ";
cout<<endl;
*/
blen=1e9;
bc=0;

for (int i=0;i<st.size();i++)
{
 val1=minsuf[i+1]-bal[i];
 val2=minpref[i]+(bal[st.size()]-bal[i]);
 val1=min(val1,val2);
 if (val1>=0)
 {
  tlen=st.size()+(open-clos);
  if (tlen<blen||(tlen==blen&&c[i]<c[bc]))
  {
   blen=tlen;
   bc=i;
  }
 }
 else
 {
  nopen=open-val1;
  tlen=st.size()+(nopen-clos);
  if (tlen<blen||(tlen==blen&&c[i]<c[bc]))
  {
   blen=tlen;
   bc=i;
  }
 }
}

string ts="";
for (int i=bc;i<st.size();i++)
 ts+=st[i];
for (int i=0;i<bc;i++)
 ts+=st[i];

long mb=0;
long qb=0;

for (int i=0;i<ts.size();i++)
{
    if (ts[i]=='(')
     qb++;
     else qb--;
    if (qb<mb)mb=qb;
}
reverse(ts.begin(),ts.end());
if (mb<0)
{
 mb*=-1;
 for (int i=0;i<mb;i++)
  ts+='(';
}
reverse(ts.begin(),ts.end());
qb=0;

for (int i=0;i<ts.size();i++)
{
 if (ts[i]=='(')++qb;
 else --qb;
}

for (int i=0;i<qb;i++)
 ts+=')';
 cout<<ts<<endl;
cin.get();cin.get();
return 0;}