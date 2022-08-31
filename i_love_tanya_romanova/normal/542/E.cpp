/*
I've lost a part of me
Tell your friends to sharpen their teeth
There's a few quid to be made

And my soul's a sorry state
So come on down, you're empty lovers.
Wolves come out of the woodwork
And the snakes start to sing.

Do you feel the chair,
Clawing at the back of your neck?
And start to spell,
Did you really think that you could fix me?
We'll sell your bones for another roll.
We'll sharpen your teeth.
Tell yourself that it's just business.

Wolves come out of the woodwork.
Leeches come from out of the dirt.
Rats come out of the holes they call home,
And I fall apart.
And the snakes start to sing.

Don't say I'm better off dead,
Cause heaven's full and hell won't have me.
Won't you make some room in your bed?
Well you could lock me up in your heart,
And throw away the key.
Won't you take me out of my head?

I'm just a would've been, could've been,
Should've been, never was and never ever will be.
We'll sharpen your teeth.
Tell yourself that it's just business.
Would've been, could've been,
Should've been, never was, and never ever will be.
Wolves come out of the woodwork,
And the snakes start to sing.

Wolves come out of the woodwork.
Leeches come from out of the dirt.
Rats come out of the holes they call home,
And I fall apart.
And the snakes start to sing.

If you can't soar with the eagles
Then don't fly with the flock.
Are you still getting high?
Did you catch your own reflection,
In the knife my mother held?
Or the hell in my father's eyes?

If you can't soar with the eagles
Then don't fly with the flock.
Are you still getting by?
Was I your knight in shining armor?
The apple of your eye?
Or just a step to climb?

If you can't soar with the eagles
Then don't fly with the flock.
Are you still getting high?
Did you catch your own reflection
In the knife my mother held?
Or the hell in my father's eyes?

If you can't soar with the eagles,
Then don't fly with the flock.
Are you still getting by?
Was I your knight in shining armor?
Or the apple of your eye?
Or just a step, a fucking step to climb
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,m,ar[1<<10][1<<10];
int a,b;
int used[1<<10];
int ans;
int mx;

void trace(int v)
{
    used[v]=1;
    for (int i=1;i<=n;i++)
     if (ar[v][i]<1e6)
      mx=max(mx,ar[v][i]);
    for (int i=1;i<=n;i++)
     if (ar[v][i]<1e6&&used[i]==0)
      trace(i);
}

int fail;

void dfs(int v,int color)
{
    used[v]=color;
    for (int i=1;i<=n;i++)
    {
        if (ar[v][i]>1e6)continue;
        if (v==i)continue;
        if (used[v]==used[i]){fail=1;return;}
        if (used[i])continue;
        dfs(i,3-color);
    }
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  ar[i][j]=1e9;

for (int i=1;i<=n;i++)
 ar[i][i]=0;
 
for (;m;--m)
{
    cin>>a>>b;
    ar[a][b]=ar[b][a]=1;
}

for (int i=1;i<=n;i++)
{
    if (used[i]==0)
     dfs(i,1);
    if (fail)
    {
        cout<<-1<<endl;
        return 0;
    }
}

for (int k=1;k<=n;k++)
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
   ar[i][j]=min(ar[i][j],ar[i][k]+ar[k][j]);

for (int i=1;i<=n;i++)
 used[i]=0;

for (int i=1;i<=n;i++)
{
    if (used[i])continue;
    mx=0;
//  cout<<i<<endl;
    trace(i);
    ans+=mx;
}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}