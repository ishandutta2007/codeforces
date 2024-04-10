/*
Even if it's serious
You got to have some fun
This is something we believe in
From the moment we begun

Heavy metal thunder
Let the power take command
Got to keep it simple
Make people understand

Some might say that we all are a fake
Just rednecks who pretend
But we don't really care

We're going higher on fire
With fire we force our way
We got a higher desire for life

We just ignore this indiscretion
Keep our heads up high
Staying faithful to our mission
To playing metal till we die

So with metal chains and leather
We pree in lust
This music lasts forever
In metal we all trust

Some might say that we all are a fake
Just rednecks who pretend
But we don't really care

We're going higher on fire
With fire we force our way
We got a higher desire for life
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define bsize 256

using namespace std;

long long n,m,ar[20000],q,t[20000],ans,answ,tans;
vector<long long> v1,v2;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for(int i=1;i<=n;i++)
{
 cin>>ar[i];
}
for (int i=1;i<=m;i++)
{
 cin>>q;
 t[q]=1;
}
for (int i=1;i<=n;i++)
{
 if (t[i]==0)
 v1.push_back(ar[i]);
 else v2.push_back(ar[i]);
}

sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());
for (int i=0;i<v1.size();i++)
 ans+=v1[i];

for (int p=0;p<=v2.size();p++)
{
 tans=ans;
 for (int j=p;j<v2.size();j++)
 tans+=v2[j];
 for (int j=0;j<p;j++)
  tans+=max(v2[j],tans);
 answ=max(answ,tans);
}

cout<<answ<<endl;
cin.get();cin.get();
return 0;}