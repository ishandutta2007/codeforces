/*
One by one we take control
New consciousness, one heart, one soul
Oppression ends, the time has come
So don't look back, it can be done

Something is still missing
Something keeps 'em blind
Like a precious sacrilege
They can never find
(They can never find)

So they walk together
Into a silent war
Though it seems to take forever
This generation is finally heading for

A better tomorrow
A better tomorrow

Tell me can't you feel it?
Tell me can't you see?
Tell me can't you hear it?
I know it ain't just me

Let us walk together
What are we waiting for?
(What are we waiting for?)
It is now or never
This generation is finally heading for

A better tomorrow
A better tomorrow

Day by day we're praying for
It to come across the shores
It brings new hope, it brings new light
Nameless spirits now they shine

One by one become aware
New consciousness will be there
And all the blind, now they will see
Embrace their minds to plant the seeds for

A better tomorrow
A better tomorrow
A better tomorrow
A better tomorrow
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

double get_inter(pair<long long, long long> p1,pair<long long, long long> p2)
{
    double z=p1.first-p2.first;
    if (z==0)
    {
        return (p1.second>p2.second?1e18:-1e18);
    }
    return (p2.second-p1.second)/z;
}

int n;
long long a[1<<20],b[1<<20],dp[1<<20];
pair<long long, long long> tp;
int s,t;
pair<long long, long long> v[1<<20];

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>a[i];
}
for (int i=1;i<=n;i++)
    cin>>b[i];

dp[1]=0;

s=t=0;

// dp[i]=dp[j]+b[j]*a[i]
for (int i=2;i<=n;i++)
{
    tp.first=b[i-1];
    tp.second=dp[i-1];
    
    while (t>s+1&&get_inter(v[t-1],v[t-2])>=get_inter(tp,v[t-1]))
        --t;
    
    v[t]=tp;
    ++t;
    
    while (s+1<t&&get_inter(v[s],v[s+1])<a[i])
        ++s;
    
    tp=v[s];
    dp[i]=tp.first*a[i]+tp.second;
    
    /*for (int j=s;j<t;j++)
    {
        cout<<v[j].first<<"   "<<v[j].second<<endl;
    }
    cout<<dp[i]<<"#"<<endl;*/
}

cout<<dp[n]<<endl;

//cin.get();cin.get();
return 0;}