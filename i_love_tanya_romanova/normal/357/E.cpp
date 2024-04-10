/*
After the battle is over
And the sands drunken the blood
All what there remains
Is the bitterness of delusion

The immortality of the gods
Sits at their side
As they leave the walls behind
To reach the jewels gleam

The days have come
When the steel will rule
And upon his head
A crown of gold

Your hand wields the might
The tyrant's the precursor
You carry the will
As the morning is near

I sing the ballads
Of victory and defeat
I hear the tales
Of frozen mystery

The new kingdoms rise
By the circle of the tyrants
In the land of darkness
The warrior, that was me
Grotesque glory
None will (ever) see them fall
And hunts and war
Are like everlasting shadows

Where the winds cannot reach
The tyrant's might was born
And often I look back
With tears in my eyes
Grotesque glory
None will (ever) see them fall
And hunts and wars
Are like everlasting shadows
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
//#include <memory.h>

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

long n,ar[2000000],s[2000000],oh[2000000],need[2000000];
long ans,fst,sp,snd;

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
sort(ar+1,ar+n+1);

for (int i=1;i<=n;i++)
s[i]=s[i-1]+ar[i];

for (int i=1;i<=n;i++)
{
 oh[i]=oh[i-1];
 if (ar[i]==4)++oh[i]; 
 need[i]=need[i-1];
 if (ar[i]<3)need[i]+=3-ar[i];  
}

ans=1000000000;

for (int cp=0;cp<=n;cp++)
{
    fst=s[cp];
    sp=4*(n-cp)-s[n]+s[cp];
    if (fst>sp)continue;
    snd=need[n]-need[cp];
    if (fst>=snd)ans=min(ans,fst);
    if (fst<snd)
    {
     if (oh[n]-oh[cp]+fst>=snd)ans=min(ans,snd);
    }
//    cout<<ans<<""<<fst<<" "<<snd<<endl;
    
}

if (ans>100000000)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}