/*
When the clock strikes the hour
My restless soul has to rise
Unsubstantial, bare of flesh
Chained by unsacred ties
Centuries come, millenniums go
Time has no meaning
So much pain, I'm longing for peace
To find a way to redeem

All alone, I'm walking in the night
Solitude smiles at me in despite

Between the worlds of life and death
A spectre damned to exist

To make amends for my deeds of sin
Done with ferocity long ago
In another time
In another life

Unforgotten
Unforgiven

[Chorus:]
Immortal, punished to be
Nocturnal prison in eternity
Forever banished, banned from the day
Within these walls I have to remain
The immortal ghost

Once I walked beneath the sun
In a distant past where it all begun
Nevermore will I see her again
Enamoured by the chain

Nightbound
Hear my sigh
Eternal rest; let me die
Let me die

[Chorus]

Once again the clock
Is striking the hour
Once again
I have to rise

Once again I'm walking the night
End the pain, let me die
Let me die

[Chorus]
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

long n,L;
vector<long> av;
long ans;
long x[1<<20],b[1<<20];
double l,r,mid;
long par[1<<20];
double best[1<<20];

bool check(double ratio)
{
 for (int i=1;i<=n;i++)
  best[i]=-1e18;
 best[0]=0;
 
 for (int i=0;i<n;i++)
  for (int j=i+1;j<=n;j++)
  {
   double cost=-sqrt(fabs(.0+x[j]-x[i]-L));
   cost+=b[j]*ratio;
   if (best[j]<best[i]+cost)
   {
    best[j]=best[i]+cost;
    par[j]=i;
   }
  }
  return (best[n]>=-eps);
}

int main(){
//freopen("billing.in","r",stdin);
//freopen("billing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>L;
for (int i=1;i<=n;i++)
 cin>>x[i]>>b[i];
 //x[i]=x[i-1]+rand()%100,
 //b[i]=rand()%100;
 
l=0;
r=1e9;
for (int iter=1;iter<=112;iter++)
{
 mid=l+r;
 mid/=2;
 if (check(mid))r=mid;
 else l=mid;
}

//cout<<l<<endl;

l+=1e-9;
check(l);
ans=n;
while (ans>0)
{
 av.push_back(ans);ans=par[ans];
}
//av.push_back(1);
reverse(av.begin(),av.end());
for (int i=0;i<av.size();i++)
{
 if (i)cout<<" ";
 cout<<av[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}