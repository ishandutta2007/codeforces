/*
A heart of gold but it lost its pride
Beautiful veins and bloodshot eyes
I've seen your face in another light
Why'd you have to go and let it die?

Why'd you have to go and let it die?
Why'd you have to go and let it die?
In too deep and out of time
Why'd you have to go and let it die?

A simple man and his blushin' bride
(Why'd you have to go and let it die?)
Interveinious, intertwined
(Why'd you have to go and let it die?)

Heart's gone cold, your hands were tied
(Why'd you have to go and let it die?)
Why'd you have to go and let it die?
(Why'd you have to go and let it die?)

Why'd you have to go and let it die?
Why'd you have to go and let it die?
In too deep and out of time
Why'd you have to go and let it die?

Do you ever think of me?
You're so considerate
Do you ever think of me?
Oh, so considerate

In too deep and lost in time
Why'd you have to go and let it die?
Beautiful veins and bloodshot eyes
Why'd you have to go and let it die?

Heart's gone cold and hands are tied
Why'd you have to go and let it die?
Why'd you have to go and let it die?

Do you ever think of me?
You're so considerate
Did you ever think of me?
Oh, so considerate

In too deep and lost in time
Why'd you have to go and let it die?
Beautiful veins and bloodshot eyes
Why'd you have to go and let it die?

Hearts' gone cold and hands are tied
Why'd you have to go and let it die?
Why'd you have to go and let this die?

Why'd you have to go and let this die?
Why'd you have to go and let this die?
Why'd you have to go and let this die?
Why'd you have to go and let it die?
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
#define N 120000

using namespace std;

long long a,b,n,res;

set<pair<long long, long long> > was;
map<pair<long long, long long> ,long long> win;

long long poww(long long a,long long b)
{
 long long r=1;
 for (int i=1;i<=b;i++)
  if (1e18/a<=r)return 1e18;
  else r*=a;
 return r;
}

long long solve(long long a,long long b)
{
 if (a==1&&((1<<b)>=n))return 0;
 if (a*a>=n&&b==1){
                   if ((n-a)%2)return -1;
                   return 1;
                   }
 if (poww(a,b)>=n)return 1;
 if (was.find(make_pair(a,b))!=was.end())return win[make_pair(a,b)];
 was.insert(make_pair(a,b));
 long long ret=-1;
 ret=max(ret,0-solve(a+1,b));
 ret=max(ret,0-solve(a,b+1));
 win[make_pair(a,b)]=ret;
// cout<<a<<" "<<b<<" "<<ret<<endl;
 return ret;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b>>n;
res=solve(a,b);
if (res==0)cout<<"Missing"<<endl;
else if (res==1)cout<<"Masha"<<endl;
else cout<<"Stas"<<endl;

cin.get();cin.get();
return 0;}