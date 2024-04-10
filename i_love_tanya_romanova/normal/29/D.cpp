/*
Looking at you I see her face
Through all these years, just waiting
It all catches up to you when you slow down

I'm back in that yard, tasting that shame
Of pushing her down, Of kids and her games
...their strongholds

We had a bigger world - we had a better view
I guess I never fully realized then
What she lost when I cut that loss

So she filled the void with unearthly friends
Voices of hers - greater... than us

We had a bigger world - we had a better view
I wish she'd never told us about her voices
We were strong, we were much too strong

Never forgive - never forget

We picked and pierced, we ripped and we tore
We hit and we scratched to make in her a hole
Glares and eyes - whispers and notes
Attached to her every pose

We fed her shouts
For the collection of her voices
I was too weak to collect
But so, it turned out, was she
Both paid in soul for the cutting of that loss

Their ugly truth
Outnumbered by far her beautiful dream
And I closed my eyes
Were her eyes in yours already when we met?
Am I still paying debts to recover Life?

Now I can see she proved to be right
As she was called down
It's sad though...
...that I turned out to be one of her voices.
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

long d[500][500],n,w[600][500];
vector<long> way;
long t;
long a,b,ttl;

void solve(long a,long b)
{
 vector<long> p;
 while (b!=a){p.push_back(b);b=w[a][b];}
 reverse(p.begin(),p.end());
 for (int i=0;i<p.size();i++)cout<<" "<<p[i];
}

int main(){
//freopen("substr.in","r",stdin);
//freopen("substr.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
  d[i][j]=1e9;
  
for (int i=1;i<n;i++)
{
 cin>>a>>b;
 d[a][b]=1;
 d[b][a]=1;
 w[a][b]=a;
 w[b][a]=b;
}

way.push_back(1);
while (cin>>t)
{ 
 if (t==0)break;
 way.push_back(t);
}
way.push_back(1);

for (int k=1;k<=n;k++)
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
   if (d[i][k]+d[k][j]<d[i][j])
   {
    d[i][j]=d[i][k]+d[k][j];
    w[i][j]=w[k][j];
   }

ttl=0;
for (int i=1;i<way.size();i++)
 ttl+=d[way[i-1]][way[i]];
 if (ttl>2*n-1)
 cout<<-1<<endl;
 else
 {
  cout<<1;
  for (int i=1;i<way.size();i++)
   solve(way[i-1],way[i]);
   cout<<endl;
 }
 
cin.get();cin.get();
return 0;}