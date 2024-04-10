/*
Loathsome
Glum is commonplace
Lonely
Longing for a face
Dwelling in the shadows
There's a darker side still
Once what was wide open
Is closed and unfulfilled

Acceptance
A need that I can't understand
Some uninvited guest
Is whispering demands
Damage

Private and off the beaten track
Bulwarked, so as not to get shellacked
As I sit in solitary confinement
Which I choose
Bewildered and stumped
By the many ways I lose

Some uninvited guest is tugging at my hand
Sap the energy and corrode the order of the day
Pigeon feet touch the ground, mind is disarray
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
#define bs 1000000007
#define bsize 256
 
using namespace std;

long ar[2000000][5],n;
long l[200000],r[2000000],v[2000000],ans;
vector<long> R[1000000],V[1000000];
long ansl,ansr;
vector<long> av;

void update(long v,long L,long R,long l,long r,long val)
{
 if (l>=L&&r<=R)
 {
  ar[v][1]+=val;
  ar[v][2]+=val;
  if (ar[v][3]==0)ar[v][3]=l;
  return;
 }
 long mid=l+r;
 mid/=2;
 if (L<=mid)update(v*2,L,R,l,mid,val);
 if (R>mid)update(v*2+1,L,R,mid+1,r,val);
 if (ar[v*2][1]>ar[v*2+1][1])
 {
  ar[v][1]=ar[v*2][1]+ar[v][2];ar[v][3]=ar[v*2][3];
 }
 else
 {
  ar[v][1]=ar[v*2+1][1]+ar[v][2];ar[v][3]=ar[v*2+1][3];
 }
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>l[i]>>v[i]>>r[i];
 V[v[i]].push_back(i);
 R[r[i]].push_back(i);
}

for (int i=0;i<=300000;i++)
{
 for (int j=0;j<V[i].size();j++)
 {
  update(1,l[V[i][j]],v[V[i][j]],0,300000,1);
 }
 if (ar[1][1]>=ans)
 {
  ans=ar[1][1];ansl=ar[1][3];
  ansr=i;
 }
 for (int j=0;j<R[i].size();j++)
 {
  update(1,l[R[i][j]],v[R[i][j]],0,300000,-1);
 }
}

for (int i=0;i<n;i++)
{
 if( l[i]<=ansl&&r[i]>=ansr&&v[i]>=ansl&&v[i]<=ansr)
  av.push_back(i+1);
}
cout<<av.size()<<endl;
for (int i=0;i<av.size();i++)
{
     if (i)cout<<" ";
     cout<<av[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}