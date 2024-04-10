/*
From now on there's an abscence of smile

Foul voices welcome me to loneliness
Graceful tunes on her lips have now ceased
This winter's here to surpass all the hopes
And dreams succumb to nightmares and freezing air

Now lonely is my road, path paved with bitter thoughts
Conception of beauty excluded from this heart
Within closed doors no-one speaks, behind barred windows no soul lives
As I walk the soil beneath my feet is crumbling...

She was my sun and now the light has faded away
Night condensing around me, leading astray
Shining image torn down, remembrance of her fades
Left but anguish and shame to haunt me in the shades

Should I be content with the memory of the life I had?
Or is the Hell knowing what we could have beome?
- Quite indifferent as the tides of time have now turned
And the past is buried in a drift of whirling snow

...White sheet covering all things left behind...

And from now on there's an abscence of hope...

She was my sun and now the light has faded away
Night condensing around me, leading astray
Shining image torn down, remembrance of her fades
Left but anguish and shame to haunt me in the shades

So be it, perdition is my home,
Since the day it all came down
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

long long val[2000],ans,n,tans;

void solve(long long n,long long ps,long long tans)
{
 if (ps==0)
 {
  if (n==0)ans=min(ans,tans);
  return ;
 }
 long long l,h;
 l=n/val[ps];
 h=(n+val[ps]-1)/val[ps];
 solve(n-l*val[ps],ps-1,tans+l*ps);
 solve(h*val[ps]-n,ps-1,tans+h*ps);
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

ans=1e18;

for (int i=1;i<=17;i++)
 val[i]=val[i-1]*10+1;

cin>>n;
solve(n,16,0);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}