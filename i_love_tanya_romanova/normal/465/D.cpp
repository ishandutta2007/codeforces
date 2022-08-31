/*
(Hey God)
Why are you doing this to me?
Am I not living up to what I'm supposed to be?
Why am I seething with this animosity?
(Hey God)
I think you owe me a great big apology

Terrible lie
Terrible lie
(Everything)
Terrible lie
(My sweet everything)
Terrible lie
(I give you everything)

(Hey God)
I really don't know what you mean
Seems like salvation comes only in our dreams
I feel my hatred grow all the more extreme
(Hey God)
Can this world really be as sad as it seems?

Terrible lie
(Everything)
Terrible lie
(My sweet everything)
Terrible lie
(I give you everything)
Terrible lie
(My sweet everything)

Don't take it away from me, I need someone to hold on to
Don't take it away from me, I need someone to hold on to
Don't take it away from me, I need someone to hold on to
Don't take it away from me, I need someone to hold on to

Don't take it away from me, I need someone to hold on to
Don't take it away from me, I need someone to hold on to
Don't take it away from me, I need you to hold on to
Don't take, don't take, don't take it, don't take it, don't

(Hey God)
There's nothing left for me to hide
I lost my ignorance, security and pride
I'm all alone in a world you must despise
(Hey God)
I believed the promises, your promises and lies

Terrible lie
(Everything)
Terrible lie
(My sweet everything)
Terrible lie
(I give you everything)
Terrible lie
(My sweet everything)
Terrible lie

You made me throw it all away, my morals left to decay
(Terrible lie)
How many you betray you've taken everything
(Terrible lie)
My head is filled with disease, my skin is begging you please
(Terrible lie)
I'm on my hands and knees, I want so much to believe

I give you everything, my sweet everything
I give you everything, my sweet everything
I give you everything, my sweet everything
I give you everything, my sweet everything
There's nothing left for me to hide
(There's nothing left for me to hide)
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
#define bsize 512

using namespace std;

long long ar[10][4];
vector<long> vec[10];
long ans;
long long crd[20][10];
long long anss[20][10];

long long gd(long a,long b)
{
 long long s=0;
 for (int i=0;i<3;i++)
 {
  s+=(crd[a][i]-crd[b][i])*(crd[a][i]-crd[b][i]);
 }
 return s;
}

bool bad(long long x)
{
 if (x==0)return 1;
 long long temp=sqrt(x+0.5);
 
 for (long long i=temp-1;i<=temp+1;i++)
 if (i*i==x)return false;
 return true;
}

bool check()
{
 vector<long long> edges;
 for (int i=0;i<8;i++)
  for (int j=i+1;j<8;j++)
   edges.push_back(gd(i,j));
 sort(edges.begin(),edges.end());
 if (bad(edges[0]))return false;
 for (int i=0;i<12;i++)
  if (edges[i]!=edges[0])return false;
 for (int i=12;i<24;i++)
  if (edges[i]!=edges[0]*2)return false;
 for (int i=24;i<28;i++)
  if (edges[i]!=edges[0]*3)return false;
 return true; 
}

void solve(long dep)
{
 if (dep<8)
 {
  do
  {
   if (ans)break;
   solve(dep+1);
  }while (next_permutation(vec[dep].begin(),vec[dep].end()));
  return;
 }
 for (int i=0;i<8;i++)
 {
  for (int j=0;j<3;j++)
   crd[i][j]=ar[i][vec[i][j]];
 }
 if (check())
 {
  ans=1;
  for (int i=0;i<8;i++)
   for (int j=0;j<3;j++)
    anss[i][j]=crd[i][j];
 }
 return;
}

int main(){
//freopen("highway.in","r",stdin);
//freopen("highway.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<8;i++)
{
 for (int j=0;j<3;j++)
  cin>>ar[i][j];
}

for (int i=0;i<8;i++)
 for (int j=0;j<3;j++)
  vec[i].push_back(j);

solve(1);

if (ans){cout<<"YES"<<endl;
for (int i=0;i<8;i++)
cout<<anss[i][0]<<" "<<anss[i][1]<<" "<<anss[i][2]<<endl;
}
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}