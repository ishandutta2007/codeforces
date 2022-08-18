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

long long n,m,a,q;
vector<long long> v1,v2;
long long l,r;

long long check(long long x)
{
 long long of=0;
 for (int i=0;i<x;i++)
 {
     if (v1[n-x+i]<v2[i])
     of+=v2[i]-v1[n-x+i];
 }
 return of;
}

long long check1(long long x)
{
 long long tc=0;
 
 for (int i=0;i<x;i++)
 tc+=v2[i];
 if (a>tc)return 0;
 return tc-a;
}

int main(){
//freopen("gnu.in","r",stdin);
//freopen("gnu.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>a;
for (int i=1;i<=n;i++)
{
    cin>>q;
    v1.push_back(q);
}
sort(v1.begin(),v1.end());

for (int i=1;i<=m;i++)
{
 cin>>q;   
 v2.push_back(q);
}

sort(v2.begin(),v2.end());

l=0;
r=min(v2.size(),v1.size());

while (l<r)
{
 m=l+r+1;
 m/=2;
 if (check(m)<=a)l=m;else r=m-1;     
}

cout<<l<<" "<<check1(l)<<endl;


cin.get();cin.get();
return 0;}