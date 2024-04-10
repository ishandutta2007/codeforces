/* 
Let not the sun go down on my wrath
I let it shake the world
Vengeance is the grudge I bear
flag of reckoning unfurled
You are the architect
of your own demise
so smile no more
I am the gatekeeper,
and you are mine for evermore

[Chorus:]
Come greet the reaper
You know the time is nigh
This is the day of reckoning,
your time to die
Brave men they spin in fear
At the sound of my voice
Say goodbye to life so dear
You no longer have a choice

Burnt black and silent,
rust and blood
upon my reapers blade
I come collect the tolls
gather up all the debts unpaid
I call when you least expect
but when you deserve it the most
Behold the timekeeper
the end is getting close

[Chorus]

The dead no longer have
A cross to bear
The dead no longer have
Need to despair
Death has come
And set the snare
Death will come
When you are unaware

The misbegotten have the gall
to think them safe and sound
They try to cheat the reaper
scatter, hide, no matter, found
The wheel of life is standing still
For them it turns no more
Now comes the soul keeper
and you become my whore

[Chorus]
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

long long pwr[10000],c[1010][1010],q;
vector<long long> v;
long long n,m,span,ans;
long long free;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

ans=1;

for (int i=0;i<=1005;i++)
for (int j=0;j<=i;j++)
{if (j==i||j==0)c[i][j]=1;
else c[i][j]=c[i-1][j-1]+c[i-1][j];
c[i][j]%=bs;}

pwr[0]=1;
pwr[1]=1;
for (int i=2;i<=1005;i++)
pwr[i]=pwr[i-1]*2%bs;

cin>>n>>m;
for (int i=0;i<m;i++)
{cin>>q;v.push_back(q);}
sort(v.begin(),v.end());

for(int i=0;i<v.size();i++)
{
 span=v[i]-1;
 if (i>0){span-=v[i-1];ans=ans*pwr[span]%bs;}
 //cout<<span<<endl;
 free+=span;
 ans=ans*c[free][span]%bs;
}

free+=n-v[v.size()-1];
ans=ans*c[free][n-v[v.size()-1]]%bs;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}