/*
Two hearts that shouldn't
Talk to each other become close
In a town much like a prison cell

People speak our names
On the street in hushed tones
Oh the stories they'd tell
If anyone would listen

You come from a town where
People don't bother saying hello
Unless somebody's born or dies

And I come from a place where they
Drag your hopes through the mud
Because their own dreams are all dying

And when we walk down the street
The wind sings our name in rebel songs
The sounds of the night should make us anxious
But it's much to late when the fear is gone

I will meet you in the Next Life, I promise you
Where we can be together, I promise you
I will wait till then in Heaven, I promise you
I promise, I promise

There's so many fighting
To get past the Pearly Gates
But nobody ever wants to die or get saved

Their intentions aren't that good
And I can smell the asphalt
That's their personal road to hell being paved

And when we walk down the street
The wind sings our name in rebel songs
But it's much to late when the fear is gone

I will meet you in the Next Life, I promise you
Where we can be together, I promise you
I will wait till then in Heaven, I promise you
I promise, I promise

I will meet you in the Next Life, I promise you
Where we can be together, I promise you
I will wait till then in Heaven, I promise you
I promise, I promise
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
#define bsize 256

using namespace std;

long long n,ar[200000],dp[200000][3];
string st;

int main(){
//freopen("unionday.in","r",stdin);
//freopen("unionday.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
cin>>st;
for (int i=0;i<=n;i++)
dp[i][0]=dp[i][1]=-1000000000000ll;

dp[n][1]=0;

for (int i=n-1;i+1;--i)
{
 dp[i][0]=max(dp[i][0],dp[i+1][0]);
 if (st[i]=='1'){dp[i][0]=max(dp[i][0],dp[i+1][1]);dp[i][0]=max(dp[i][0],dp[i+1][0]+ar[i+1]);
 dp[i][1]=max(dp[i][1],dp[i+1][1]+ar[i+1]);}
 if (st[i]=='0'){dp[i][1]=max(dp[i][1],dp[i+1][1]);dp[i][0]=max(dp[i][0],dp[i+1][0]+ar[i+1]);}    
}

cout<<max(dp[0][0],dp[0][1])<<endl;

cin.get();cin.get();
return 0;}