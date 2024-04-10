/*
Can't bring me down
You can't kill me
Can't sell me out
Going to help myself now
You can't fill me with what you want me to be
No one will make me
You can't change me
I am my own man
So fall by the hand of me
No mercy from me
Can't bring me down...so cold

Gone in your wasted mind
Won't let you by
So don't even try
I'm done...
No more thoughts of you
I'm through with you
I curse you dead
Throw the hammer down
I'm down...
Burn in fucking hell
Better hear what I say
Get out of my way
I'm wild in my fucking ways
So cold...

You show to all your wickedness
Pray for the life you'll miss
A flash of white is what you get
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

long n,t,calc[11000000],pr[11000000],ttl[11000000],ans[11000000];
long l,r,tests;
long solve(long x)
{
 if (x>10000000)return solve(10000000);
 return ans[x];
}
 
int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>t;calc[t]++;}

pr[1]=1;
for (int i=2;i<=10000000;i++)
{
    if (pr[i]==0)
    {
     ttl[i]+=calc[i];
     for (int j=i*2;j<=10000000;j+=i)
     {
         ttl[i]+=calc[j];pr[j]=1;
     }
    }
}
for (int i=1;i<=10000000;i++)
ans[i]=ans[i-1]+ttl[i];
cin>>tests;
for (;tests;--tests)
{
    cin>>l>>r;
    cout<<solve(r)-solve(l-1)<<endl;
}
cin.get();cin.get();
return 0;}