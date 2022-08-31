/*
Can you hear the silence?
Can you see the dark?
Can you fix the broken?
Can you feel... can you feel my heart?

Can you help the hopeless?
While, I'm begging on my knees
Can you save my bastard soul?
Will you weep for me?

I'm sorry brothers
So sorry lover
Forgive me father
I love you, mother

Can you hear the silence?
Can you see the dark?
Can you fix the broken?
Can you feel my heart?

Can you feel my heart?
Can you feel my heart?
Can you feel my heart?

I'm scared to get close and I hate being alone
I long for that feeling to not feel at all
The higher I get, the lower I sink
I can't drown my demons, they know how to swim

I'm scared to get close and I hate being alone
I long for that feeling to not feel at all
The higher I get, the lower I sink
I can't drown my demons, they know how to swim

I'm scared to get close and I hate being alone
I long for that feeling to not feel at all
The higher I get, the lower I sink
I can't drown my demons, they know how to swim

Can you feel my heart?

Can you hear the silence?
Can you see the dark?
Can you fix the broken?
Can you feel... can you feel my heart?
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