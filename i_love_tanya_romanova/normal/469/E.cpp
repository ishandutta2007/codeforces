/*
Dark are the streets, gloom's creeping out of the walls
Dirt comes alive and all the neon lights call
Demons and fools and a lady of black
She's of the kind nighttime insomniac

She sees the prey and she's aware
The times are hard but she don't care

She's a vampire
(Desire darker than black)
She's a vampire
(Reach higher, no turning back)

Her wings are curtains of the night
She knows no wrong or right

Dead are the places where this goddess has been
Cold is the skin that this creature has seen
Her universe is an ocean of blood
Her dining table the cradle of mud

She sees the prey and she's aware
The times are hard but she don't care

She's a vampire
(Desire darker than black)
She's a vampire
(Reach higher, no turning back)

Her wings are curtains of the night
She knows no wrong or right, vampire

The night is blind, the mistress
She is calling you to be by her side forevermore
Follow her until her thirst is sated
An immortal lie, heart blood

Can't help yourself
She's got you paralyzed

So would you kiss the sun goodbye
And give your life to never die?

She's a vampire
(Desire darker than black)
She's a vampire
(Reach higher, no turning back)

She's a vampire
(Desire darker than black)
She's a vampire
(Reach higher, no turning back)
Vampire
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