/*
I barely get to the graveyard shift on time
After pulling another grueling 9 to 5
I live from credit card to check, the paper money's whirling by
And I hardly just, just barely only just survive

I'm living on the edge, reality is teetering
My mind is on the brink

How will I face the day tomorrow
If I can't make it through today?
I've got nothing left to lose but my sanity
And the right to go insane

I've got nothing left to lose but my mind
I've got nothing left to choose so I think I'll go insane

My stomach aches, insufficient funds
My cheeks are gaunt and my guts are overdrawn
My head pounds, starvation's giving me the shakes
Too much squalor, too much pressure and now I'm getting pissed

I'm living on the edge, reality is teetering
My mind is on the brink

How will I face the day tomorrow
If I can't make it through today?
I've got nothing left to lose but my sanity
And the right to go insane

I've got nothing left to lose but my mind
I've got nothing left to choose so I think I'll go insane
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long n,k,answ;
long dp[2100][2100];
void ad(long&a,long &b)
{
 a+=b;
 while(a>=bs)a-=bs;

}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
dp[1][i]=1;
for (int i=1;i<k;i++)
{
 for (int j=1;j<=n;j++)
  for (int q=j;q<=n;q+=j)
   ad(dp[i+1][q],dp[i][j]);
}

answ=0;
for (int i=1;i<=n;i++)
ad(answ,dp[k][i]);
cout<<answ<<endl;

cin.get();cin.get();
return 0;}