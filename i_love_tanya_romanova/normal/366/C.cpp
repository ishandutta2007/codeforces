/*
The only cribs that we should care for
Are the ones that we are here for
The ones belonging to our children
That do that we do, scar from our wounds

The only cribs that make a difference
Where the magic really happens
Don't come with a Mercedes Benz
Or a wide screen showing nothing
Showing nothing...

I'm sick of home control devices
Sick of sickening home designers
Sick of drugs and gold and strip poles
Sick of homies, sick of poses

Despite the nodding staff that serves you
Despite your name on clothes and perfume
Despite the way the press observes you
You're just people... you're just people...

Successful people
Dressed up people
Smiling people
Famous people
Red carpet people
Wealthy people
Important people -
But still just people

So fuck the million dollar kitchen
Fuck the Al Pacino posters
Fuck the drugs, the gold, the strip poles
Fuck the homies, fuck the poses
Fuck the walls they build around them
Fuck the bedroom magic nonsense
I don't want to hear their voices
As long as they vote with their wallets

Fuck the silly "throw you out" joke
Fuck the framed cigar DeNiro smoked
Fuck their lack of originality and personality
Fuck this travesty
Fuck this new norm
Fuck conformity
Fuck their Kristal
Fuck their sordity
Fuck the way they fuck equality
Fuck their freebie gear
Fuck the ones they wear

(you're just people - you're just people...)

Successful people
Dressed up people
Smiling people
Famous people
Red carpet people
Wealthy people
Important people -
But still just people

Messed up people
Shallow people
Stupid people
Plastic people
Meta people
Theta people
Therapyople
Entropyople

Oh, fuck the ones they wear

I'm cribcaged
Cribcaged

The only cribs that we should care for
Are the ones that we are here for
The ones belonging to our children
That do what we do, scar from our wounds
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,k,ar1[20000],ar2[2000],cost[2000],bst[1200000];

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
cin>>ar1[i];
for (int i=1;i<=n;i++)
cin>>ar2[i];
for (int i=1;i<=n;i++)
cost[i]=ar1[i]-ar2[i]*k;

for (int i=0;i<=1000000;i++)
bst[i]=-1000000000;
bst[100000]=0;
for (int i=1;i<=n;i++)
{
    if (cost[i]<0)
    {for (int j=0;j<=200000;j++)
    if (bst[j]>=0)bst[j+cost[i]]=max(bst[j+cost[i]],bst[j]+ar1[i]);
    }
    else
    {for (int j=200000;j;j--)
    if (bst[j]>=0)bst[j+cost[i]]=max(bst[j+cost[i]],bst[j]+ar1[i]);
    }
}
if (bst[100000]==0)--bst[100000];
cout<<bst[100000]<<endl;

cin.get();cin.get();
return 0;}