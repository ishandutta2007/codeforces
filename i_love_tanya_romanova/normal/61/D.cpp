/*
In my hour of need
Ha you're not there
And though I reached out for you
Wouldn't lend a hand

Through the darkest hour
Grace did not shine on me
It feels so cold, very cold
No one cares for me

Did you ever think I get lonely
Did you ever think that I needed love
Did you ever think to stop thinking
You're the only one that I'm thinking of

You'll never know how hard I tried
To find my space and satisfy you too

Things will be better when I'm dead and gone
Don't try to understand, knowing you I'm probably wrong

But oh how I lived my life for you
Still you'd turn away
Now as I die for you
My flesh still crawls as I breathe your name
All these years I thought I was wrong
Now I know it was you
Raise your head raise your face your eyes
Tell me who you think you are, who ?

I walk, I walk alone
Into the promised land
There's a better place for me
But it's far, far away
Everlasting life for me
In a perfect world
But I gotta die first
Please God send me on my way

Time has a way of taking time
Loneliness is not only felt by fools
Alone I call to ease the pain
Yearning to be held by you, alone, so alone, I'm lost
Consumed by the pain
The pain, the pain, the pain

Won't you hold me again
You just laughed, ha, ha, bitch
My whole life is work built on the past
But the time has come when all things shall pass
This good thing passed away

In my darkest hour
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long long  n,a,b,c;
long long arp[200000];
vector<pair<long, long> > g[200000];
long long dist[200000];
long long s,bst;//[200000];

void dfs(long v)
{
 arp[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i].first;
  if (arp[q]==0)
  {
   arp[q]=1;
   dist[q]=dist[v]+g[v][i].second;
   dfs(q);
  }
 }
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<n;i++)
{
    cin>>a>>b>>c;
    g[a].push_back(make_pair(b,c));
    g[b].push_back(make_pair(a,c));
    s+=c;
    s+=c;
}

dfs(1);

bst=-1;
for (int i=1;i<=n;i++)
bst=max(bst,dist[i]);
cout<<s-bst<<endl;

cin.get();cin.get();
return 0;}