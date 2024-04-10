/*
Now like a bird she flew away
To chase her dreams of books and praise
Still I miss her, yeah I miss her, since she's gone

At JFK, who played the fool?
Self pity sick jet fuel perfume
Still I miss her, yeah I miss her, since she's gone

Girl I want to die with you
In each other's arms

If this time were the last time
Could I hold you, hold you, hold you all life long?
Since this time is the last time
Can I hold you, hold you, hold you all night long?

Lay your head down
For the last time, the last time
For the last time, the last time

Lay your head down
For the last time, the last time
For the last time, the last time

Hey KLM AT and T, the UK post system
Do you still love me?
Still I miss her, yeah I miss her, since she's gone

Girl I want to die with you
In each other's arms
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
#define bsize 512
#define time asdfasdfasfd

using namespace std;

int n,k,ar[1<<20];
long long dp[5005][5005];
int C;
int cnt[5050];
int c1,c2;
int done;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=0;i<n;i++)
{
    cin>>ar[i];
    cnt[i%k]++;
}
sort(ar,ar+n);

C=1e9;

for (int i=0;i<k;i++)
{
    if (cnt[i]<C)
        C=cnt[i];
}
for (int i=0;i<k;i++)
    if (cnt[i]==C)
        c1++;
    else
        c2++;

for (int i=0;i<=c1;i++)
    for (int j=0;j<=c2;j++)
        dp[i][j]=1e18;

dp[0][0]=0;
for (int i=0;i<=c1;i++)
    for (int j=0;j<=c2;j++)
    {
        done=i*C+j*(C+1);
        if (i<c1&&C>0)
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+abs(ar[done+C-1]-ar[done]));
        if (j<c2)
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+abs(ar[done+C]-ar[done]));
    }

cout<<dp[c1][c2]<<endl;
    

//cin.get();cin.get();
return 0;}