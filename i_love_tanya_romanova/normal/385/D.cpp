/*
Powers of hate
Are directing your thoughts
And lead me to believe
In what you are not
Anger drives you
To inflict others' pain
Now feel the rage
Consuming your brain
Committing revenge now regulates
Your unguided ways to manipulate
Logic dies with bitter frustration
Anxiety feeds your slow damnation
How can this be right?
Your way of looking through me
Seeing beyond your lies
It's just your way to use me
All anger that you feel
Its driving force surrounding you
Forget your words of hate
The power that's confounding you
Reason to not forgive
Breaking down your tolerance
Can't you tell it's wrong
Not believing in the consequence
Into the recesses of your mind
Mysterious shadows unidentified
Shrouded by fears of the darkest kind
And there your being lies classified
This reign of hatred and despise
This weapon of spite caused you to lie
What is kept secret behind your eyes
Is now my fear of the truth denied
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

double dp[1200000],x[2000],y[2000],ang[200],l,r;
long n;

double solve(long n,double start)
{
 double a=ang[n]*M_PI/180-atan((x[n]-start)/y[n]);
 if (a>M_PI/2)return 1e9;
 return x[n]+tan(a)*y[n];
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>l>>r;
for (int i=0;i<n;i++)
cin>>x[i]>>y[i]>>ang[i];
dp[0]=l;
for (int mask=0;mask<(1<<n);++mask)
{
    dp[mask]=l;
    for (int i=0;i<n;i++)
    if (mask&(1<<i))
    dp[mask]=max(dp[mask],solve(i,dp[mask^(1<<i)]));
}
if (dp[(1<<n)-1]>r)dp[(1<<n)-1]=r;
cout.precision(9);
cout<<fixed<<dp[(1<<n)-1]-l<<endl;
cin.get();cin.get();
return 0;}