/*
The blackest of organs lying on the floor throbbing and glistening full of deep bitter wants
Dirty blood trickles gushes then torrents flow down to the gutter where nobody knows
It clots and hardens under the weight of these mouldy truths

Crawling down its black throat
All mangled and devastated
It festers and decomposes
Colourless odourless
Without nourishment

Its taking hold the pain the narcotic
Cutting through the spleen
Severing devouring everything
The pain of it ploughs me over

Frothing heaving sucking the air from my lungs
A shelter for maggots
Intoxicated rancid distorted sleep the worm vomits vats of despair
Twisting shapes from thin air
Damaged cells lying everywhere

Crawling down its black throat
All mangled and devastated
It festers and decomposes
Colourless odourless
Without nourishment
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
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,k,p,x,y,rem,ar[1<<20],s;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k>>p>>x>>y;

rem=n/2;

long med=y;

for (int i=1;i<=k;i++)
{ cin>>ar[i];
 if (ar[i]<med)
  --rem;
}

if (rem<0)
{
    cout<<-1<<endl;
    return 0;
}

for (int i=k+1;i<=n;i++)
{
 if (rem>0){--rem;ar[i]=1;}
 else
 {
    ar[i]=y;
 }
}

s=0;
for (int i=1;i<=n;i++)
 s+=ar[i];
if (s>x)
cout<<-1<<endl;
else
{
    for (int i=k+1;i<=n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
cin.get();cin.get();
return 0;}