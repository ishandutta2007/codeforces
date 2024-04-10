/*
Love is a razor and I walked the line on that silver blade
Slept in the dust with his daughter, her eyes red with
The slaughter of innocence
And I will pray for her.
I will call her name out loud.
I would bleed for her.
If I could only see her now.

Living on a razor's edge.
Balancing on a ledge.
Living on a razor's edge on...
Balancing on a ledge on...
Balancing on a ledge on...
Living on a razor's edge.
Balancing on a ledge you know ... you know !!

The evil that men do lives on and on !....[x4]

Circle of fire my baptism of joy at an end it seems
The seventh lamb slain, the book of life opens before me.
And I will pray for you.
...Some day I may return.
Don't you cry for me
Beyond is where I learn.

Living on a razor's edge.
Balancing on a ledge.
Living on a razor's edge you know... you know !!

The evil that men do lives on and on! [x4]

Living on a razor's edge.
Balancing on a ledge.
Living on a razor's edge you know ... you know !!

The evil that men do lives on and on! [x4]
The evil !
The evil !
The evil that men do...
The evil !
The evil !
The evil that men do...
Yeah yeah!!
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