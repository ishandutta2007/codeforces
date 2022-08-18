/*
Death-type dreaming hoping not fade away
And i'm sinking ever deeper
In the gleaming
And i'm weaving down thru alleys of bone
Dermal dripping
Trees of people still it lingers
And it's endless winding long corridors
Of the bleaching
And the grinning never frowning

Skull forrest
And i see them haunting skinless forlorn
Swaying demons eyeless creatures
Hearts still beating
There the fallen thickets row after row
Dangling helpless damned and woeful
Still they glisten
Then the faces staring that i have known
All the parted
All the missing
Here to greet me

Skull forrest
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long n,ar[10000],nuls,sum,rdown,rup,bans,ts;
double temp;

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n*2;i++)
{cin>>temp;ar[i]=temp*1000+1e-3;if (ar[i]%1000==0)nuls++;sum+=ar[i];}

bans=1000000000;

for (int ndown=0;ndown<=nuls;++ndown)
{
    if (ndown>n)continue;
    rdown=n-ndown;
    rup=n-(nuls-ndown);
    if(rup>n)continue;
    if (rup<0)continue;
    ts=0;
    for (int i=1;i<=n*2;i++)
    if (ar[i]%1000==0)ts+=ar[i];
    else if (rdown>0){ts+=(ar[i]-ar[i]%1000);--rdown;}
    else if (rup>0){ts+=ar[i]-ar[i]%1000+1000;--rup;}
    if (abs(ts-sum)<bans)
    bans=abs(ts-sum);
}

cout<<bans/1000<<".";
bans%=1000;
cout<<bans/100;
bans%=100;
cout<<bans/10;
cout<<bans%10<<endl;
//bans%1000<<endl;
cin.get();cin.get();
return 0;}