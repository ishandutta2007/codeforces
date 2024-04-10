/* 
Rise up and revolt
Overthrow the government
Level all the temples
Destroy the monuments

Return to anarchy
Defy the Christian law
Prepare for mutiny
Prepare for coup d'etat

So begins our final riot act
Now that your in, there'll be no turning back
Smash everything, wreck it all with pride
The power of our revolution won't ever be denied

Reduce the halls of power
To ruin and to ash
An end to Christianity
An end to holy mass

The dawn of an iron age
Return to Pagan law
Lex Talionis
We rule by fang and claw

So begins our final riot act
Now that your in, there'll be no turning back
Smash everything, wreck it all with pride
The power of our revolution won't ever be denied
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
#define lr asgasgash

#define  INF 100000000
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,a[1000],b[1000],sw,bst[1000];
long ans;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>a[i]>>b[i];sw+=b[i];}

for (int i=1;i<1000;i++)
bst[i]=-1000000;

for (int i=1;i<=n;i++)
for (int total=200;total>=0;total--)
{
 if (bst[total+a[i]]<bst[total]+b[i])
 bst[total+a[i]]=bst[total]+b[i];
}

ans=1000000;
for (int i=200;i>=1;i--)
if (sw-bst[i]<=i)
ans=i;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}