/*
Right here, right now
I'm looking back
To the road that I've been traveling
That brought me here
I remember Heaven, I saw Hell
And now the hour for my return
Is drawing near

Endless is the moment
As if time is standing still
Fractions of a minute
Like a thousand years
Countless are the memories
Of all I used to know
I'm ready to go

Big city lights
Are painting the skies
My mind is set
I'm raising the eyes
And by all means
I'm coming home
To Megatropolis

Nowhere my restless heart could find
All I've ever longing for
Some peace of mind
Now I'm standing here where all began
Now the world has turned
And I became a different man

Nothing to regret

Boldly I was going to
Where no man's gone before
Used to be a thunderbird
At distant shores
Countless are the memories
Of my adventurous past
Now I am back
Back to stay at last

Big city lights
Are painting the skies
My mind is set
I'm raising the eyes
And by all means
I'm coming home

Now I keep on wondering
What the future holds for me
I'm meeting fate so easefully
Countless are the visions
Of my future road
But right now I'm here
And I'm help for good

Big city lights
Are painting the skies
My mind is set
I'm raising the eyes
And by all means
I'm coming home
To Megatropolis

Megatropolis
To Megatropolis
And by all means
I'm made it home

Megatropolis I have returned
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

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long long ways[77][2100],ans[77][2100],c[2100][2100];
long long tests,a,b,fact[21000];

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

c[0][0]=1;
fact[0]=1;
for (int i=1;i<=1200;i++)
fact[i]=fact[i-1]*i%bs;

for (int i=1;i<=1000;i++)
 for (int j=0;j<=i;j++)
  if (j==0||j==i)
   c[i][j]=1;
    else c[i][j]=(c[i-1][j]+c[i-1][j-1])%bs;
   
ways[0][0]=1;
for (int ad=1;ad<=1000;ad++)
{
 for (int ttl=60;ttl>=0;ttl--)
  for (int old=0;old<=1000;old++)
  {
   ways[ttl+1][old+ad]+=ways[ttl][old];
   while (ways[ttl+1][old+ad]>=bs)
    ways[ttl+1][old+ad]-=bs;
  }
}


for (int ttl=1;ttl<=60;ttl++)
 for (int i=0;i<=1000;i++)
  for (int j=i;j<=1000;j++)
   ans[ttl][j]=(ans[ttl][j]+ways[ttl][i]*c[j-i+ttl][ttl])%bs;

for (int ttl=1;ttl<=60;ttl++)
 for (int i=0;i<=1000;i++)
  ans[ttl][i]=ans[ttl][i]*fact[ttl]%bs;

cin>>tests;
for (;tests;--tests)
{
 cin>>a>>b;
 swap(a,b);
 if (a>65)cout<<0<<endl; else
 cout<<ans[a][b]<<endl;
// cout<<ways[a][b]<<endl;
}
   
cin.get();cin.get();
return 0;}