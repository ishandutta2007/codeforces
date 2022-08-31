/*
I wonder if we'll smile in our coffins while loved ones
Mourn the day, the absence of our faces, living, laughing,
Eyes awake. Is this too much for them to take?
Too young for ones conclusion, the lifestyle won.
Such values you taught your son. That's how.

Look at me now. I'm broken.
Inherit my life.

One day we all will die, a cliched fact of life. Force fed
To make us heed. Inbred to sponge our bleed. Every
Warning, a leaking rubber, a poison apple for mingled
Blood. Too young for ones delusion the lifestyle cost
Venereal Mother embrace the loss. That's how

Look at you now. You're broken
Inherit your life.
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

long long n,m,ar[200000],l,r,ans;

int main(){
//freopen("galaxy.in","r",stdin);
//freopen("galaxy.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>ar[i];
r=1;
for (int i=1;i<=n;i++)
{
 while (r<n&&ar[r+1]-ar[i]<=m)++r;
 ans+=(r-i)*(r-i-1)/2;  
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}