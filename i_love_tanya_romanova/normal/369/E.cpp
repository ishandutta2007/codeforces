/*
Only yesterday 
They told me you were gone 
All these normal people 
Will I find another one? 

Monkey on ny back 
Aching in my bones 
I forgot you said, 
"One day you'll walk alone." 

I said I need you 
Does that make me wrong? 
Am I a weak man? 
Are you feeling strong? 

My heart was blackened 
It's bloody red 
A hole in my heart 
A hole in my head 

Who will help me up? 
Where's the helping hand? 
Will you turn on me? 
Is this my final stand? 

In a dream I cannot see 
Tangled abstract fallacy 
Random turmoil builds in me 
I'm addicted to chaos 

Light shined on my path 
Turn bad days into good 
Turn breakdowns into blocks 
I smashed 'em cause I could 

My brain was labored 
My head would spin 
Don't let me down 
Don't give up, don't give in 

The rain comes down 
Cold wind blows 
The plans we made 
Are back up on the road 

Turn up my collar 
Welcome the unknown 
Remember that you said 
"One day you'll walk alone" 

Who will help me up? 
Where's the helping hand? 
Will you turn on me? 
Is this my final stand? 

Oh, oh, oh, oh, oh, oh! 

In a dream I cannot see 
Tangled abstract fallacy 
Random turmoil builds in me 
I'm addicted to chaos, ha! 

Who will help me up? 
Where's the helping hand? 
Will you turn on me? 
Is this my final stand? 
Stand! 

In a dream I cannot see (In a dream I cannot see) 
Tangled abstract fallacy (Tangled abstract fallacy) 
Random turmoil builds in me (Random turmoil builds in me) 
Oh! 
Builds, builds, builds 

In a dream I cannot see (In a dream I cannot see) 
Tangled abstract fallacy (Tangled abstract fallacy) 
Random turmoil builds in me (Random turmoil builds in me) 

I'm addicted to 
I'm addicted to chaos 

Addicted, addicted 
To chaos 
Chaos 

Addicted to chaos 
Chaos...
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

vector<long> vec[4100000];
vector<long> has[4100000];
long n,m,a,b,temp,last,nw;
long aa,bb,ans;

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  vec[v]=has[tl];
 }
 else
 {
  int tm=(tl+tr)/2;
  build(v*2,tl,tm);
  build(v*2+1,tm+1,tr);
  long p1=0;
  long p2=0;
  while (p1<vec[v*2].size()||p2<vec[v*2+1].size())
  {
   if (p1==vec[v*2].size())
   {vec[v].push_back(vec[v*2+1][p2]);++p2;}
   else if (p2==vec[v*2+1].size())
   {vec[v].push_back(vec[v*2][p1]);++p1;}
   else if (vec[v*2][p1]<vec[v*2+1][p2])
   {vec[v].push_back(vec[v*2][p1]);++p1;}
   else
   {vec[v].push_back(vec[v*2+1][p2]);++p2;}
  }
 }
}

long gett(long v,long tl,long tr,long l,long r)
{
 if (l>r)return 0;
 if (l==tl&&r==tr)
 {
//  cout<<tl<<" "<<tr<<" "<<nw<<"#"<<" "<<vec[v].size()<<endl;
  if (vec[v].size()==0)return 0;
  if (vec[v][0]>=nw)return 0;
  long ll,mm,rr;
  ll=0;rr=vec[v].size()-1;
  while (ll<rr)
  {
   mm=ll+rr+1;mm/=2;
   if (vec[v][mm]>=nw)rr=mm-1;
   else ll=mm;
  }
   return ll+1;
 }
 
 long tm=(tl+tr)/2;
 return gett(v*2,tl,tm,l,min(r,tm))+gett(v*2+1,tm+1,tr,max(l,tm+1),r);
}

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>aa>>bb;
    has[aa].push_back(bb);
}

for (int i=1;i<=1000000;i++)
sort(has[i].begin(),has[i].end());

build(1,1,1000000);

for (int i=1;i<=m;i++)
{
    cin>>temp;
    ans=0;
    last=0;
    for (int j=1;j<=temp;j++)
    {
     cin>>nw;
     ans+=gett(1,1,1000000,last+1,nw-1);////
     last=nw;
    }
    nw=1000001;
    ans+=gett(1,1,1000000,last+1,1000000);
    cout<<n-ans<<endl;
}

cin.get();cin.get();
return 0;}