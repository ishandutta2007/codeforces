/*
In the smoke of combat
No gods give you the guts

You see the fire in the sky
The bombs fall by your side
I put powder in my gun
Let me free, let me run

Armed with swords and hash
I run, kill and fight
I remove the knife in your sore
I believe in the death's call

I live to kill, create war and pain
You die for fire, your soul burns in flames

Our disaster is not complete today
We make no difference because you fall in fate
The war punishes and pain resists
The wildness shouts, the blood burst out

We're going in hell tonight
For another loud attack
And you see in the mist
Black flag is on my mast

The cannons creep in your desert to kill
And no defense, no forces, you're the blood lust victims
The war punishes and pain resists
The wildness shouts, the blood burst out

In the smoke of combat
No gods gives you the guts
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
#define time asdfasdfasfd

using namespace std;

long long pw[1<<21];
string st1,st2;
long long s1[1<<20],s2[1<<20],rs1[1<<20],rs2[1<<20];
int n;
int lcp[1<<20];
int pref[1<<20];
int lcp2[1<<20];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pw[0]=1;
for (int i=1;i<=(1<<20);i++)
    pw[i]=pw[i-1]*173;

getline(cin,st1);
getline(cin,st2);

if (st1.size()!=st2.size())
{
    cout<<-1<<" "<<-1<<endl;
    return 0;
}

for (int i=0;i<st1.size();i++)
    s1[i+1]=s1[i]+st1[i]*pw[i];
for (int i=0;i<st2.size();i++)
    s2[i+1]=s2[i]+st2[i]*pw[i];

reverse(st1.begin(),st1.end());
reverse(st2.begin(),st2.end());
for (int i=0;i<st1.size();i++)
    rs1[i+1]=rs1[i]+st1[i]*pw[i];
for (int i=0;i<st2.size();i++)
    rs2[i+1]=rs2[i]+st2[i]*pw[i];

reverse(st1.begin(),st1.end());
reverse(st2.begin(),st2.end());

n=st1.size();

for (int i=1;i<=n;i++)
{
    int l,r;
    l=0;
    r=n-i+1;
    while (l<r)
    {
        int mid=l+r+1;
        mid/=2;
        long long val1=rs1[mid]*pw[1<<20];
        long long val2=(s2[i+mid-1]-s2[i-1])*pw[(1<<20)-i+1];
        if (val1==val2)
            l=mid;
        else
            r=mid-1;
    }
    lcp[i]=l;
}

for (int i=1;i<=n;i++)
{
    int l,r;
    l=0;
    r=n-i+1;
    while (l<r)
    {
        int mid=l+r+1;
        mid/=2;
        long long val1=s1[i+mid-1]-s1[i-1];
        val1*=pw[(1<<20)-i+1];
        long long val2=s2[mid]*pw[1<<20];
        if (val1==val2)
            l=mid;
        else
            r=mid-1;
    }
    lcp2[i]=l;
}
/*
for (int i=1;i<=n;i++)
    cout<<lcp[i]<<" ";
cout<<endl;
for (int i=1;i<=n;i++)
    cout<<lcp2[i]<<" ";
cout<<endl;
*/

for (int i=1;i<=n+1;i++)
    pref[i]=max(pref[i-1],i+lcp[i]);


for (int i=n-1;i;i--)
{
    long long val1=s1[i]*pw[1<<20];
    long long val2=rs2[i]*pw[1<<20];
    if (val1!=val2)
        continue;
    
//  cout<<i<<" "<<" #"<<pref[i+lcp2[i+1]+1]<<" "<<i+lcp2[i+1]+1<<endl;
    
    if (pref[lcp2[i+1]+1]<=n-i)
        continue;
//  cout<<"@"<<i<<endl;
    cout<<i-1<<" ";
    for (int j=1;j<=st1.size();j++)
    {
        if (lcp[j]+j>n-i)
        {
//          cout<<i<<"  "<<j<<" "<<lcp[j]<<endl;
            cout<<i+j-1<<endl;
            return 0;
        }
    }
}

cout<<-1<<" "<<-1<<endl;
//cin.get();cin.get();
return 0;}