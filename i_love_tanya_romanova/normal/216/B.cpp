/*
I get up around seven
Get outta bed around nine
And I don't worry about nothin' no
Cause worryin's a waste of my...time

The show usually starts around seven
We go on stage around nine
Get on the bus about eleven
Sippin' a drink and feelin' fine

[Chorus:]

We been dancin' with
Mr. Brownstone
He's been knockin'
He won't leave me alone

I used ta do a little
but a little wouldn't do
So the little got more and more
I just keep tryin'
ta get a little better
Said a little better than before
I used ta do a little
but a little wouldn't do
So the little got more and more
I just keep tryin'
ta get a little better
Said a little better than before

[Chorus]

Now I get up around whenever
I used ta get up on time
But that old man
he's a real muthafucker
Gonna kick him on down the line
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,m,a,b,ar[200][200],ans;
long arp[10000],fl,l;

void dfs(long v,long par)
{
     arp[v]=1;
     l++;
     for (int i=1;i<=n;i++)
     if (ar[v][i]==1)
     {
      if (i==par)continue;
      if (arp[i]==1){fl=1;return;}
      dfs(i,v);
     }
}
int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{cin>>a>>b;ar[a][b]=ar[b][a]=1;}

for (int i=1;i<=n;i++)
if (arp[i]==0)
{
              fl=0;
              l=0;
              dfs(i,-1);
              if (fl)if (l%2)++ans;
}
n-=ans;
if (n%2)++ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}