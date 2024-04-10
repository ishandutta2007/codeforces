/*
Unknown Substance
A putrid Cloud -
Choking all within Results of Progress,
A noxious Waste -
Floating in the Air
Living free?
Chemically
So now our World is fading into slowly burning out Prime Wealth?
Toxic Health
Advancing towards extinction is the way it's turning out Foul Air?
Do you care?
Is Cleanness where
you live going against your common believe
Too much slime, insufficient time?
In a suffocated future
will you find the time to breathe
Jammed in one place
Blind in haste
Progress can't wait
A life in waste
Tending towards - Technology
Reverse of: life's biology
Chemical comatose
Radiation overdose
Burning, melting flesh
Leaking slime of dissolving waste
Overflowing blackness of death
Creation is being torn down by abuse
Infringement of the substance and our use
Elements decomposing, dilution is too slow
Every contribution, to the evolution
Its bad gets worse; deathly course.
Swallowed in Black
Faced with reality?
Search your memory
Nothing dead ever comes back
The Black
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,m,a,b,deg[1<<20],alive[1<<20];
int odd,even;
int cnt[1<<20];
int w[1<<20];
int odds[1<<20];

int get(int x)
{
    if (w[x]==x)
    return x;
    return w[x]=get(w[x]);
}

void merge(int a,int b)
{
    alive[a]=alive[b]=1;
    w[a]=b;
}

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
    w[i]=i;
    
for (int i=0;i<m;i++)
{
    cin>>a>>b;
    deg[a]++;
    deg[b]++;
    a=get(a);
    b=get(b);
    alive[a]=alive[b]=1;
    if (a!=b)
    merge(a,b);
}

int oddV=0;

for (int i=1;i<=n;i++)
{
    int q=get(i);
    if (alive[q]==0)
        continue;
    cnt[q]+=deg[i]%2;
    oddV+=deg[i]%2;
}
/*
for (int i=1;i<=n;i++)
 cout<<w[i]<<" "<<alive[i]<<" "<<cnt[i]<<endl;
 */
for (int i=1;i<=n;i++)
{
    if (alive[i]==0)continue;
    if (w[i]!=i)continue;
    if (cnt[i]==0)
        ++even;
}

int ans=0;
if (deg[1]==0)
    ++even;

if (even==1&&oddV==0)
    cout<<0<<endl;
else
    cout<<even+oddV/2<<endl;

//cout<<even<<" "<<oddV<<endl;

//cin.get();cin.get();
return 0;}