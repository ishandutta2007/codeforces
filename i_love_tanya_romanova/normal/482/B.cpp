/*
The moment when you held me tight
Won't come back any more
And at the end of that night
You slammed the door

My dream it died away
Just when I saw red
And nothing but a memory
Is left inside my head

Nothing is forever in life
But a memory believe it's true
And when I gaze in the rain
I'm crying just for you

The scarlet rose has died
Lost inside the night
Left in my mind like a dream and full of pride
The scarlet rose has died

The one and only way to catch the
Beauty of a dawn
Is to take a picture
Of the growing sun

I got that experience
No one could steal away
One moment of your life is mine
I remember day by day

Nothing is forever in life
But a memory believe it's true
And when I gaze in the rain
I'm crying just for you
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
#define free adsgasdg

using namespace std;

long n,m,a[1<<20],b[1<<20],val[1<<20],ad[1<<18][33];
long ttl[1<<20];
long v;
long ar[1<<20];
long er;
long t[1<<20];

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  t[v]=ar[tl];
  return;
 }
 long tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
 t[v]=(t[v*2]&t[v*2+1]);
// cout<<v<<" "<<tl<<" "<<tr<<"  "<<t[v]<<endl;
}

long get(long v,long tl,long tr,long l,long r)
{
 if (l>r)
  return ((1<<30)-1);
 if (tl==l&&tr==r)
  return t[v];
 long tm=tl+tr;
 tm/=2;
 long v1=get(v*2,tl,tm,l,min(r,tm));
 long v2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 return (v1&v2);
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=m;i++)
{
 cin>>a[i]>>b[i]>>val[i];
 
 for (int j=0;j<=30;j++)
  if (val[i]&(1<<j))
   ad[a[i]][j]++,
   ad[b[i]+1][j]--;
}

for (int i=1;i<=n;i++)
{
 for (int j=0;j<=30;j++) 
 ttl[j]+=ad[i][j];
 v=0;
 for (int j=0;j<=30;j++)
  if (ttl[j]) v+=(1<<j);
 ar[i]=v;
}

 
build(1,1,n);

er=0;
for (int i=1;i<=m;i++)
{
 //cout<<get(1,1,n,a[i],b[i])<<endl;
 if (get(1,1,n,a[i],b[i])!=val[i])
  er=1;
}
if (er)cout<<"NO"<<endl;
else
{
 cout<<"YES"<<endl;
 for (int i=1;i<=n;i++)
 {
  if (i>1)
  cout<<" ";
  cout<<ar[i];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}