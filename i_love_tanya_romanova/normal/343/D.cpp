/*
Bombs go off around me
Bullets chase my head
Demonscene hellscape
Try to not get dead

From the cradle I was in
Straight for the firing line
By the teeth of my skin
Dragon and the serpent versus swine

Never quite ready
It just becomes your turn
Evertight steady
No more light to burn

A lie has no feet
Cannot stand alone
A cry in the street
Who cast the first stone

With dirt between my teeth
I made the devil sell his soul
I know that he can bleed
Moon goes dark sun grows cold

Where my mind would take me
Never coming near
Scared my heart would break me
Why am I here
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
#define eps 1e-6
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

long n,a,b,q;
vector<long> g[1000000];
vector<long> events[1000000];
vector<long> quer[1000000];
long tp[1000000];
long arp[1000000];
set<long> Ev;
set<long>::iterator it,itt;
long anss[1000000],anss1[1000000];
vector<long> events1[1000000];

set<long> Ev1[1000000];
long mark[1000000];

void merge(long a,long b)
{
 if (Ev1[mark[a]].size()<Ev1[mark[b]].size())
 {
  swap(mark[a],mark[b]);
 }
 set<long>::iterator it;
 long q,w;
 w=mark[b];
 q=mark[a];
 for (it=Ev1[w].begin();it!=Ev1[w].end();it++)
  Ev1[q].insert(*it);
  Ev1[w].clear();
}

void dfs(long v)
{
     arp[v]=1;
     
     mark[v]=v;
     
     for (int i=0;i<events1[v].size();i++)
     Ev1[v].insert(events1[v][i]);
     
     for (int i=0;i<events[v].size();i++)
     {
         Ev.insert(events[v][i]);
     }
      set<long>::iterator itt;
     
     for (int i=0;i<quer[v].size();i++)
     {
      long p=quer[v][i];
      itt=Ev.upper_bound(p);
      if (itt==Ev.end())
      {
       anss[-p]=0;
      }  
      else
      {
       long qq=(*itt);
       qq=-qq;
//       cout<<qq<<" "<<p<<endl;
  //     cout<<p<<" "<<qq<<" "<<tp[qq]<<endl;
       anss[-p]=qq;
      }
//      cout<<i<<endl;
     } 
      
     for (int i=0;i<g[v].size();i++)
     {
         long q=g[v][i];
         if (arp[q])continue;
         dfs(q);
         merge(v,q);
     }
     
      for (int i=0;i<quer[v].size();i++)
     {
      long p=quer[v][i];
      itt=Ev1[mark[v]].upper_bound(p);
      if (itt==Ev1[mark[v]].end())
      {
       anss1[-p]=0;
      }  
      else
      {
       long qq=(*itt);
       qq=-qq;
//       cout<<qq<<" "<<p<<endl;
  //     cout<<p<<" "<<qq<<" "<<tp[qq]<<endl;
       anss1[-p]=qq;
      }
//      cout<<i<<endl;
}
  
     for (int i=0;i<events[v].size();i++)
     {
         Ev.erase(events[v][i]);
     }
}

int main(){
//freopen("swimming.in","r",stdin);
//freopen("swimming.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

cin>>q;
for (int i=1;i<=q;i++)
{
    cin>>a>>b;
    tp[i]=a;
    
    if (a==1)events[b].push_back(-i);
    else if (a==2)events1[b].push_back(-i);
    else quer[b].push_back(-i);
}

dfs(1);

for (int i=1;i<=q;i++)
if (tp[i]==3)
//cout<<anss[i]<<" "<<anss1[i]<<endl;
{
 if (anss[i]==0&&anss1[i]==0)
 cout<<0<<endl;
 else if (anss[i]>anss1[i])
 cout<<1<<endl;
 else cout<<0<<endl;
}

cin.get();cin.get();
return 0;}