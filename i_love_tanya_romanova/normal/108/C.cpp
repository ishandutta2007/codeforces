/*
Where do I take this pain of mine?
I run but it stays right by my side

So tear me open and pour me out
There's things inside that scream and shout
And the pain still hates me
So hold me until it sleeps

Just like the curse, just like a stray
You feed it once and now it stays
Now it stays

So tear me open but beware
There's things inside without a care
And the dirt still stains me
So wash me until I'm clean

It grips you so hold me
It stains you so hold me
It hates you so hold me
It holds you so hold me
Until it sleeps

So tell me why you've chosen me
Don't want your grip
Don't want your greed
Don't want it

I'll tear me open, make you gone
No more can you hurt anyone
And the fear still shakes me
So hold me until it sleeps

It grips you so hold me
It stains you so hold me
It hates you so hold me
It holds you, holds you
Holds you until it sleeps

Until it sleeps
Until it sleeps
Until it sleeps
Until it sleeps

I don't want it
I don't want it, want it, want it
Want it, want it, no

So tear me open but beware
There's things inside without a care
And the dirt still stains me
So wash me 'til I'm clean

I'll tear thee open, make you gone
No longer will you hurt anyone
And the hate still shapes me
So hold me until it sleeps

Until it sleeps
Until it sleeps
Until it sleeps
Until it sleeps
Until it sleeps
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,k,a,b,c,deg[20000],temp;
vector<long> ans1,ans2,ans3;
vector<pair<long, long> > g[20000];
long lst;

long dfs(long v)
{
 lst=v;
 if (g[v].size()==0)return 1e9;
 return min(g[v][0].second,dfs(g[v][0].first));
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=k;i++)
{
 cin>>a>>b>>c;
 g[a].push_back(make_pair(b,c));
// g[b].push_back(make_pair(a,c));
 deg[b]++;   
}

for (int i=1;i<=n;i++)
{
 if (deg[i])continue;
 if (g[i].size()==0)continue;
 temp=dfs(i);
 ans1.push_back(i);
 ans2.push_back(lst);
 ans3.push_back(temp);
}

cout<<ans1.size()<<endl;
for (int i=0;i<ans1.size();i++)
{
 cout<<ans1[i]<<" "<<ans2[i]<<" "<<ans3[i]<<endl;
}

cin.get();cin.get();
return 0;}