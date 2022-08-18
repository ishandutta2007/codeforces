/*
Evil Minds grievous sins
Pagan lives have no place for law
Twisted worship exhume the dead
Minds unite for evil cause
Death corrodes the book once strong
Evil lourd destroys his foes
Plague has spread throughout the land
Revelations have begun

Call of evil's mastermind
Christians flock to the beast
Burning crosses burn souls
Exterminate the altar of laws
Atrocities of a new reich
Holy war and holocaust
God weeps and turns his back
The time is right to destroy the world

[Chorus:]
Damnation
Fill the world with plague
Force of devastation
Tyranny from above

[Chorus]

Churning of cities lust so profane
Driving the will to destroy
Crippling powers I'm forced to partake unholy rituals
Crimes of a world barely alive
Melting debauchery
Ashes to ashes, so must I be
Lost in this misery
There's nothing left here for me
I know of no other way
Even death cannot change my ways
I'm first in the line
To hell we shall go

Call of evil's mastermind
Christians flock to the beast
Burning crosses burn souls
The time is right to destroy the world

[Chorus]
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
//#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,k,iters,p[10000],q[1000],rp[1000],ar[200000],ar1[20000];
long ans;

bool not_same()
{
     for (int i=1;i<=n;i++)
     if (ar[i]!=q[i])return true;
     return false;
}

int main(){
//freopen("galaxy.in","r",stdin);
//freopen("galaxy.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
cin>>p[i];
for (int i=1;i<=n;i++)
cin>>q[i];
for (int i=1;i<=n;i++)
rp[p[i]]=i;

long tf=0;

for (int i=1;i<=n;i++)
if (rp[i]!=p[i])tf=1;

/*for (int i=1;i<=n;i++)
cout<<rp[i]<<" ";
cout<<endl;
*/

ans=0;

 for (int i=1;i<=n;i++)
 ar[i]=i;
 
 iters=0;
 while (not_same())
 {
       ++iters;
       for (int i=1;i<=n;i++)
       ar1[i]=ar[p[i]];
       for (int i=1;i<=n;i++)
       ar[i]=ar1[i];
       if (iters>k)break;
 }
 if (iters<=k&&iters%2==k%2)ans=1;

 for (int i=1;i<=n;i++)
 ar[i]=i;
 iters=0;

 while (not_same())
 {
       ++iters;
       for (int i=1;i<=n;i++)
       ar1[i]=ar[rp[i]];
       for (int i=1;i<=n;i++)
       ar[i]=ar1[i];
       if (iters>k)break;
 }
 if (iters<=k&&iters%2==k%2)ans=1;

long fl=0;
for (int i=1;i<=n;i++)
if(q[i]!=i)fl=1;
if (fl==0)ans=0;
if (tf==0&&k>1)ans=0;

if (ans)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}