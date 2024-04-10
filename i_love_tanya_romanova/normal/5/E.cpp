/*
Neglected treated bad
Outcasts no gall
Obsessed with hate
Vengence death's call

Crazy out of his mind in sand he's cracked
Desperate to take his life
Rifle gun or knife

Plead for help silent scream
No one cares now it seems
The weapon to his head
Trigger's pulled no he's dead

Die for no reason but we do not know
Why he killed himself death by suicide

Everyone wonders why
The young man took his life
Unsolved mystery
Evil let it be
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

using namespace std;

long long n,l[2200000],h[2200000],ar[2200000],r[2200000],same[2200000],ans,cp,mx;
long long calc;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>h[i];
 if (h[i]>mx)cp=i;
 mx=max(mx,h[i]);
}


for (int i=cp;i<=cp+n;i++)
{
 ar[i-cp+1]=h[i];
 if (i>n)ar[i-cp+1]=h[i-n];
}
++n;

for (int i=1;i<n;i++)
 if (ar[i]==mx)++calc;

ans=calc*(calc-1)/2;

r[n]=n;

for (int i=n-1;i;--i)
{
 r[i]=i+1;
 while (r[i]<n&&ar[i]>ar[r[i]])r[i]=r[r[i]];
 if (ar[i]==ar[r[i]]){same[i]=same[r[i]]+1;r[i]=r[r[i]];}
}

l[1]=1;
for (int i=2;i<=n;i++)
{
 l[i]=i-1;
 while (l[i]>1&&ar[l[i]]<ar[i])l[i]=l[l[i]];
 if (l[i]>1&&ar[i]==ar[l[i]])l[i]=l[l[i]];
}
/*
for (int i=1;i<=n;i++)
 cout<<ar[i]<<" ";
 cout<<endl;
for (int i=1;i<=n;i++)
 cout<<l[i]<<" ";
 cout<<endl;
for (int i=1;i<=n;i++)
 cout<<r[i]<<" ";
 cout<<endl;
 */
for (int i=1;i<n;i++)
{
 if (ar[i]<mx)ans+=2+same[i];
 if (ar[i]<mx&&l[i]==1&&r[i]==n)--ans;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}