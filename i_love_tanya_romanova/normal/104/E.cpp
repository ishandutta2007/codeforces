/*
I feel responsibility to hate what I can't eat.
A sack full of hissin' snakes, laying at my feet.
I see colors that don't exist, feel pain that isn't mine,
Gone from dirt to mud,
Gone from mud to slime.

When you're ready! To come home!
Whan you've had enough.

When you're standing! all alone!
Ya know, I'll be waiting here!!!

There's pride in what you call yourself, but then whats in a name?
I feel responsibility to hate and pass the blame.
Know you no security, they'll beat you with a stick.
I feel responsibility to hate what makes me sick.

I know you're standing! All alone!
Yeah! I'm still waiting here...

They eat their young! They eat their young!
Without question.
They eat their young! They eat their young!
Can't be done all by myself, send help.

I feel responsibility to hate what I can't eat.
An' I feel no security, just standin' on my feet.
I see colors that don't exist, feel pain an' its all mine!
Gone from dirt to mud,
Livin' in the slime.

When you're ready! To come home!
I know you had enough!
When you're standing! All alone!
Ya know, I'm still waiting here...

They eat their Young!
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

using namespace std;

int n,w[1<<20];
int tests,a[1<<20],b[1<<20];
long long ans[1<<20];
vector<int> queries[1<<20];
long long dp[1<<20];

long long naive(long long a,long long b)
{
    long long res=0;
    for (int i=a;i<=n;i+=b)
        res+=w[i];
    return res; 
}

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
    cin>>w[i];

cin>>tests;
for (int iter=1;iter<=tests;iter++)
{
    cin>>a[iter]>>b[iter];
    if (b[iter]>bsize)
    {
        ans[iter]=naive(a[iter],b[iter]);
    }
    else
    {
        queries[b[iter]].push_back(iter);
    }
}

for (int i=1;i<=bsize;i++)
{
    for (int j=n;j;--j)
        dp[j]=0;
    for (int j=n;j;--j)
    {
        dp[j]=dp[j+i]+w[j];
    }
    for (int j=0;j<queries[i].size();j++)
    {
        int id=queries[i][j];
        ans[id]=dp[a[id]];
    }
}

for (int i=1;i<=tests;i++)
{
        cout<<ans[i]<<endl;
}
cout<<endl;

//cin.get();cin.get();
return 0;}