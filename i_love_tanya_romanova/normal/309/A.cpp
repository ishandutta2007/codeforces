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

long long n,q,l,t,frings;
vector<long long> v;

long long trtime,rtime;
double ans;

long long ll,rr,mm;

long long solve(long long p)
{
     if (p<v[0])return 0;
     ll=0;
     rr=n-1;
     while (ll<rr)
     {
           mm=ll+rr+1;mm/=2;
           if (v[mm]>p)rr=mm-1;
           else ll=mm;
     }
     return ll+1;
}
int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>l>>t;
rtime=(t*2)%l;
frings=t*2/l;
for (int i=0;i<n;i++)
{
    cin>>q;
    v.push_back(q);
}

sort(v.begin(),v.end());

    for (int i=0;i<n;i++)
{    ans+=0.25*frings*(n-1);// forvard, bw
    ans+=0.25*frings*(n-1);//backward, fv
}
//cout<<rtime<<endl;

//cout<<ans<<endl;

for (int i=0;i<n;i++)
{
    trtime=rtime;
    ans+=(solve(v[i])-solve(v[i]-rtime-1)-1)*0.25;
    if (rtime>v[i])
    {
     trtime=l-(rtime-v[i])-1;
     ans+=(solve(l)-solve(trtime))*0.25;
    }
}

reverse(v.begin(),v.end());
for (int i=0;i<n;i++)
v[i]=l-v[i]-1;

/*for (int i=0;i<n;i++)
cout<<v[i]<<" ";
cout<<endl;
*/

for (int i=0;i<n;i++)
{
    trtime=rtime;
    ans+=(solve(v[i])-solve(v[i]-rtime-1)-1)*0.25;
    if (rtime>v[i])
    {
     trtime=l-(rtime-v[i])-1;
     ans+=(solve(l)-solve(trtime))*0.25;
    }
}

cout.precision(10);
cout<<fixed<<ans/2<<endl;

cin.get();cin.get();
return 0;}