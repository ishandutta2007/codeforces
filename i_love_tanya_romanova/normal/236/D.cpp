/*
No more!
The craps rolls out your mouth again
Haven't changed, your brain is still gelatin
Little whispers circle around your head
Why don't you worry about yourself instead

Who are you? where ya been? where ya from?
Gossip is burning on the tip of your tongue
You lie so much you believe yourself
Judge not lest ye be judged yourself

Holier than thou
You are
Holier than thou
You are

You know not

Before you judge me take a look at you
Can't you find somethig better to do
Point the finger, slow to understand
Arrogance and ignorance go hand in hand

It's not who you are it's who you know
Others lives are the basis of your own
Burn your bridges build them back with wealth
Judge not lest ye be judged yourself

Holier than thou
You are
Holier than thou
You are

You know not
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n;
double q,ans,dp[200000];

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
dp[0]=0;
for (int i=1;i<=n;i++)
{
    cin>>q;
    ans+=q*dp[i-1]*2+q;
    dp[i]=dp[i-1]*q+q;
}
cout.precision(8);
cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}