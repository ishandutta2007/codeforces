/*  
Late at night all systems go
You have come to see the show
We do our best You're the rest
You make it real you know
There is a feeling deep inside
That drives you fuckin' mad
A feeling of a hammerhead
You need it oh so bad

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
Whiplash

Bang your head against the stage
Like you never did before
Make it ring Make it bleed
Make it really sore
In a frenzied madness
with your leather and your spikes
Heads are bobbing all around
It is hot as hell tonight

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
Whiplash

Here on the stage the Marshal noise
is piercing through your ears
It kicks your ass kick your face
Exploding feeling nears
Now is the time to let it rip
To let it fuckin' loose
We are gathered here to be with you
Cause this is what we choose

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
Whiplash

The show is through the metal is gone
It is time to hit the road
Another town Another gig
Again we will explode
Hotel rooms and motorways
Life out here is raw
But we will never stop
We will never quit
cause we are Metallica

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
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
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,m,x,y,preb[10000],prew[10000];
long ans[10000][3];
char zr[1100][1100];
long tb[11000],tw[11000];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>x>>y;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
cin>>zr[i][j];

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
 if (zr[i][j]=='#')tb[j]++; else tw[j]++;
}

for (int i=1;i<=m;i++)
{
    preb[i]=preb[i-1]+tb[i];
    prew[i]=prew[i-1]+tw[i];
}

for (int i=0;i<=m;i++)
ans[i][0]=ans[i][1]=1000000000;

ans[0][0]=ans[0][1]=0;

for (int i=0;i<=m;i++)
for (int nw=i+1;nw<=m;nw++)
if (nw-i>=x&&nw-i<=y)
{
 ans[nw][1]=min(ans[nw][1],ans[i][0]+prew[nw]-prew[i]);
 ans[nw][0]=min(ans[nw][0],ans[i][1]+preb[nw]-preb[i]);                     
}

cout<<min(ans[m][0],ans[m][1])<<endl;

cin.get();cin.get();
return 0;}