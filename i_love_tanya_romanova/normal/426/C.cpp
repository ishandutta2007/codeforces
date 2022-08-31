/*
Here and now you wonder
Looking at the past
Start to realize
Time's running fast
Thinking of the bitterness
Decisions made and chances missed
But here you are
Still standing strong

Locked up in adaption
Like a tiger in the cage
Tainted by an anger
Tangled up
Your life is in need to be purged

And the battle rages on
Iron warrior
Keep on standing strong
And the battle rages on
And when you're back against the wall
Never surrender
Stand up and fight them all

The struggle for survival
You're sick of all those goddamned days
Stumbling like a blind man through the maze

Routine and conformity
Have taken on control
Regain your independence
Drag yourself - drag yourself out of the hole

And the battle rages on
Iron warrior
Keep on standing strong
And the battle rages on
And when you're back against the wall
Never surrender
Stand up, fight them all

Routine and conformity
Have put you in that hole
Time to free the tiger
Release yourself
Time to be back in control

And the battle rages on
Iron warrior
Keep on standing strong
And the battle rages on
And when you're back against the wall
Never surrender
Stand up and fight them all

And the battle rages on
Iron warrior
Keep on standing strong
And the battle rages on
And when you're back against the wall
Never surrender
Stand up and fight them all
Fight them all
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define bsize 256

using namespace std;

vector<long> f,has;
long ar[20000];
long n,k,ans,s;
long ts;

void ad(long x)
{
long q=0;
while (q<has.size()&&has[q]<=x)++q;
has.insert(has.begin()+q,x);
}

void er(long x)
{
 long q=0;
 while (f[q]!=x)++q;
 f.erase(f.begin()+q);
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>k;

ans=-1e9;

for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int start=1;start<=n;start++)
{
 f.clear();
 
 for (int i=1;i<=n;i++)
 f.push_back(ar[i]);
 sort(f.begin(),f.end());
 reverse(f.begin(),f.end());
 
 has.clear();
 s=0;
 for (int i=start;i<=n;i++)
 {
  ad(ar[i]);
  s+=ar[i];
  er(ar[i]);
  /*for (int j=0;j<has.size();j++)
  cout<<has[j]<<" ";
  cout<<endl;
  */
  ts=s;
//  cout<<s<<endl;
  for (int j=0;j<k&&j<has.size()&&j<f.size();j++)
   if (has[j]<f[j])
   ts=ts-has[j]+f[j];
  ans=max(ans,ts);
 }
 
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}