/*
Tongues, lost in me
yours be the sharp and the vile
Glide neath my skin
storm through my nerves

I bury the nomad years
hours in the earth
couldn't exorcise these searing, pecking tongues
Immune you say
yet venom strikes in strangest guises
as the viper in our eyes
Tongue, throat, tongue
slayer of the word and stealer of wisdom

A monumental reign of terrors
throats slit up to stain the target
We're food for the hounds of trauma,
prey to the crows of stress

No power left to retrieve my stolen language
filtered through the illiterate fingers of death

Flies
let sickness be poured
from the cupped hands of bedlam

On account of their brightness
I made friends with the word and the moon
went with the tide and left for the sound
of dead instruments thrown out of tune

The red square patterns, dragonrise and
evenclaw
decoying from pandemonic symmetry

Let ring
a dissonant note in the music of the spheres
the streak of promise in the nuclear sky
These whipping black tongues
aching to lick me back to life
to inject their truths within me
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

long n,a,b;
long ar[200000];
long ans[200000];
vector<pair<long, long> > v;

void solve()
{
 if (a==b)
 {
 for (int i=1;i<=n;i++)
 {if (i-1)cout<<" "; if (i<=a)cout<<1;
  else cout<<2;}
  cout<<endl;
  return;
 }
 if (a>b)
 {
  for (int i=1;i<=n;i++)
  v.push_back(make_pair(ar[i],i));
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
 }
 else
 {
  for (int i=1;i<=n;i++)
  {
   v.push_back(make_pair(ar[i],-i));
  }
  sort(v.begin(),v.end());
 }
 for (int i=0;i<b;i++)
 {
  if (v[i].second<0)v[i].second=-v[i].second;
  ans[v[i].second]=2;
 }
 for (int i=1;i<=n;i++)
 {
  if (i-1)cout<<" ";
  if (ans[i]==0)cout<<1;else cout<<2;
 }
 cout<<endl;
}

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>a>>b;
for (int i=1;i<=n;i++)
cin>>ar[i];
solve();

cin.get();cin.get();
return 0;}