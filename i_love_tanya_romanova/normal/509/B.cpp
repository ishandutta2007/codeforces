/*
Love songs keep pumpin' on my radio
You split on Monday
Took your machine that kept me afloat
Now your back, it's Tuesday

I call it love insanity
I call it my reality

She mine
Mine all mine
She mine
Mine all mine

Cool kids keep movin' as the car explodes
Roll around on Sunday
Threw down and loose that's just the way to go
Poppin' pills like candy

I call it love insanity
I call it my reality

She mine
Mine all mine
She mine
Mine all mine

Run away, oh, from own mistakes
Break through from the chains

She mine
Mine all mine
She mine
Mine all mine

She mine
(Love songs keep pumpin' on my radio)
Mine all mine
(You split on Monday)

She mine
(Cool kids keep movin' as the car explodes)
Mine all mine
(Roll around on Sunday)
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
#define MAG 10000

using namespace std;

long n,k,maxx,minn,ar[1<<10],ans[1<<10][1<<10];

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
maxx=0;
minn=1e9;

for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 minn=min(ar[i],minn);
 maxx=max(ar[i],maxx);
}

if (maxx-minn>k)
{
 cout<<"NO"<<endl;
 return 0;
}

for (int i=1;i<=n;i++)
{
 for (int j=1;j<=minn;j++)
  ans[i][j]=1;
 for (int j=minn+1;j<=ar[i];j++)
  ans[i][j]=j-minn;
}
cout<<"YES"<<endl;
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=ar[i];j++)
 {
  if (j>1)cout<<" ";
  cout<<ans[i][j];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}