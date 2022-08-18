/*
Well I guess it would be nice
If I could touch your body
I know not everybody
Has got a body like you

But I've got to think twice
Before I give my heart away
And I know all the games you play
Because I play them too

Oh but I
Need some time off
From that emotion
Time to pick my heart up off the floor

Oh, and that love comes down
Without devotion
Well it takes a strong man baby
But I'm showing you the door

Because I gotta have faith
I gotta have faith
Because I got to have faith, faith
I gotta have faith, faith, faith

Baby
I know you're asking me to stay
Sayin' please, please, please, don't go away
You say I'm giving you the blues

Maybe
You mean every word you say
Can't help but think of yesterday
And another who tied me down to lover boy rules

Before this river
Becomes an ocean
Before you throw my heart back
On the floor

Oh, baby I reconsider
My foolish notion
Well I need someone to hold me
But I'll wait for something more

Yes I've gotta have faith
I gotta have faith
Because I got to have faith, faith, faith
I gotta have faith, faith, faith

Because I got to have faith
Oh yeah, faith
Got to have faith

Before this river
Becomes an ocean
Before you throw my heart back
On the floor

Oh, baby I reconsider
My foolish notion
Well I need someone to hold me
But I'll wait for something more

Because I gotta have faith
I gotta have faith
Because I got to have faith, faith, faith
I gotta have faith, faith, faith
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

int n,k;
int ar[1<<20];
long long dp[1<<20][4];
vector<long long> v;
long long ans;
set<long long> have;
map<long long, long long> mapp;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
    cin>>ar[i];

for (int i=1;i<=n;i++)
{
    v.push_back(ar[i]);
}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
    if (i==0||v[i]!=v[i-1])
    {
        have.insert(v[i]);
        mapp[v[i]]=have.size();
//      cout<<v[i]<<"$"<<endl;
    }
}

for (int i=n;i;--i)
{
    long long need=1ll*ar[i]*k;
/*  if (need>2e9||need<-2e9)
        continue;
    if (have.find(need)==have.end())
        continue;
*/  
    if (have.find(need)!=have.end())
    for (int j=3;j>=2;j--)
        dp[mapp[ar[i]]][j]+=dp[mapp[need]][j-1];
    dp[mapp[ar[i]]][1]++;
//  cout<<i<<" "<<mapp[ar[i]]<<" "<<dp[mapp[ar[i]]][1]<<" "<<dp[mapp[ar[i]]][2]<<" "<<dp[mapp[ar[i]]][3]<<" "<<need<<" "<<mapp[need]<<endl;
}

for (int i=1;i<(1<<20);i++)
    ans+=dp[i][3];
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}