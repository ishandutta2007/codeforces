/*
The victorious reign!
We are the glorious order,
Bound together by blood and by faith,
Successors to a tradition.
Are we the vessels of death?

Sworn to this alliance, we only speak of truths,
Heretical in its shape, is it profane?

Devotees to the cause, sacrilegious in its form

We are your purification, united by purpose and will,
Affiliates of an allegiance, are we the blasphemous creed?

We are the infamous legion, a covenant of supposed heresy,
Conceivers of a hierarchy, Are we the disciples from hell?

Sworn to this alliance, we only speak of truths,
Heretical in its shape, is it profane?

Devotees to the cause, Sacrilregious in it's form,
Sworn to this alliance, We only honor him.
Heretical in its shape, is it profane?

Devotees to the cause, is this profane?
Sacrilegious in its form, is this profane?
What sayest thou o king?
Shall you exercise justice during thou reign?
Or shall thou commit us to the flames? To the flames!

The victorious reign!
The victorious reign!
The victorious reign!
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n,l[200000],r[200000],ar[200000],ans;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int i=1;i<=n;i++)
{
 l[i]=l[i-1]+1;
 if (ar[i]<=ar[i-1])l[i]=1;
}

for (int i=n;i;--i)
{
 r[i]=r[i+1]+1;
 if (ar[i]>=ar[i+1])r[i]=1;
}

for (int i=1;i<=n;i++)
 ans=max(ans,l[i]);
for (int i=1;i<=n;i++)
 ans=max(ans,r[i]);

for (int i=1;i<=n;i++)
 ans=max(ans,l[i-1]+1);
for (int i=1;i<=n;i++)
 ans=max(ans,r[i+1]+1);
/*
for (int i=1;i<=n;i++)
 cout<<l[i]<<" ";
 cout<<endl;
for (int i=1;i<=n;i++)
 cout<<r[i]<<" ";
 cout<<endl;
 */
  
for (int i=2;i<n;i++)
{
 if (ar[i-1]+1<ar[i+1])
 ans=max(ans,l[i-1]+r[i+1]+1);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}