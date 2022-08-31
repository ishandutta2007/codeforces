/*
Media used as a platform
To put things in a better light
Its so easy to have a say
But its hard to tell the truth
Of some ones mind
On a paper
Manipulated to ruin and rule
Don't listen
Don't read
Don't believe
The words they say
My words turned around
My truth became their lies
The truth of the followers
The lies of the honest
Or is it that you just wont see
They are only here
To ruin and rule
Don't listen
Don't read
Don't believe the words they say
Don't listen don't read
Don't believe
The words were written
Do i have to prove you wrong?
Or is it up to yourself
Is it better working eye for an eye
Feel me now
Touch my skin
And turn the switch
To ruin and rule...
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,t,ar[1<<20];
vector<pair<long, long> > block[1000];
long l[1<<20],r[1<<20];
long long ans[1<<20];
long long score;
long long cnt[1<<20];
long tid,nid;

void add(long x)
{
 score-=cnt[x]*cnt[x]*x;
 cnt[x]++;
 score+=cnt[x]*cnt[x]*x;
}

void del(long x)
{
 score-=cnt[x]*cnt[x]*x;
 --cnt[x];
 score+=cnt[x]*cnt[x]*x;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>t;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int i=1;i<=t;i++)
{
 cin>>l[i]>>r[i];
 block[l[i]/bsize].push_back(make_pair(r[i],i));
}

for (int qblock=0;qblock<=200000/bsize;qblock++)
{
 sort(block[qblock].begin(),block[qblock].end());
 if (block[qblock].size()==0)continue;
 for (int i=1;i<=1000000;i++)
  cnt[i]=0;
 score=0;
 tid=block[qblock][0].second;
 for (int i=l[tid];i<=r[tid];i++)
 {
  add(ar[i]);
 }
 ans[tid]=score;
 
 for (int i=1;i<block[qblock].size();i++)
 {
  nid=block[qblock][i].second;
  if (l[tid]<l[nid])
  {
   for (int j=l[tid];j<l[nid];j++)
    del(ar[j]);
  }
  else
  for (int j=l[nid];j<l[tid];j++)
   add(ar[j]);
  
  for (int j=r[tid]+1;j<=r[nid];j++)
   add(ar[j]);
  ans[nid]=score;
  tid=nid;
 }
}

for(int i=1;i<=t;i++)
{
 cout<<ans[i]<<endl;
}

cin.get();cin.get();
return 0;}