/*
Things I've seen and things I've done
I want you grant all
I have come a long way to become the man I am
Do the deepest angels you will fall
Climbing and screaming for help

There'll be mountains to be done
No more walls too high
Like an eagle you will fly
Higher and higher

You know
That you can touch the sky
You'll be
The one to spread your wings

I'll be the one that conquers soul
Last in line
I'll be the one that's standing tall
Hear my call

After all these years are gone
They find the reach of destiny
You've been patient for so long
But now your aims are near

And if you keep holding on
You will find your way
No reason being on the run
Settle down and stay

I know you can touch the sky
You'll be the one to spread your wings
Like an eagle you will fly
Higher and higher
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
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,m,ff;
string tp[200000];
long val[200000];
long used[200000];
vector<long>o,ans;
set<long> active;

void check(long x)
{
 for (int i=1;i<=m;i++)
 {
  if (tp[i]=="-")
  {
   active.erase(val[i]);
  }
  else active.insert(val[i]);
  if (active.size()>0&&active.find(x)==active.end())return ;
 }
 ans.push_back(x);
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>n>>m;
ff=-1;
for (int i=1;i<=m;i++)
{
 cin>>tp[i]>>val[i];
 if (tp[i]=="-"&&used[val[i]]==0)ff=i;
 if (tp[i]=="-"&&used[val[i]]==0)o.push_back(val[i]);
 used[val[i]]=1;
}

for (int i=1;i<=n;i++)
 if (used[i]==0)ans.push_back(i);
 
if (ff==-1)
{
 check(val[1]);
}
else
{
 for (int i=0;i<o.size();i++)
  active.insert(o[i]);
 check(val[ff]);  
}
sort(ans.begin(),ans.end());
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}