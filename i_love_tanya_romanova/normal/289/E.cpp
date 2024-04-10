/*
Your empty walls...
Your empty walls...
Pretentious attention
Dismissive apprehension
Don't waste your time, on coffins today
When we decline, from the confines of our mind
Don't waste your time, on coffins today

Don't you see their bodies burning?
Desolate and full of yearning
Dying of anticipation
Choking from intoxication

Don't you see their bodies burning?
Desolate and full of yearning
Dying of anticipation
Choking from intoxication

I want you
To be
Left behind those empty walls
Taunt you
To see
From behind those empty walls

Those empty walls
When we decline, from the confines of our mind
Don't waste your time, on coffins today

Don't you see their bodies burning?
Desolate and full of yearning
Dying of anticipation
Choking from intoxication

Don't you see their bodies burning?
Desolate and full of yearning
Dying of anticipation
Choking from intoxication

I want you
To be
Left behind those empty walls
Taunt you
To see
From behind those empty walls
Want you to be
Left behind those empty walls
I taunt you
To see
From behind those empty walls

From behind those empty walls
From behind those empty walls
The walls
From behind those empty walls

I loved you
Yesterday, before
You killed my family.

Don't you see their bodies burning?
Desolate and full of yearning
Dying of anticipation
Choking from intoxication

Don't you see their bodies burning?
Desolate and full of yearning
Dying of anticipation
Choking from intoxication

I want you
To be
Left behind those empty walls
Taunt you
To see
From behind those empty walls
Want you to be, left behind those empty walls
Taunt you
To see
From behind those empty walls
From behind those empty walls
From behind those fucking walls
From behind those goddamn walls
Those walls...
Those walls...

*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n;
vector<long> v,bv;
long long s,bans;
long long mpow,q,usd[2000000],ans[1200000];

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
/*
for (int i=0;i<=n;i++)
v.push_back(i);

while (next_permutation(v.begin(),v.end()))
{
 s=0;
 for (int i=0;i<v.size();i++)
 s+=v[i]^i;
 if (s>bans)
 {
  bans=s;bv=v;
 }     
 else if (s==bans&&v<bv)
 {bv=v;}
}

cout<<bans<<endl;
*/
/*for (int i=0;i<v.size();i++)
cout<<bv[i]<<" ";
cout<<endl;
for(int i=0;i<v.size();i++)
cout<<(bv[i]^i)<<" ";
cout<<endl;
*/
mpow=20;

for (int i=n;i>=0;--i)
{
 q=i;
 while ((q^((1<<mpow)-1))>n||usd[q^((1<<mpow)-1)]==1)
 {
       --mpow;
 }
 usd[q^((1<<mpow)-1)]=1;
 ans[i]=q^((1<<mpow)-1);
}

cout<<n*(n+1)<<endl;

for (int i=0;i<=n;i++)
{if (i)cout<<" ";
cout<<ans[i];}
cout<<endl;

cin.get();cin.get();
return 0;}