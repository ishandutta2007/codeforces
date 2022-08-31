/*
Welcome to our fortress tall
Take some time to show you around
Impossible to break these walls
For you see the steel is much too strong
Computer banks to rule the world
Instruments to sight the stars

Possibly I've seen too much
Hangar 18 I know too much.

Foreign life forms inventory
Suspended State of cryogenics
Selective amnesia's the story
Believed foretold but who'd suspect
The military intelligence
Two words combined that can't make sense

Possibly I've seen too much
Hangar 18 I know too much.
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long qq;
long long l,mm,r;
long long lx,rx,ly,ry,ta,tb;
long long n,m,x,y,a,b;
long long span;
long long stepp;

long long gcd(long long a,long long b)
{while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

bool cp(long long mid)
{
     ta=mid*a;tb=mid*b;
     lx=max(0ll,x-ta);
     rx=min(n,x+ta);
     ly=max(0ll,y-tb);
     ry=min(m,y+tb);
     if (lx+ta<=rx&&ly+tb<=ry)return true;
     return false;
}

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>x>>y>>a>>b;

qq=gcd(a,b);
a/=qq;b/=qq;

l=0;
r=1000000000;

while (l<r)
{
 mm=l+r+1;
 mm/=2;
 if (cp(mm))l=mm;
 else r=mm-1;     
}

mm=cp(l);

span=ta;
rx-=ta;
stepp=span/2+(span%2>0);
lx=min(rx,max(lx,x-stepp));
span=tb;
ry-=tb;
stepp=span/2+(span%2>0);
ly=min(ry,max(ly,y-stepp));
cout<<lx<<" "<<ly<<" "<<lx+ta<<" "<<ly+tb<<endl;

cin.get();cin.get();
return 0;}