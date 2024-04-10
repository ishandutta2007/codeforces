/*
The end
Spent my whole life dreaming
Waiting for the end
My end
Gave myself no reason
For the violence in my hands

Fuck the dreams I'm holding onto
Fuck the path that lies ahead
Fuck your ego
Fuck your comfort
Fuck it all until it's dead

Fuck it all [x4]

The time has come
For you to pay
For all you've done
Our public execution
Violence has come
Until this revolution
You will pay with your blood

Feel the failure
It's easy for you to run
Screaming
Staring at the power of the god

Fuck the wings that lie before us
Fuck the bloodbath has began
Fuck excuses
Fuck denial
Fuck it all until it's dead

Fuck it all [x4]

The time has come
For you to pay
For all you've done
Our public execution
Violence has come
Until this revolution
You will pay with your blood

Your time has expired
Destroying your empire
Your time has expired
Destroying your empire

Fuck the wings that lie before us
Fuck the bloodbath has began
Fuck excuses
Fuck denial
Fuck it all until it's dead

Fuck it all [x4]

The time has come
For you to pay
For all you've done
Our public execution
Violence has come
Until this revolution
You will pay with your blood

Your time has expired
Destroying your empire 
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
//#define bs 1000000007
#define bsize 256

using namespace std;

long n,m,q,o;
vector<long> g[300000];
long p;
long online[500000];
long aa[500000],bb[500000];
string tp[500000];
long deg[500000];
vector<long> heavy;
bool isheavy[600000];
long ans[500000];
long hmap[500000];
long ar[1000][30000];

bool friends(long a,long b)
{
 a=hmap[a];
 return ((ar[a][b/16]&(1<<(b%16)))>0);
}

void setfriends(long a,long b,long val)
{
// cout<<"%"<<endl;
 a=hmap[a];
// cout<<a<<" "<<b/16<<endl;
 long q=(1<<(b%16));
 if (val)ar[a][b/16]+=q;
 else ar[a][b/16]-=q;
}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m>>q;
cin>>o;
for (int i=1;i<=o;i++)
{
 cin>>p;
 online[p]=1;
}

for (int i=1;i<=m;i++)
{
 cin>>aa[i]>>bb[i];
 tp[i]="A";
 deg[aa[i]]++;
 deg[bb[i]]++;
}

for (int i=m+1;i<=m+q;i++)
{
 cin>>tp[i];
 cin>>aa[i];
 if (tp[i]!="C"&&tp[i]!="O"&&tp[i]!="F")cin>>bb[i];
 if (tp[i]=="A")deg[aa[i]]++,deg[bb[i]]++;
}

for (int i=1;i<=n;i++)
if (deg[i]>260)
{
 heavy.push_back(i);
 isheavy[i]=1;
 hmap[i]=heavy.size()-1;
}

for (int i=1;i<=m+q;i++)
{
//    cout<<"%"<<endl;
 if (tp[i]=="C")// calc
 {
  if (isheavy[aa[i]])
  cout<<ans[aa[i]]<<endl;
  else
  {
   long q=aa[i];
   long tans=0;
   for (int j=0;j<g[q].size();j++)
   {
    long v=g[q][j];
    if (online[v])++tans;
   }
   cout<<tans<<endl;
  }
 }
 
 if (tp[i]=="O")// online 
 {
  long q=aa[i];
  online[q]=1;
  for (int j=0;j<heavy.size();j++)
  {
   long v=heavy[j];
   if (friends(v,q))
   ++ans[v];
  }
 }
 
 if (tp[i]=="F")// offline
 {
  long q=aa[i];
  online[q]=0;
  for (int j=0;j<heavy.size();j++)
  {
   long v=heavy[j];
   if (friends(v,q))
   --ans[v];
  }
 }
 
 if (tp[i]=="A")
 {
  long q,v;
  q=aa[i];
  v=bb[i];
  
  //cout<<"%"<<q<<" "<<v<<endl;
  
  if (isheavy[q])
  {
//   cout<<"%"<<endl;
   setfriends(q,v,1);
   if (online[v])++ans[q];
  }
  else
  g[q].push_back(v);
//  cout<<"%"<<endl;
  if (isheavy[v])
  {
   setfriends(v,q,1);
   if (online[q])++ans[v];
  }
  else g[v].push_back(q);
 }
 
  if (tp[i]=="D")
 {
  long q,v;
  q=aa[i];
  v=bb[i];
  if (isheavy[q])
  {
   setfriends(q,v,0);
   if (online[v])--ans[q];
  }
  else
   for (int j=0;j<g[q].size();j++)
    if (g[q][j]==v)g[q].erase(g[q].begin()+j);
  
  if (isheavy[v])
  {
   setfriends(v,q,0);
   if (online[q])--ans[v];
  }
  else 
   for (int j=0;j<g[v].size();j++)
    if (g[v][j]==q)g[v].erase(g[v].begin()+j);
 }
 
}

cin.get();cin.get();
return 0;}