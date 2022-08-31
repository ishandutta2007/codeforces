/*
Lost, lost in a maze, can't rearrange, my mind is unclear
Fade, fade into black, but not fade away
Who should I turn to, where should I go, six feet too deep in the ground
How long can I take this, how long will it last
I can't stop re-living my past
Beyond the sunless sky, so far away, beyond the sunless sky
Torn, I've torn you in two, what can I do, I'm lost in confusion
Time, I've run out of time, the clock ticks away, just keeping time... an illusion
I wallow in the darkness, I suffer through the pain, ripping through the madness
Til life's been re-gained
I'm nothing but a shell of what I used to be
I'm washed upon the shore of my checkered past
No one would believe all the things I've seen
Deliver me from darkness, I'm fading fast
It's all been lies, time after time
There will be no more sunless skies
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

vector<string> vec;
long n,m;
long arp[20000];
long clr;
vector<long> g[20000];
string st1[20000],st2[20000];
long un;
map<string, long> mapp;
long a,b;
vector<vector<bool> > ar;
short ttl[10001][10001];
vector<string> uns;
long ans[11000],aw[11000];
void dfs(long v)
{
arp[v]=clr;
for (int i=0;i<g[v].size();i++)
{
    long q=g[v][i];
    if (arp[q])continue;
    dfs(q);
}
}

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>m;
for (int i=1;i<=m;i++)
{
    cin>>st1[i]>>st2[i];
    vec.push_back(st1[i]);
    vec.push_back(st2[i]);
}

sort(vec.begin(),vec.end());

for (int i=0;i<vec.size();i++)
{
    if (i==0||vec[i]!=vec[i-1])
    {++un;mapp[vec[i]]=un;uns.push_back(vec[i]);}
}

ar.resize(un+1);
for (int i=0;i<ar.size();i++)
ar[i].resize(un+1);

for (int i=0;i<ar.size();i++)
for (int j=0;j<ar.size();j++)
ar[i][j]=0;

for (int i=1;i<=m;i++)
{
 a=mapp[st1[i]];
 b=mapp[st2[i]];
 ar[a][b]=1;
 ar[b][a]=1;
 g[a].push_back(b);
 g[b].push_back(a);   
}

for(int i=1;i<=un;i++)
if (arp[i]==0)
{
 ++clr;
 dfs(i);
}

for (int ii=1;ii<=m;ii++)
{
 a=mapp[st1[ii]];
 b=mapp[st2[ii]];
 for (int i=1;i<=un;i++)
 if (ar[b][i]==1&&ar[a][i]==0&&i!=a&&i!=b)
  ttl[a][i]++;
 swap(a,b);
 for (int i=1;i<=un;i++)
 if (ar[b][i]==1&&ar[a][i]==0&&i!=a&&i!=b)
  ttl[a][i]++;
 
}

/*for (int i=1;i<=un;i++)
cout<<mapp[st1[i]]<<" "<<mapp[st2[i]]<<" %"<<endl;
*/

/*for (int i=1;i<=un;i++)
{
    for (int j=1;j<=un;j++)
    cout<<ttl[i][j]<<" ";
    cout<<endl;
}*/
for (int i=1;i<=un;i++)
for (int j=1;j<=un;j++)
{
    if (j==i)continue;
    if (ar[i][j])continue;
   // if(arp[i]!=arp[j])continue;
    if (ttl[i][j]>ans[i]){ans[i]=ttl[i][j];aw[i]=1;}
    else if (ttl[i][j]==ans[i])aw[i]++;
}

cout<<uns.size()<<endl;
for (int i=1;i<=un;i++)
cout<<uns[i-1]<<" "<<aw[i]<<endl;

cin.get();cin.get();
return 0;}