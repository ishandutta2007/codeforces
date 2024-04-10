/*
Don't go looking for snakes you might find them
Don't send your eyes to the sun you might blind them
Haven't I seen you here before?

Oh, watch the puppets dancing
Yeah, see the clowns fall down
Hey, tie your tap shoes tightly
Yeah, wear them into town

See you crawlin;
See you crawlin'

Don't go looking for snakes you might find them
Don't send your eyes to the sun you might blind them
Haven't I seen you here before?
There ain't no heroes here
No, no more

Oh, play the game so nicely
Oh, check, it's your move now
Yeah, we're standing in this jungle
Yeah, with serpents I have found

See you crawlin'
See you crawlin'

Don't go looking for snakes you might find them
Don't send your eyes to the sun you might blind them
Haven't I seen you here before?
Have your heroes disappeared?

See you crawlin'
See you crawlin'

So don't go looking for snakes you might find them
Don't send your eyes to the sun you might blind them
Haven't I seen you here before?
No, there ain't no heroes here

Haven't I seen you here before?
No, there ain't no heroes here

Don't go looking for snakes you might find them
Yeah, Haven't I seen you here before?
Have your heroes disappeared?

Don't send your eyes to the sun you might blind them
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,a,b,tp;
vector<pair<long, long> > g[200000];
long arp[200000];
long subbad[200000];
long bad[200000];
vector<long> ans;

void dfs(long v)
{
     subbad[v]=bad[v];
 arp[v]=1;
 for(int i=0;i<g[v].size();i++)
 {
  long q=g[v][i].first;
  long e=g[v][i].second;
  if (arp[q])continue;
  if (e==2)bad[q]=1;
  dfs(q);
  subbad[v]+=subbad[q];
 }
}

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<n;i++)
{
 cin>>a>>b>>tp;
 g[a].push_back(make_pair(b,tp));
 g[b].push_back(make_pair(a,tp));
}

dfs(1);
for (int i=1;i<=n;i++)
if (bad[i]==1&&subbad[i]==1)
ans.push_back(i);
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}