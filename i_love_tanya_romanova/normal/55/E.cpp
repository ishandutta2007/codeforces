/*
One drop too much might break the camels back
that ain't the case this time cause I didn't even snap
Done it all had enough climbed
a mountain that's a wrap
Singing and dancing around my funeral pyre
Pyro-messiah bound to set the world on fire

[Chorus:]
Unleashing sick fire
Ignite the flames when I'm long gone
Keep bleeding
Feel it burning
Light up the sky with sick fire

This path is paved with roses,
they never cease to bloom
With joy and laughter I waltz towards my doom
I inhale the haze of Hades
Escape without notice - I know it can be a bitch
Fear not I'll leave a spark -
that just can't be extinguished

[Chorus]

Tell me how could you have failed
If you never even tried to burn
a hole in our memories
Without wings one cannot fly,
Without hear the flesh won't fry
Without the air I cannot breathe
Now I've told you why reincarnate with the flames

(Unleashing sick fire, sick fire)

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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long n,x[1<<20],y[1<<20],tx,ty,tests,ans,r;
long long gs(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
 return (x3-x1)*(y2-y1)-(y3-y1)*(x2-x1);
}
long long sp;

long long gss(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
 return fabs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
}

bool outside(long long tx,long long ty)
{
 long long s1=0;
 for (int i=3;i<=n;i++)
 {
  s1+=gss(x[1],y[1],x[i-1],y[i-1],x[i],y[i]);
 }
 long long s2=0;
 for (int i=1;i<=n;i++)
  s2+=gss(tx,ty,x[i],y[i],x[i+1],y[i+1]);
 //cout<<s1<<" "<<s2<<endl;
  return (s1!=s2);
}

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>x[i]>>y[i];
for (int i=n+1;i<=n*2;i++)
 x[i]=x[i-n],y[i]=y[i-n];

cin>>tests;
for (;tests;--tests)
{
 cin>>tx>>ty;
 if (outside(tx,ty))
 {
  cout<<0<<//"^"<<
  endl;continue;
 }
 
 ans=1ll*n*(n-1)*(n-2)/6;
 r=2;
 for (int i=1;i<=n;i++)
 {
  if (r==i)++r;
  while (r<n+i&&gs(x[i],y[i],x[r],y[r],tx,ty)>0)++r;
  --r;
  sp=r-i;
  ans-=sp*(sp-1)/2;
//  cout<<i<<" "<<r<<endl;
  
 }
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}