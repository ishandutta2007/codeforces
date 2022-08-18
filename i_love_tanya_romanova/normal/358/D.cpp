/*
I will see you rise and fall
I will be you rise and fall
I will make you rise and fall
I create your rise and fall
And I will be you

Got bored with me because I'm
Born with conviction
From a pain you'll never ever understand, understand
Never forget what I said cause you ain't half of me
I'll tear down and break anything that stands in front of me
I'm taking down what the fuck is ever in my way
So get way

I will see you rise and fall
I will be you rise and fall
I will make you rise and fall
I create your rise and fall
And I will be you

But for me I'll forgive despite your actions
Cos you never ever ever act on what you said
Like you said
Give it to me, let it be,
But you're the one who quit
You said it yourself, you're the best
and you can handle it
The cry, watch how Machine Head takes it all, it all

And i feel for you
Cos your eyes they whore
And I think I hurt
Cos of something more
You see I'm falling
All apart
Cos your eyes they
Decide your heart

Rise and fall
And I will make the walls fall
And I will make the walls fall
And I will make the walls fall
And I will make the walls fall
Down.. Down.. Fall down.. Fall down..

I will see you rise and fall
I will be you rise and fall
I will make you rise and fall
I create your rise and fall
And I will be you
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

long n,a[10000],b[10000],c[10000],dp[5000][5];

int main(){
//freopen("codes.in","r",stdin);
//freopen("codes.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>a[i];
for (int i=1;i<=n;i++)
cin>>b[i];
for (int i=1;i<=n;i++)
cin>>c[i];

dp[1][0]=a[1];
dp[1][1]=-1000000000;

for (int i=2;i<=n;i++)
{
 // after
 dp[i][1]=dp[i-1][0]+b[i];
 dp[i][1]=max(dp[i-1][1]+b[i],dp[i][1]);
 // before
 dp[i][0]=max(dp[i][0],dp[i-1][1]+c[i-1]-b[i-1]+a[i]);
 dp[i][0]=max(dp[i][0],dp[i-1][0]+b[i-1]-a[i-1]+a[i]);
}

cout<<max(dp[n][1],dp[n][0])<<endl;

cin.get();cin.get();
return 0;}