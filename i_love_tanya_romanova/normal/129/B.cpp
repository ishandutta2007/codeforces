/*
No one could ever doubt my rapture
As you too wil son discover
No one will ever cross my love
Deadly consequence will rise above
Lying all alone
Visions of erotic bliss
Feel your warmth from inside your skin
A fever I can not resist
Desire I would kill for you
Right or wrong I'd do anything
True and pure the intensity
Every time death is next to me
Lying all alone
Visions of erotic bliss
Feel your warmth from inside your skin
A fever I can not resist

Anxiously feeling grotesque
Up against your flesh
Forbidden fantasies
Uncontrollable heat
Find yourself all alone and dead
Visions of corroding bliss
Feel the warmth from inside your skin
A sensation I can't resist
*/

#pragma comment(linker, "/STACK:16777216")
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,m,a,b;
vector<long> g[1000];
long deg[1000];
vector<long> v;
long ans;

int main(){
//freopen("cooling.in","r",stdin);
//freopen("cooling.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
 deg[a]++;
 deg[b]++;   
}

while (true)
{
      v.clear();
 for (int i=1;i<=n;i++)
 {
     if (deg[i]==1)
     {
      v.push_back(i);                   
     }
 }
 
 if (v.size()==0)break;
 
 ans++;
 
 for (int i=0;i<v.size();i++)
 deg[v[i]]=0;
 for (int i=0;i<v.size();i++)
 {
  long q=v[i];
  for (int j=0;j<g[q].size();j++)
  {
   long t=g[q][j];
   deg[t]--;
  }
 }
 
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}