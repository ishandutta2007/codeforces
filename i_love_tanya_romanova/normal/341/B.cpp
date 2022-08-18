/*
We're the day birds
Deciding to fly against the sky
Within our dreams, we all wake up
To kiss the ones who are born to die

We're the greying herds
Hurting each other with our lies
Within our dreams, we all wake up
To kiss the ones who are born...
Born to die
Born to die

The drum fish
They beached themselves in Harakiri
The blackbirds
They fell in thousands from the sky
Their red wings
Streaming down from the higher seas
Deflected by the ground
They crowned the sun

They crowned the sun (They crowned the sun)
They crowned the sun (They crowned the sun)
But I believe that they are free
When their time was done (Their time was done)
They were drowned by the only one (They crowned the sun)
But I believe that they are free
Washed by the sun

Our statues
The soaring edifice of our times
Detracted from the ways of the wise
The future will view all history as a crime
So father, tell us when is the time to rise

They crowned the sun (They crowned the sun)
They crowned the sun (They crowned the sun)
But I believe that they are free
When their time was done (Their time was done)
They were drowned by the only one (They crowned the sun)
But I believe that they are free

We're the day birds
Deciding to fly against the sky
Within our dreams, we all wake up
To kiss the ones who are born to die

We're the greying herds
Hurting each other with our lies
Within our dreams, we all wake up
To kiss the ones who are born...
Born to die

They crowned the sun (They crowned the sun)
They crowned the sun (They crowned the sun)
But I believe that they are free
When their time was done (Their time was done)
They were drowned by the only one (They crowned the sun)
But I believe that they are free
They crowned the sun (They crowned the sun)
They crowned the sun (They crowned the sun)
But I believe that they are free
And we believe that they are free
Cause I believe that they are me
Washed by the sun
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
#include <memory.h>

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
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

/*
long n,ar[200000],comps,arp[1000];
vector<long> g[1000];

void dfs(long v)
{
     arp[v]=1;
     for (int i=0;i<g[v].size();i++)
     {
         long q=g[v][i];
         if (arp[q])continue;
         dfs(q);
     }
}
*/

long n,d[500000],l,r,m,answ,ar[500000];

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
/*
cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

for (int iter=1;iter<=n;iter++)
for (int i=1;i<n;i++)
if (ar[i]>ar[i+1])
{
                  g[ar[i]].push_back(ar[i+1]);
                  g[ar[i+1]].push_back(ar[i]);
                  cout<<ar[i]<<" "<<ar[i+1]<<endl;
                  swap(ar[i],ar[i+1]);
}

for (int i=1;i<=n;i++)
if (arp[i]==0)
{
 ++comps;
 dfs(i);
}

cout<<comps<<endl;
*/

cin>>n;
for (int i=0;i<n;i++)
cin>>ar[i];

for (int i=0;i<=n;i++)
d[i]=1000000000;

d[0]=-100000000;

for (int i=0;i<n;i++)
{
 l=0;
 r=n;
 while (l<r)
 {
       long m=l+r+1;m/=2;
       if (d[m]<ar[i])l=m;else r=m-1;
 }
 if (d[l]<ar[i]&&ar[i]<d[l+1])
 d[l+1]=ar[i];   
}

for (int i=1;i<=n;i++)
if (d[i]<100000000)
answ=i;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}