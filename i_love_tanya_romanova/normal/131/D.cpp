/*
Don't forget me now, laughing through the tears
For somewhere, somehow, life becomes the years
You speak to millions, but you're talking to no one
Home is the place that you can't walk away from
You seek our opinions but listen to no one
You throw up your hands and tell me that it's all done

We intend to rise through motion, speak through silence
And fight 'til the ocean
No more glimmering hopes or commotions
Our dedication's to each other in devotion

No pretending now, your heart is open and you reappear
For somewhere, somehow, you dropped the ball and you ran with fear
You speak to millions, but talk to no one
Home is the place you can't walk away from
You seek opinions but listen to no one
You throw up your hands and tell me that it's all done

We intend to rise through motion, speak through silence
And fight 'til the ocean
No more glimmering hopes or commotions
Our dedication's to each other in devotion

We intend to speak through peace
Cross the ocean and wake up in the east
Make Jerusalem home for all creeds
Unsheathe your swords and take the eagle's peace

I want you, I need you
I pray that God absolves you
Can't live this life without you
I've cleared the coffin for two

I want you, I need you
I pray that God absolves you
Can't live this life without you
I've cleared the coffin for two

Come, today is another day
Come, your hairs are no longer grey
Come, we're clearing the runway
There's no turning back from the path for the chosen ones

We intend to rise through motion, speak through silence
And fight 'til the ocean
No more glimmering hopes or commotions
Our dedication's to each other in devotion

We intend to scream through peace
Cross the ocean and wake up in the east
Make Jerusalem home for all the creeds
Unsheathe your swords and take the eagle's peace
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256
#define clone agsdahfaassdg

using namespace std;

long n;
vector<long> g[5000];
long a,b;
long pv[5000];
long arp[5000];
long d[5000];
queue<long> qu;
long temp,q;

void getcycle(long v)
{
     d[v]=0;
     long q=pv[v];
     while (q!=v){d[q]=0;q=pv[q];}
}

void dfs(long v,long par)
{
     arp[v]=1;
     for (int i=0;i<g[v].size();i++)
     {
         long q=g[v][i];
         if (q==par)continue;
         if (arp[q]==1){pv[q]=v;getcycle(q);return;}
         if (arp[q]==2)continue;
         pv[q]=v;
         dfs(q,v);
     }
     arp[v]=2;
}


int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

for (int i=1;i<=n;i++)
d[i]=10000;


dfs(1,-1);

for (int i=1;i<=n;i++)
if (d[i]==0)qu.push(i);
while (qu.size())
{
      temp=qu.front();
      qu.pop();
      for (int i=0;i<g[temp].size();i++)
      {
          q=g[temp][i];
          if (d[q]<=d[temp]+1)continue;
          d[q]=d[temp]+1;
          qu.push(q);
      }
}

for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<d[i];
}
cout<<endl;
cin.get();cin.get();
return 0;}