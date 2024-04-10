/*
So I'm the king of all these things
Of this mess I have made
Such a waste, what a shame
My whole life is a fake

Well I'm a bore
And I'm sure
I'm a thorn inside of you
That has torn at you for years

The alcohol
The Demerol
These things never could replace
What a minute with you could do to put a smile on my face

I'm a bore
And I'm sure
I'm a thorn inside of you
That has torn at me for years

I can't get out of this dead skin
(I can't shed my skin)
And I'm not sure where to begin
I can't get under my dead skin
(I can't shed my skin)
Can I sleep 'til then?

Phenobarbital and alcohol
These two surely will do
To knock me out
Keep me down at least a day or two

When I'm awake
I can taste, how bitter I've become
And it's more than I can bare some days
I pray someone will blow me away

Make it quick, but let it burn
So I can feel my life fade
Well, I'm a waste and I can taste, how bitter I've become
And it's more than I can bare

I can't get out of this dead skin
(I can't shed my skin)
And I'm not sure where to begin
(Why can't I begin again)
I can't get under my dead skin
(I can't shed my skin)
Can I sleep 'til then?

I can't get out of this dead skin
And I'm not sure where to begin
I can't get under my dead skin
Can I sleep 'til then?

I can't get out of this dead skin
(I can't shed my skin)
And I'm not sure where to begin
(Why can't I begin again)
I can't get under my dead skin
(I can't shed my skin)
Can I sleep 'til then?
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

long n;
vector<long> v;
long used[1<<20];
long temp;
long ans;
vector<long> av;

long t;

long long pw(long long a,long long b)
{
 if (b==0)return 1;
 if (b%2)return a*pw(a,b-1)%n;
 return pw(a*a%n,b/2);
}

long inverse(long long x)
{
 return pw(x,n-2);
}

long used1[1<<20],used2[1<<20];

bool check()
{
 for (int i=0;i<=n;i++)
  used1[i]=used2[i]=0;
 long long p=1;
 for (int i=0;i<av.size();i++)
 {
  p*=av[i];
  p%=n;
  used1[av[i]]=1;
  used2[p]=1;
 }
 for (int i=0;i<n;i++)
  if (used2[i]==0)
   return false;
 for (int i=1;i<=n;i++)
  if (used1[i]==0)
   return false;
  return true;
}
int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;

if (n==1)
{
 cout<<"YES"<<endl;
 cout<<1<<endl;
 return 0;
}

if (n==4)
{
 cout<<"YES"<<endl;
 cout<<1<<endl;
 cout<<3<<endl;
 cout<<2<<endl;
 cout<<4<<endl;
 return 0;
}

for (int i=2;i*i<=n;i++)
{
 if (n%i==0)
 {
  cout<<"NO"<<endl;
  return 0;
 }
}
/*
for (int i=1;i<=n;i++)
{
 v.push_back(i);
}
do
{
 for (int i=0;i<n;i++)
  used[i]=0;
  temp=1;
 for (int i=0;i<v.size();i++)
 {
  temp=temp*v[i];
  temp%=n;
  used[temp]=1;
 }
 long er=0;
 for (int i=0;i<n;i++)
  if (used[i]==0)
   er=1;
  if (er==0)ans=1;
 if (ans)
 {
  for (int i=0;i<v.size();i++)
   cout<<v[i]<<" ";
 cout<<endl;
 }
  if (ans)break;
}
while (next_permutation(v.begin(),v.end()));
*/
//cout<<ans<<endl;

av.push_back(1);
for (int i=2;i<n;i++)
{
 t=inverse(i-1);
 t=1ll*t*i%n;
// t%=n;
 av.push_back(t);
 used[t]=1;
}

av.push_back(n);

cout<<"YES"<<endl;
for (int i=0;i<av.size();i++)
 cout<<av[i]<<"\n";//" ";

//cout<<check()<<endl;

cin.get();cin.get();
return 0;}