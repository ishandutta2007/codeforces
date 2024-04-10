/*
We are strangling
Our souls every day
Our sacrifice
For the Modern Age
Dispirited
A ghost to our selves
Alienated
Lifeless shells

We are so sated
And we are so much
But we will never be enough
Our hearts are breaking
Without a sound
Fighting freedom
Losing ground

The path I take
I'll walk with fire
I'll earth myself
And seek the higher
The path I take
I'll walk with fire

Peace of mind
A gift for the gifted kind
The haunted breed
The language I speak

Into this sound
I carry all that's bad
My hopes
My demons
My regrets

We are so sated and
We are so much
But we will never be enough
Our hearts are breaking
Without a sound
Fighting freedom
Losing ground

The path I take
I'll walk with fire
I'll earth myself
And seek the higher
The path I take
I'll walk with fire
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,x[1<<19],h[1<<19],l,r,mid;
vector<pair<long, long> > v;
long ans[1<<19];
long t[1<<20];

long get(long v,long tl,long tr,long l,long r)
{
 if (l>r)return -1; 
 if (tl==l&&tr==r)
  return t[v];
  long tm=tl+tr;
 tm/=2;
 long res1=get(v*2,tl,tm,l,min(r,tm));
 long res2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 return max(res1,res2);
}

void update(long v,long tl,long tr,long ps,long val)
{
     if (tl==tr) 
     {
                 t[v]=val;
                 return;
     }
     long tm=tl+tr;
     tm/=2;
     if (ps<=tm)
      update(v*2,tl,tm,ps,val);
     else
     update(v*2+1,tm+1,tr,ps,val);
     t[v]=max(t[v*2],t[v*2+1]);
}

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>x[i]>>h[i];

for (int i=1;i<=n;i++)
{
    v.push_back(make_pair(x[i],i));
}

sort(v.begin(),v.end());

for (int i=v.size()-1;i+1;--i)
{
 l=i;
 r=v.size()-1;
 long id=v[i].second;
 while (l<r)
 {
  long mid=l+r+1;
  mid/=2;
  if (v[mid].first<x[id]+h[id])
   l=mid;
   else r=mid-1;
 }
/* cout<<"^"<<" "<<l<<endl;
 cin.get();
 cin.get();
 */
 long mx=get(1,0,n-1,i,l);
 if (mx<i)mx=i;
 ans[id]=mx-i+1;
 update(1,0,n-1,i,mx);
}


for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}