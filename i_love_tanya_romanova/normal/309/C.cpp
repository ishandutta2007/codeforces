/*
An unforseen future nestled somewhere in time.
Unsuspecting victims no warnings, no signs.
Judgment day the second coming arrives.
Before you see the light you must die.

Forgotten children, conform a new faith,
Avidity and lust controlled by hate.
(The) Never ending search for your shattered sanity,
Souls of Damnation in their own reality.

Chaos rampant,
An age of distrust.
Confrontations.
Impulsive habitat.

Bastard sons begat your cunting daughters,
Promiscuous mothers with your incestuous fathers.
Engreat souls condemned for all eternity,
Obtained by immoral observance a domineering deity.

Chaos rampant,
An age of distrust.
Confrontations.
Impulsive sabbath.

On and on, south of heaven [x 4]

The root of all evil is the heart of a black soul.
A force that has lived all eternity.
The never ending search for a truth never told.
The loss of all hope and your dignity.

Chaos rampant,
An age of distrust.
Confrontations.
Impulsive habitat.

On and on, south of heaven [x 4]
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

long q,p;
vector<long> v;
long calc[100],n,m;
long ans;

void build(long q)
{
     for (int pw=30;pw>=0;--pw)
     {
         if (q>=(1<<pw)){calc[pw]++;q-=(1<<pw);}
     }
}

void solve(long a,long b)
{
 calc[b]--;
 for (int i=b-1;i>=a;--i)
 {
     calc[i]++;
 }
}

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{cin>>q;
 build(q);}

for (int i=0;i<m;i++)
{cin>>p;v.push_back(p);}

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
    for (int j=v[i];j<=30;j++)
    {
        if (calc[j]>0)
        {
                      solve(v[i],j);
                      ++ans;
                      break;
        }
    }
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}