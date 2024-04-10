/*
Facing the wind as they ride through the sky
Shadows of Mordor black horses they fly
Black shadow king, find the ring.

Search for the Halfling you lords of the dark
The hobbit with Sauron's ring he is your mark
Unholy light, in the night

Black knights of Sauron
Youre made of iron
Black shadows of Mordor
Wield one-eyed shields

Unholy ring wraiths with armour of steel
Kings of the past to no one you kneel
Hearts filled with hate, thats your fate.

Facing the wind as they ride through the sky
Shadows of Mordor black horses they fly
Ride shadow king, find the ring.
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

using namespace std;

long long need,tneed,ans;
long long l,r;

long long sadd(long long a,long long b)
{
 if (a+b>2e18)return 2e18;
 return a+b; 
}

long long smult(long long a,long long b)
{
 if (a==0||b==0)return a*b;
 if (2e18/b<=a)return 2e18;
 return a*b;
}

long digisum(long long x)
{
 long res=0;
 while (x){res+=x%10;x/=10;}
 return res;
}

long long worst;

long long solve(long long x)
{
 if (x<=0)return 0;
 long long res=0;
 long long q,r;
 q=x/10;
 r=x%10;
 res=sadd(res,smult(q,45ll));
 res=sadd(res,smult(10,solve(q-1)));
 res=sadd(res,r*(r+1)/2);
 res=sadd(res,smult(r+1,digisum(q)));
 return res;
}

long long gener()
{
 long long res=0;
 for (int i=1;i<=18;i++)    
 res=res*10+rand()%10;
 return res;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

srand(13133);

/*for (int iter=1;iter<=100000000;iter++)
{
    if (iter%1000==0)cout<<iter<<endl;
    need=gener();
  */  cin>>need;
    
ans=-1;
long long i=0;
while (true)
{
 i++;
 l=i;
 r=1e18;
 tneed=need+solve(l-1);
 while (l<r)
 {
  long long mid=l+r;
  mid/=2;
  if (solve(mid)>=tneed)r=mid;
  else l=mid+1;
 }
 if (solve(l)==tneed){ans=l;break;}
}
//if (i>worst){worst=i;cout<<need<<" "<<worst<<" "<<ans<<endl;}
//}
cout<<i<<" "<<ans<<endl;

cin.get();cin.get();
return 0;}