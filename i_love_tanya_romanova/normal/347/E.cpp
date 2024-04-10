/*
Breathing slowly, mechanical heartbeat
losing contact with the living
Almighty TV plugged, hybrid empty brain
don't see anything real in the game
The tension is building constantly
No reason just a reflex I have, driven by clockwork
I try to keep an eye open
And I realize I haven't closed my eyes in a long time

Neglected emotions lead to catastrophic voyage on the other side
I have been given so much stress and lack of confidence
I've been given the gift of so small hope deep inside
I haven't closed my eyes in a long time, I am trying

I cannot stomach these forms and colors anymore
but I'm here to continue, after all I have been through
I try to keep my eyes open, I am realizing
This life and death more precious than anything

I won't bring no material in the after life
Take no possessions, I would rather travel light
I'm of this kind that kills all day
but I don't know yet how to die

Art of dying, is the way to let all go
Within I practice in the secret of my soul
My shape in the reflector
has now for ever, a life on it's own
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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,ar[1200000],l,r,rem;
long minn[1200000];
long fst;
long mmove;
long temp,ans;
long tmove;
long iters;
int main(){
//freopen("police.in","r",stdin);
//freopen("police.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i<=n;i++)
{
 cin>>ar[i];
//ar[i]=i;
}

sort(ar+1,ar+n+1);

cin>>r>>l;

for (int i=l;i<=r;i++)
minn[i-l]=1200000000;

for (int i=1;i<=n;i++)
{
    if (i>1&&ar[i]==ar[i-1])continue;
    //if (ar[i]==1)continue;
    rem=l%ar[i];
    if (rem==0)fst=l;
    else fst=l+(ar[i]-rem);
//    cout<<fst<<endl;
    for (int q=fst;q<=r;q+=ar[i])
    if (q-ar[i]>=l)minn[q-l]=min(minn[q-l],q-ar[i]);
    
}

mmove=r-1;

for (int i=1;i<=n;i++)
if(r-r%ar[i]>=l)mmove=min(mmove,r-r%ar[i]);

//cout<<mmove<<endl;

while (r>l)
{
 ++ans;
 tmove=mmove-1;
 for (int i=r;i>mmove;--i)
 tmove=min(tmove,minn[i-l]);
  
 r=mmove;
 mmove=tmove;
}
//cout<<iters<<endl;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}