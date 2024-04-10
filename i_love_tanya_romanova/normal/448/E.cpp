/*
Indecisive government
Regardless of brutal punishment
Indestructible regiment
Twice as many lives

Perversion never too bizarre
Can't remember who we are
Influenced us to get this far
Emotions paralyzed

Monotony provokes the escalation
Terrifying industry protect departed nations
Can't get back together again
Leaving Europe after the rain

Acceptance of neo-fascist
Persecuting anarchists
Put the wrong ones on the list
Let the new age begin

Monotony provokes the escalation
Terrifying industry protect departed nations
Can't get back they're going insane
Leaving Europe after the rain

Come on

Can't look at the world the way I did before
Can't ignore they've all mutated into materialistic parasites
Can't forget the pictures I saw on television
Can't close my eyes on this abstract spectrum

Tomorrow I'll be gone

Forcing them to support without asking
Imprisoned in factories for a lifetime
Reasons are becoming meaningless
Optimism leaves the bitter taste of hopelessness

Tomorrow I'll be gone
Tomorrow I'll be gone

Monotony provokes the escalation
Terrifying industry protect departed nations
Can't get back together again
Leaving Europe after the rain

A complex keeps the industries
In motion for some new disease
Bound to those who still resist
Yet harder to find

Monotony provokes the escalation
Terrifying industry protect departed nations
Can't get back together again
Leaving Europe after the rain
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long done;
long long n,k;

set<long long> was;
map<long long, long> rem;
vector<set<long long> > v;

void add(long long x)
{
 if (done)cout<<" ";
 cout<<x;
 ++done;
}

void solve(long long n,long long iter)
{
 if (done==100000)return;    
 if (iter==0){add(n);return;}
 if (n==1){add(n);return;}
 set<long long> divs;
 set<long long>::iterator it;
 if (was.find(n)!=was.end())
  divs=v[rem[n]];
 else
 {
  was.insert(n);
  rem[n]=was.size()-1;
  for (long long i=1;i*i<=n;i++)
  if (n%i==0)
  {
   divs.insert(i);
   divs.insert(n/i);
  }
  v.push_back(divs);
 }
 
 for (it=divs.begin();it!=divs.end();it++)
 {
  solve((*it),iter-1);
 }
}

int main(){
//freopen("pattern.in","r",stdin);
//freopen("pattern.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
solve(n,k);

cout<<endl;

cin.get();cin.get();
return 0;}