/*  
Ripping out the feelings used to
Hold me in to place
Breaking through the
Structures, I unfold at my
Disgrace

I'm digging deeper
To lay my misery down
Into the water
So that it may drown

A grey
A grey so dark
It moves in silence and kills
Again
A grey
A grey so dark
I lose myself and embrace the
End

Swallowing the ashes of a newly
Burned down dream
Tasting only charred remains of
Cured and better me

I'm digging deeper
To lay my misery down
Into the water
So that it may drown

A grey
A grey so dark
It moves in silence and kills
Again
A grey
A grey so dark
I lose myself and embrace the
End

I burst, not bleed
I'm pulled into the undertow
I burst, not bleed
I'm swallowed by the great below

A grey
A grey so dark
It moves in silence and kills
Again
A grey
A grey so dark
I lose myself and embrace the
End

A grey so dark
(Still blinding me)
A grey so dark
(Still blinding me)
A grey so dark
(Still blinding me)
A grey so dark
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
#define eps 1e-9
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

char ans[10000];
long long n,m,k,pri[200][200],mpri[3000];
vector<pair<long long,long long> > v;
long long dp[300][300];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
cin>>pri[i][j];

for (int s=2;s<=n+m;s++)
mpri[s]=100000;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (mpri[i+j]>pri[i][j])mpri[i+j]=pri[i][j];

for (int i=2;i<=n+m;i++)
v.push_back(make_pair(mpri[i],i));
sort(v.begin(),v.end());

for (int ps=0;ps<v.size();ps++)
{
    
    ans[v[ps].second-2]='(';
    for (int i=0;i<n+m;i++)
    for (int j=0;j<n+m;j++)
    dp[i][j]=0;
    dp[0][0]=1;
    for (int i=0;i<=n+m;i++)
    for (int j=0;j<=n+m;j++)
    {
        if (dp[i][j]>1000000000000000000ll)dp[i][j]=1000000000000000000ll;
        if (ans[i]!=')')dp[i+1][j+1]+=dp[i][j];
        if (ans[i]!='(')if (j>0)dp[i+1][j-1]+=dp[i][j];
    }
    if (k>dp[n+m-1][0]){k-=dp[n+m-1][0];ans[v[ps].second-2]=')';}
}

for(int i=1;i<=n;i++)
{
        for (int j=1;j<=m;j++)
        {
            cout<<ans[i+j-2];
        }cout<<endl;
}
cin.get();cin.get();
return 0;}