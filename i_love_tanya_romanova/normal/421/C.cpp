/*
Answer me - Open your heart
Answer me - Take me in your arms
Answer me

I'm all by myself, just the wind in my hair
I take another step but I don't really care
All my thoughts go out to you
I'm lost in nowhere, there's nothing left to do

I take another breath but my heart seems to freeze
I'm losing the ground so won't you answer please
I'm a broken man with nothing left to loose
I'm down on my knees you made me pay my dues

Answer me - Hear my call - Open your heart
Answer me - Release my pain - Take me in your arms
And all these tears I've cried for you
I'm sendin' out my love to you
Now that you're gone

I open the door but it seems to be locked
I'm runnin' round in circles, I realize that I'm trapped
And all that I feel is that I'm runnin' insane
My wounds don't seem to heal
And the pain remains the same

You take away my breath
And I'm slaved by your thoughts
It feels like I'm deaf and I'm wasting all my words
I'm a broken man but my arms are open wide
Tryin' my best to make things turn out right

Answer me - Hear my call - Open your heart
Answer me - Release my pain - Take me in your arms
And all these tears I've cried for you
I'm sendin' out my love to you
Now that you're gone

Answer me - Open your heart
Answer me - Take me in your arms
Answer me
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