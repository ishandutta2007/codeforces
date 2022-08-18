/*
Got out of bed about 3 PM thought it was a holiday
Then my boss called just to tell me
I'm late and he's giving my job away
Well I took me a walk to the liquor store
so I could drink away my blues
Spent my last ten bucks, then I dropped the bottle
and I broke it all over my shoes
So I got home to find the power's shut off,
there was someone knocking at my door
It was my landlord serving an eviction notice
'cause my checks are bouncing off the floor
I pounded my head up against the wall
thinking what else could go wrong
But this was only the beginning to a real bad day,
it wasn't gonna be a lot of fun

I knew I should have never gotten out of bed
'Cause of the rain cloud above my head
I'm down on my luck and it's plain to see
So tell me why does this happen to me?

When it rains it pours, when it rains it pours on me
When it rains it pours, and there's a storm moving in on me
When it rains it pours, raining down on only me
When it rains it pours, when it rains it pours

I drove across town to go see a friend
when I heard a siren on my tail
It turned out I had a warrant for my arrest
and I couldn't even post the bail
So I'm sittin' in a cell for 48 hours
keepin' company with thieves and drunks
I'm free to go but my car's impounded
and I'm thinkin' 'bout becoming a monk
So I'm wandering aorund in a catatonic daze
now barely a shell of a man
I look like I live out of a shopping cart
and I'm picking up aluminum cans
I staggered my way to an overpass
and fell to the dirt asleep
I figured out tomorrow is a new day
and maybe I could buy myself a life real cheap
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
//#include <memory.h>

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
//#define N 120000

using namespace std;

long long n,m,k;

long long gett(long long span, long long cuts)
{
 if (cuts<=0)return span;
 ++cuts;
 if (cuts>span)return -1;
 return span/cuts;
}

long long solve()
{
 if (n-1+m-1<k)return -1;
 long long res=0;
  for (long long i=0;i<=40000;i++) 
  res=max(res,n/(i+1)*gett(m,k-i));
  
  long long cdo;
  
  for (long long i=1;i<=40000&&i<=n;i++)
  {
   cdo=n/i-1;
   res=max(res,i*gett(m,k-cdo));
  }
  return res;
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
cout<<solve()<<endl;
//cout<<n*m-solve()*(k+1)<<endl;

cin.get();cin.get();
return 0;}