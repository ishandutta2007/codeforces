/*
Out on the wiley, windy moors
We'd roll and fall in green
You had a temper, like my jealousy
Too hot, too greedy
How could you leave me?
When I needed to possess you
I hated you, I loved you too

Bad dreams in the night
They told me I was going to lose the fight
Leave behind my wuthering, wuthering
Wuthering Heights.

Heathcliff, it's me, Cathy come home
I'm so cold, let me in-a-your window

Oh it gets dark, it gets lonely
On the other side from you
I pine a lot, I find the lot
Falls through without you
I'm coming back love, cruel Heathcliff
My only one dream, my only master

Too long I roam in the night
I'm coming back to his side to put it right
I'm coming home to wuthering, wuthering
Wuthering Heights

Oh let me have it, let me grab your soul away
Oh let me have it, let me grab your soul away
You know it's me, Cathy
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long flag,q,dp[1<<20],par[1<<20];
vector<long> moves,ans;
long n;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=1000000;i++)
{
    flag=0;
    q=i;
    while (q)
    {
        if (q%10>1)flag=1;
        q/=10;
    }
    if (flag==0)
     moves.push_back(i);
}

for (int i=1;i<=1000000;i++)
{
    dp[i]=1e9;
}

dp[0]=0;
for (int i=0;i<=1000000;i++)
{
    for (int j=0;j<moves.size();j++)
    {
        long q=moves[j]+i;
        if (q<=1000000&&dp[q]>=dp[i]+1)
        {
            dp[q]=dp[i]+1;
            par[q]=i;
        }
    }
}
cin>>n;
cout<<dp[n]<<endl;
while (n)
{
    ans.push_back(n-par[n]);
    n=par[n];
}
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}