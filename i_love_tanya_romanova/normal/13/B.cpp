/*
Rise thy horns
For I'm at one with the dark
Divine presence ascends
Touching the forehead ov God

Hark, I was not, I have become
In rapture, in vengeance, in blood
From word into flesh
From man into God

Strive ever to more
So spake the wisdom ov snake
Hold up thyself
Sayeth the law ov the brave

Beyond all I am
Let it be known
Within my blood fire stirs
Thee I invoke, the unspoken one

As the wolf among the sheep
Yet cower I do not
Victorious, glorious
Constantly thirsting

And as the anger fuels
My heart and will
No longer fear
That which feeble men fear

No rest for conquerors
Legions of typhoon set await
Conquering child ov Mars
Breathes out war formula

Ain soph aur
Protect my ways
Enlighten my paths
Consume me with thy rays

I, the heart ov tiphareth is waiting
The center and secret ov the sun
I invoke the sothis rites
As day and night I'm reborn
We shall all be one with the flames
From above, from above
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

using namespace std;

struct pt
{
 long x;
 long y;
 
 bool operator==(pt&xx)
 {
  return x==xx.x&&y==xx.y;
 }
};

struct seg
{
 pt a;
 pt b;
};

seg s[4];

long tests,ans;

bool hc(seg a,seg b)
{
 if (a.a==b.a)return true;
 if (a.b==b.b)return true;
 if (a.a==b.b)return true;
 if (a.b==b.a)return true;
 return false;
}

bool onl(pt a,seg b)
{
 long tx,x1,x2;
 tx=a.x;
 x1=b.a.x;
 x2=b.b.x;
 if (x1>x2)swap(x1,x2);
 if (tx<x1||tx>x2)return false;
 tx=a.y;
 x1=b.a.y;
 x2=b.b.y;
 if (x1>x2)swap(x1,x2);
 if (tx<x1||tx>x2)return false;
 long long s=1ll*(b.b.x-a.x)*(b.a.y-a.y)-1ll*(b.b.y-a.y)*(b.a.x-a.x);
// cout<<s<<endl;
 return (s==0);
}

double gd(pt a,pt b)
{
 double d=(a.x-b.x+.0)*(a.x-b.x)+(a.y-b.y+.0)*(a.y-b.y);
 return sqrt(d);
}

bool solve1(pt p,seg qq)
{
     double d1=gd(p,qq.a);
     double d2=gd(p,qq.b);
     if (d1*4<d2-eps)return false;
     if (d2*4<d1-eps)return false;
     return true;
}

double sl(pt p1,pt p2,pt p3, pt p4)
{
 double l=gd(p1,p2)*gd(p3,p4);
 double ss=1ll*(p2.x-p1.x)*(p4.x-p3.x)+1ll*(p2.y-p1.y)*(p4.y-p3.y);
 return acos(ss/l);
}

double gang(seg a,seg b)
{
 if (a.a==b.a)return sl(a.a,a.b,b.a,b.b);
 if (a.a==b.b)return sl(a.a,a.b,b.b,b.a);
 if (a.b==b.a)return sl(a.b,a.a,b.a,b.b);
 if (a.b==b.b)return sl(a.b,a.a,b.b,b.a);
}

long solve(seg a,seg b,seg c)
{
 if (hc(a,b)==0)return false;
// cout<<"^"<<endl;
 double qq=gang(a,b);
 if (qq<eps||qq>M_PI/2)return false;
 if (onl(c.a,a)&&onl(c.b,b))return solve1(c.a,a)&solve1(c.b,b);
 if (onl(c.a,b)&&onl(c.b,a))return solve1(c.a,b)&solve1(c.b,a);
 return false;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
 for (int i=0;i<3;i++)
 {
  cin>>s[i].a.x>>s[i].a.y>>s[i].b.x>>s[i].b.y;
 }
 ans=0;
 if (solve(s[0],s[1],s[2]))ans=1;
 if (solve(s[1],s[2],s[0]))ans=1;
 if (solve(s[2],s[0],s[1]))ans=1;
 if (ans)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}

cin.get();cin.get();
return 0;}