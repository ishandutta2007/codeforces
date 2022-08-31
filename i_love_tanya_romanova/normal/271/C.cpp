/*
We fought your wars with all our hearts,
You sent us back in body parts,
You took our wills with the truth you stole,
We offer prayers for your long lost soul.

The remainder is,
An unjustifiable, egotistical, power struggle,
At the expense of the American Dream,
Of the American dream, of the American, of the American.

We don't give a damn about your world,
With all your global profits and all your jeweled pearls,
We don't give a damn about your world,
Right now, right now.

We don't give a fuck about your world,
With all your global profits, and all your jeweld pearls,
We don't give a fuck about your world,
Right now, right now.

There is no flag that is large enough,
To hide the shame of a man in cuffs,
You switched the signs then you closed our blinds,
You changed the channel then you changed our minds.

You bring about the stick,
We bring about the confusion,
Bring about the solution,
Bring about the fusion,
Bring about the collusion,
Bring about revolution,
Bring about revolution,
Bring it about.

We don't give a damn about your world,
With all your global profits and all your jeweled pearls,
We don't give a damn about your world,
Right now, right now.

We don't give a fuck about your world,
With all your global profits, and all your jeweld pearls,
We don't give a fuck about your world,
Right now, right now.

No flag large enoguh,
Shame on a man un cuffs,
You closed our blinds.

The remainder is,
An unjustifiable, egotistical, power struggle,
At the expense of the American Dream,
Of the American dream, of the American, of the American.

We don't give a damn about your world,
With all your global profits and all your jeweled pearls,
We don't give a damn about your world,
Right now, right now.

We don't give a fuck about your world,
With all your global profits, and all your jeweld pearls,
We don't give a fuck about your world,
Right now, right now, right now, right now, right now, right now, right now, pararara...
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,k,ans[2000000];

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
if (n/k<3)cout<<-1<<endl;
else
{
     for (int i=3*k+1;i<=n;i++)
      ans[i]=1;
     for (int i=1;i<=3*k;i+=6)
     {
         if (i/3+1<=k)
         ans[i]=ans[i+1]=ans[i+3]=i/3+1;
         if (i/3+2<=k)
         ans[i+2]=ans[i+4]=ans[i+5]=i/3+2;
     }

for (int i=1;i<=n;i++)
if (ans[i]==0)ans[i]=1;

if (k%2==1&&n==3*k)ans[4]=k;
for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;
}
cin.get();cin.get();
return 0;}