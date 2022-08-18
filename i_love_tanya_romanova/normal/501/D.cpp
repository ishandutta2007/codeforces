/*
Hateful I'm slashing, the head is removed
Removing the head of the corpse
The throat down the hard chest the trunk is torn
Tearing the trunk of the corpse

Disintegrating the stiff limb by limb
Performing deviant butchery
I chop up the limbs into small handy chunks
In my own way of sick butchery

I rip out the entrails, cut through pulsating flesh
Into the torso I grasp - deep - to tear out the rest
I divide into that which I like and which not
Nutritious organs stored, the rest left to rot

Wrathful I'm hacking the organs are minched
minching the flesh of the stiff
Imagine the bodypared by sick culinary
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,q,v1[1<<20],v2[1<<20],t[1<<20];

long get(long r)
{
 int res=0;
 for (;r>=0;r=(r&(r+1))-1)
  res+=t[r];
 return res;
}

void inc(long i, long val)
{
 for (;i<(1<<20);i=(i|(i+1)))
  t[i]+=val;
}

long ans[1<<20];

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>q;
 v1[i]+=q-get(q);
 inc(q,1);
}
for (int i=0;i<(1<<20);i++)
 t[i]=0;

for (int i=0;i<n;i++)
{
 cin>>q;
 v2[i]=q-get(q);
 inc(q,1);
}

int rem=0;

int b=1;
for (int i=n-1;i>=0;--i)
{
 v1[i]+=v2[i];
 v1[i]+=rem;
 if (v1[i]>=b)
 {
  rem=1;
  v1[i]-=b;
 }
 else rem=0;
 ++b;
}

/*for (int i=0;i<n;i++)
 cout<<v1[i]<<" ";
cout<<endl;
*/
for (int i=0;i<(1<<20);i++)
 t[i]=0;

for (int i=0;i<n;i++)
{
 long l,r;
  l=0;
 r=n-1;
 while (l<r)
 {
  long mid=l+r;
  mid/=2;
  if (mid-get(mid)+1>=v1[i]+1)
   r=mid;
  else 
   l=mid+1;
 }
 ans[i]=l;
 inc(ans[i],1);
}

for (int i=0;i<n;i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}