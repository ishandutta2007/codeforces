/*
On a cold night, in the winter winds
I lift my head, and stare to the stars
To find a path that will lead me out
To a place that will heal the scar

Of once a battle that raged long ago
Through the atmosphere surface, we all would go
Destroyer cruisers and our fighter ships
We're on a mission of mercy declared by the script

On our way to meet the Axis Powers
Surprise attack! We all went down
Destroyer cruisers, and our fighter ships
Were wrecked to the ground
There were dead all around, so I pledge I would die
"An eye for an eye" so was it burned in my head
"Vengeance is mine" you'll all be dead!

I built on the trenches beyond anger and sweat
My fighter repaired no need to dispair
With its cruiser engines, and all its armor wear
Off to destroy and kill my enemies
For betrayed we were in the scriptures of peace
Beyond the star of the rising sun

So ends the memory of once was to be
No longer do I live to see
Another time, some other place
No need to face this disgrace
As I believe to be the only one
I should do in myself as they had planned
So I write this log to anyone who finds
Will know that just has been done!
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
//#include <memory.h>

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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,a,b,ar[1200][1200],tr[1200],tc[1200];
vector<pair<long, pair<long, long> > > ans;

void eras(long x)
{
 
 for (int i=1;i<=x;i++)
 {
     if (ar[x][i])--tr[x],--tc[i];
 }
 
 for (int i=1;i<x;i++)
 if (ar[i][x])--tr[i],--tc[x];
  
}

void swapr(long a,long b)
{
 swap(tr[a],tr[b]);
 for (int i=1;i<=n;i++)
 swap(ar[a][i],ar[b][i]);
 ans.push_back(make_pair(1,make_pair(a,b)));    
}

void swapc(long a,long b)
{
 swap(tc[a],tc[b]);
 for (int i=1;i<=n;i++)
 swap(ar[i][a],ar[i][b]);
 ans.push_back(make_pair(2,make_pair(a,b)));
}

void solve(long sz)
{
     long oc;
     for (int i=1;i<=sz;i++)
     if (tc[i]==0)
     oc=i;
     if (oc!=sz)
     swapc(oc,sz);
     
     long orr;
     for (int i=1;i<=sz;i++)
     if (tr[i]>0)
     orr=i;
     
     if (orr!=sz)
     swapr(orr,sz);
     
     eras(sz);
}

int main(){
//freopen("elect.in","r",stdin);
//freopen("elect.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    tr[a]++;tc[b]++;
    ar[a][b]=1;
}

for (int i=n;i>1;--i)
solve(i);

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
}

cin.get();cin.get();
return 0;}