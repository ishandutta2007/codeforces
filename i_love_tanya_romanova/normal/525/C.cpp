/*
Crying out.
Now you can't escape you are buried in doubt
And it pulls you down
Now you're in too deep you may never get out
Such an awful place

Tear it down
It's almost too late is the end coming now
As you scream out loud
You sever the peace til your truth has been found

Is there nothing left to follow?
Is there nothing left to steal?
Crying out for something more than I've been shown
Knowing none of this is real

Don't close your eyes
Something beautiful is still alive
Don't close your eyes
Never turn away and let it die

I cannot seem to find the answers
Every truth has slipped away
All that riddles me will never cease to be
Still I search this world in vain

Don't close your eyes
Something beautiful is still alive
Don't close your eyes
Never turn away and let it die

Cry out to save tomorrow
It's not too late
Or your heavy heart will follow
You to the grave

This is not the end. This is not the end

Don't close your eyes
Something beautiful is still alive
Don't close your eyes
Never turn away and let it die

We can't hesitate, hope is not too late
For the time has come, what have we become?
Nothing left to do but deny the truth
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
#define right adsgasgadsg
#define free adsgasdg
#define count adsgasdgasdg

using namespace std;

long long n,q,cnt[1<<20],lp,ans;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 cnt[q]++;
}

for (int i=1000000;i;--i)
{
 if (cnt[i]%2&&cnt[i-1]>0)
 {
  cnt[i]--;
  cnt[i-1]++;
 }
}
lp=1000001;
for (int i=1000000;i;--i)
{
 while (cnt[i]>1&&cnt[lp]>1)
 {
  ans+=1ll*i*lp;
  cnt[i]-=2;
  cnt[lp]-=2;
 }
 while (cnt[i]>3)
 {
  ans+=1ll*i*i;
  cnt[i]-=4;
 }
 if (cnt[i]>1&&cnt[lp]<2)
  lp=i;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}