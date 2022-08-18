/*
On a cobweb afternoon
In a room full of emptiness
By a freeway I confess
I was lost in the pages

Of a book full of death
Reading how we'll die alone
And if we're good we'll lay to rest
Anywhere we want to go

In your house I long to be
Room by room patiently
I'll wait for you there like a stone
I'll wait for you there alone

And on my deathbed I will pray
To the Gods and the Angels
Like a pagan to anyone
Who will take me to Heaven

To a place I recall
I was there so long ago
The sky was bruised
The wine was bled
And there you lead me on

In your house I long to be
Room by room patiently
I'll wait for you there like a stone
I'll wait for you there alone, alone

Alone I read
Until the day was gone
And I sat in regret
Of all the things I've done

For all that I've blessed
And all that I've wronged
In dreams until my death
I will wonder on

In your house I long to be
Room by room patiently
I'll wait for you there like a stone
I'll wait for you there alone, alone
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
#define right adsgasgadsg

using namespace std;

long win[300000];
long n,k,ttl;
string st;
bool has[300000][27];
long son[300000][27];
long fwin[300000];
long tsons[500000];

void add(long v,long ps)
{
 if (ps==st.size())return;
 long q=st[ps]-'a';
 if (has[v][q]==0)
 {
  has[v][q]=1;
  son[v][q]=ttl;
  ++ttl;
  tsons[v]++;
 }
 add(son[v][q],ps+1);
}

void dfs(long v)
{
 win[v]=0;
 //cout<<v<<endl;
 
 for (int i=0;i<26;i++)
 {
  if (has[v][i]==0)continue;
  dfs(son[v][i]);
  if (win[son[v][i]]==0)
  win[v]=1;
 }
}

void dfs1(long v)
{
 if (tsons[v]==0)
 fwin[v]=1;
 
// cout<<v<<endl;
 
 for (int i=0;i<26;i++)
 {
  if (has[v][i]==0)continue;
  dfs1(son[v][i]);
  if (fwin[son[v][i]]==0)
  fwin[v]=1;
 }
}


int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
ttl=1;
for (int i=1;i<=n;i++)
{
 cin>>st;
 add(0,0);
}

dfs(0);
dfs1(0);

//cout<<win[0]<<" "<<fwin[0]<<endl;

if (fwin[0]==1&&win[0]==1)cout<<"First"<<endl;// l-l-...-l-w
else if (win[0]==0)// lose all way
cout<<"Second"<<endl;
else if (k%2==1)cout<<"First"<<endl;
else cout<<"Second"<<endl;

cin.get();cin.get();
return 0;}