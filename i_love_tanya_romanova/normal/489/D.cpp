/*
Today is what I'm not afraid of.
Its tomorrow that scares the hell out of me.
I can't begin to imagine a world without you.

But my sweet darling, I have to.
But my sweet darling, I have to let you go.
You'll always be with me, but I'm sorry I'm not coming home.
This is what you wanted, its what you wanted.
And now I got to go, so I'm sorry I'm not coming home.

You know what baby
Did I ever tell you that you're the best thing in my life?
So sorry that I turned out to be the worst thing in yours.

Why can't you let go of my hand?
Crack a smile for me, and give me one last thrill.
Why can't you let go of my hand?

We are life and we are death.
We are love and we are hate.
We are good and we are evil.
We are just.. so perfect.

It started with "I think I'm falling in love with you."
It ends with "I'm sorry I'm over you."

You'll always be with me, but I'm sorry I'm not coming home.
This is what you wanted, it's what you wanted.
And now I got to go, so I'm sorry I'm not coming home.

I embrace our life.
I embrace our death.
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
#include <ctime> 
 
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
#define free adsgasdg
 
using namespace std;

long n,m,a,b,ar[3050][3050];
vector<long> g[3050];
long intr;
long ttl[3050][3050];
long long ans;
long v;
int main(){
//freopen("billing.in","r",stdin);
//freopen("billing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
/*if (i<=m/2)
 a=1,b=2;
 else a=2,b=3;
*/ g[a].push_back(b);
 ar[a][b]=1;
}

for (int i=1;i<=n;i++)
 for (int j=0;j<g[i].size();j++)
 {
  intr=g[i][j];
  for (int q=0;q<g[intr].size();q++)
  {
   v=g[intr][q];
   ttl[i][v]++;
  }
 }

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  if (i!=j)
   ans+=1ll*ttl[i][j]*(ttl[i][j]-1)/2;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}