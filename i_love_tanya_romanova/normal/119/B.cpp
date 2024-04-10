/*
I don't want to go home
I'm feeling like a ghost
I'm falling all apart
Could you please fix my heart?

Why don't we leave this old town?
A new world waits to be seen
Give me a reason to stay
I'm not afraid to live

Tell me now
What do you read in my hand
Please don't spell me wrong
What is going on?

Tell me now
What is seen from my hand
I know what is true
Nothing's really new

Why don't we leave this old town?
A new world waits to be seen
Give me a reason to stay
I'm not afraid to live

Tell me now
All my will and destiny
Won't erase my hand
It won't change my plans

Tell me now
What could be the best for me
It's always been the same
I'm running like a train

I don't want to go home
I'm feeling like a ghost
I'm falling all apart
Could you please fix my heart?

Why don't we leave this old town?
A new world waits to be seen
Give me a reason to stay
I'm not afraid to live

Here we go
No one said it was easy
I'm on my feet again
A ticket in my hand

Here we go, here we go
Here we go, here we go
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

int n,k,ar[1000];
double l,r;
int one,ttl;
vector<int> v;
int used[1<<20];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
}

l=1e9;
r=-1e9;

one=n/k;

cin>>ttl;
int T=ttl;
for (;ttl;--ttl)
{
    int s=0;
    int unique=1;
    for (int i=1;i<=one;i++)
    {
        int val;
        cin>>val;
        if (used[val])
            unique=0;
        used[val]=1;
        s+=ar[val];
    }
    l=min(l,s*1.0/one);
    r=max(r,s*1.0/one);
    if (unique==0)
        --T;
}

if (T<k)
{

for (int i=1;i<=n;i++)
{
    if (used[i]==0)
        v.push_back(ar[i]);
}
sort(v.begin(),v.end());

int s=0;
for (int i=0;i<one;i++)
{
    s+=v[i];
}

l=min(l,s*1.0/one);
r=max(r,s*1.0/one);
reverse(v.begin(),v.end());
s=0;
for (int i=0;i<one;i++)
{
    s+=v[i];
}

l=min(l,s*1.0/one);
r=max(r,s*1.0/one);
}

cout.precision(10);
cout<<fixed<<l<<" "<<r<<endl;

//cin.get();cin.get();
return 0;}