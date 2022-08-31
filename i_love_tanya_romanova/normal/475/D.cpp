/*
Hey... oooh...
Sheets of empty canvas, untouched sheets of clay
Were laid spread out before me, as her body once did
All five horizons revolved around her soul, as the earth to the sun
Now the air I tasted and breathed has taken a turn

Ooh, and all I taught her was everything
Ooh, I know she gave me all that she wore
And now my bitter hands shake beneath the clouds
Of what was everything

All the pictures had
All been washed in black, tattooed everything
I take a walk outside, I'm surrounded by some kids at play
I can feel their laughter, so why do I sear?

And twisted thoughts that spin round my head
I'm spinning, oh, I'm spinning
How quick the sun can, drop away
And now my bitter hands cradle broken glass
Of what was everything

All the pictures had
All been washed in black, tattooed everything
All the love gone bad, turned my world to black
Tattooed all I see, all that I am, all I'll be, yeah
Uh huh... uh huh... ooh...

I know someday you'll have a beautiful life
I know you'll be a star in somebody else's sky
But why, why, why can't it be, can't it be mine?
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


long long ar[200000],
tests,s[200000][19];
long long n,ql,qval,l,r,m;

long long gcd(long long a,long long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

long long gett(long long l,long long r)
{
 long ml=0;
 while (l+(1<<ml)-1<=r)++ml;
 --ml;
 return gcd(s[l][ml],s[r-(1<<ml)+1][ml]);
}

map<long, long long> ans;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);


cin>>n;

for (int i=0;i<n;i++)
{
     cin>>ar[i];
     s[i][0]=ar[i];
}   
s[n][0]=1;ar[n]=1;

long lvl=1;
while ((1<<lvl)<=n)
{
  long span=1<<(lvl-1);
  for (int i=0;i+span<=n+1;++i)
  {
   s[i][lvl]=gcd(s[i][lvl-1],s[i+span][lvl-1]);
  }
  ++lvl;
}
 
for (int i=0;i<n;i++)
 {
  ql=i;
  qval=ar[i];
  while (ql<n)
  {
   l=ql;r=n-1;
   while (l<r)
   {
    m=l+r+1;m/=2;
    if (gett(i,m)<qval)// - div
    r=m-1;
    else l=m;
   } 
   //cout<<qval<<" "<<l<<" "<<ql<<endl;
   ans[qval]+=(l-ql+1);
//  ans=max(ans,qval*(l-i+1));
  ql=l+1;
  qval=gcd(qval,ar[ql]);
  }
 }
 
 long x;
 
cin>>tests;
for (;tests;--tests)
{
 cin>>x;
 cout<<ans[x]<<"\n";
}
cin.get();cin.get();
return 0;}