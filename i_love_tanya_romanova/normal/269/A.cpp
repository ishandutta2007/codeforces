/*
So just like that you're fucking dead and gone
You can only wear a crown of thorns for so long
We built an empire and you took the throne
But you built it from bayonets and sat there alone
I hope your queen was worth it,
Do you still serve her on your knees?
Because you sat when the world was at your feet,
Just slept while we lived the dream

You won't miss the water,
Till the river runs dry
You won't miss the sunset,
Till it burns out the sky
You won't miss what you have,
Till it's finally lost
But you don't miss a bastard,
When you're bearing his fucking cross

Blacklist
Nothing but a blacklist
With friends like you,
There's no need for enemies
With friends like you,
There's no need for anything

Blacklist
You're nothing but a blacklist

Well, truth be told
I'm a little bit gutted
I mean you were always a prick,
But we still seemed to love you
We started this together and it should have stuck
But there's no room for a useless, miserable fuck
Well I know I was a cunt in the final days
It just filled me with venom, filled me with rage
To see someone not give a shit,
Despite of all of this
I won't see you around, I couldn't give a fuck
I'd rather slit my wrists than keep in touch
You're on my blacklist and there's nothing left to say
We're finished breaking our bones, dragging dead fucking weight
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,k[200000],a[200000],mk;
map<long long,long long> ttl;
long long temp,span;

bool check(long long x)
{
      for (int i=1;i<=n;i++)
      {
          temp=ttl[k[i]];
          if (k[i]+30<x)continue;
          span=x-k[i];
          span=(1ll<<(span*2));
          if (span<temp)return false;
      }
      return true;
}

int main(){
//freopen("test.in","r",stdin);
//freopen("test.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>k[i]>>a[i];
    mk=max(mk,k[i]);
    ttl[k[i]]+=a[i];
}

for (int i=mk+1;i<=mk+30;i++)
{
 if (check(i)){cout<<i<<endl;break;}   
}

cin.get();cin.get();
return 0;}