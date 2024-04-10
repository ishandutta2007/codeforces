/*
Hello
I've waited here for you
Everlong

Tonight I throw myself in two
Out of the red
Out of her head she sang

Come down and waste away with me
Down with me
Slow, how you wanted it to be
I'm over my head
Out of her head she sang

And I wonder
When I sing along with you
If everything could ever feel this real forever
If anything could ever be this good again
The only thing I'll ever ask of you
You've got to promise not to stop when I say when
She sang

Breathe out
So I can breathe you in
Hold you in
And now
I know you've always been
Out of your head
Out of my head I sang

And I wonder
When I sing along with you
If everything could ever feel this real forever
If anything could ever be this good again
The only thing I'll ever ask of you
You've got to promise not to stop when I say when
She sang

And I wonder
If everything could ever feel this real forever
If anything could ever be this good again
The only thing I'll ever ask of you
You've got to promise not to stop when I say when
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
#define N 120000

using namespace std;

long n,m,a,b,deg[2000];
long w[2000];
long er;

long gett(long x)
{
 while (x!=w[x])x=w[x];
 return x;
}

void merg(long a,long b)
{
 a=gett(a);
 b=gett(b);
 if (rand()%2)w[a]=b;
 else w[b]=a;
}

vector<long> tv;
vector<pair<long, long> > ans;
long cycl;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
 w[i]=i;
 
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 ++deg[a];
 ++deg[b];
 if (deg[a]>2||deg[b]>2)er=1;
 if (gett(a)==gett(b))cycl++;
 merg(a,b);
}

if (m<n&&cycl==1)er=1;
if (cycl>1)er=1;

for (int i=1;i<=n;i++)
if (deg[i]>2)er=1;

if(n==1&&m<2)er=0;
if (er)
{
 cout<<"NO"<<endl;
 return 0;
}

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
  {
   if (gett(i)==gett(j))continue;
   if (deg[i]>1||deg[j]>1)continue;
   ans.push_back(make_pair(i,j));
   merg(i,j);
   deg[i]++,deg[j]++;
  }

for (int i=1;i<=n;i++)
{
 if (deg[i]==1)
  tv.push_back(i);
}
for (int i=1;i<=n;i++)
 if (deg[i]==0) ans.push_back(make_pair(i,i));
 
if (tv.size())ans.push_back(make_pair(tv[0],tv[1]));
cout<<"YES"<<endl;
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

cin.get();cin.get();
return 0;}