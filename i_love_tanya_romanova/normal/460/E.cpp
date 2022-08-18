/*
Wait
If you could ask me to wait
If you could ask me to take a break
Before I fall to pieces and break
If I could ask you to wait
(Wait darling wait on the road to who you really are)
Break
Break
(I'm driven too far)
Break
(If you want to know me just break darling break)
If you dissect me
(If I could ask you to break)
And search through the debris
(But I can't ask you to break)
You'll find my northern star leads to where you are

This wreck you see is still me
I'm just driven too far
Driven too fast
Driven too long
Driven too hard

Driven too fast
Driven too long
Driven too hard
Driven too far
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

long n,r;
long bst;
vector<long> av;
vector<pair<long, long> > p;
long er;
vector<long> o;

long gg(long a,long b)
{
 return (p[a].first-p[b].first)*(p[a].first-p[b].first)+(p[a].second-p[b].second)*(
 p[a].second-p[b].second);
}

long gd(long x,long y)
{
 return x*x+y*y;
}

long gett(vector<long> v)
{
 long res=0;
 for (int i=0;i<v.size();i++)
  for (int j=0;j<v.size();j++)
   res+=gg(v[i],v[j]);
  return res;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>r;
for (int i=-r;i<=r;i++)
 for (int j=-r;j<=r;j++)
 {
  er=0;
  if (gd(i,j)>r*r)er=1;
  if (gd(i-1,j)<=r*r&&gd(i+1,j)<=r*r)er=1;
  if (gd(i,j-1)<=r*r&&gd(i,j+1)<=r*r)er=1;
  if (er==0)
   p.push_back(make_pair(i,j));
 }

//cout<<p.size()<<endl;

bst=0;
for (int i=0;i<n;i++)
if (i%2)av.push_back(0);else av.push_back(p.size()-1); //av.push_back(0);

bst=gett(av);

for (int i=0;i<p.size();i++)
 o.push_back(i);
 
vector<long> o1;
for (int i=0;i<n;i++)
 o1.push_back(i);
 
srand(477);

while (1.0*clock()/CLOCKS_PER_SEC<2.9)
{
 random_shuffle(o.begin(),o.end());
 random_shuffle(o1.begin(),o1.end());
 
 vector<long> v;
 for (int i=0;i<n;i++)
  v.push_back(rand()%p.size());
 long cur=0;
 long opt=0;
 
 while (opt==0){
  cur=gett(v);
   for (int ii=0;ii<n;ii++){
       long i=o1[ii];
   opt=1;
   long grad=0;
   long eng=0;
   
   for (int npp=0;npp<p.size();npp++)
   {
    long np=o[npp];
    eng=grad=0;
    for (int j=0;j<v.size();j++)
    {
     if (j!=i)eng+=gg(v[j],np);
     grad+=gg(v[j],v[i]);
    }
    if (eng>grad)
    {
     opt=0;
    cur+=eng-grad;
    v[i]=np;
    }
   }
   
    if (cur>bst)
    {
    bst=cur;
    av=v;
    }
  }
 }
}

cout<<bst/2<<endl;
for (int i=0;i<av.size();i++)
 cout<<p[av[i]].first<<" "<<p[av[i]].second<<endl;
 
 
cin.get();cin.get();
return 0;}