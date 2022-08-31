/*
Justice must be blind
Closed eyes to the massacre
Death and sorrow everyday
Judge hammer is in your face
They will take your life
A Life with pain, a death with pain

Waiting the hour
The end is so near
Waking in horror
There's no Salvation from
Terror and fear
Constantly Madness
No self protection
Lethal injection

Why?
Do I have to pay?
For those who live to betray
Trapped in the Death Row chains
"Lethal Injection
In your brain!"

A sentence of death
On each one of us
Since the day we were born
Nothing is gonna change
Feeling dead when alive
A living hell, a living hell

Convicted by a tainted court!

Trial by money: Corruption
Judged by color: Injustice

You never win in a system build for you to loose,
No chance for your side, unless is their side

No way to be free: Prejudice
Hard to resist: Tyranny

There are no crimes for those who made the law
Walk in the line, but it will lead to suicide
Now pay the price!
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