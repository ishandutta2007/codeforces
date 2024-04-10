/*
After death has taken you from life
You have come to me in the night
The aura of an ancient beauty shining through
Like a goddess of fallen grace
I'm longing for your souls embrace
And all that life has lost i've found in you

The spirit is willing the flesh is weak
Just like a thousand suns it shines on me
The spirit is willing the flesh is weak
For now i'm seeing more than the eye can see

So i wait as i watch the stars
I feel you're near but you're yet too far
Too heal me from the flames that penetrate my mind
I could swear that i 've felt your touch
Your magic presence i need so much
Becomes reality only at night

The spirit is willing the flesh is weak
Just like a thousand suns it shines on me
The spirit is willing the flesh is weak
For now i'm seeing more than the eye can see

As i watch you disappear in silence
Was it really true or just a dream
As morning drags me back to life
And swallowed everything
Illusion killed the angel without wings
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define N 4000005
using namespace std;

long n,l[1700]; long bd[10];
long ans[1<<24]; long sz[1<<24];
long t; long fl;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
cin>>l[i];

for (int mask=0;mask<(1<<n);++mask)
for (int i=0;i<n;i++)
if (mask&(1<<i)){sz[mask]=sz[mask^(1<<i)]+l[i];if (sz[mask]>1000000001)sz[mask]=1000000001;break;}
long tt;
cin>>tt;

for (int i=0;i<tt;i++)
{
    cin>>bd[i];
}

for (int i=0;i<(1<<n);i++)
{
    fl=0;
    for (int j=0;j<tt;j++)
    if (bd[j]==sz[i])fl=1;
    if (fl==1)ans[i]=-1;
}

for (int i=0;i<n;i++)
if (ans[(1<<i)]!=-1)ans[(1<<i)]=1;

long tn;
for (int mask=0;mask<(1<<n);++mask){
//cout<<mask<<endl;
if (ans[mask]>0)
for (int nw=0;nw<n;nw++)
if ((mask&(1<<nw))==0)
{
 tn=(mask|(1<<nw));
 if (ans[tn]==-1)continue;
 ans[tn]+=ans[mask];if (ans[tn]>=bs)
    ans[tn]-=bs;}
}
if (ans[(1<<n)-1]==-1)ans[(1<<n)-1]=0;
cout<<ans[(1<<n)-1]<<endl;

cin.get();cin.get();
return 0;}