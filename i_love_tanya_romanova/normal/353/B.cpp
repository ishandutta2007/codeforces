/*
You give up on yourself
Somehow you got betrayed agin
Thin ice and luck runs out
Who will you blame it on this time?

Due to lack of interest in you
The light at the end of the tunnel
Was turned off
And something I noticed
Beating you is thrilling me
I've got a secret for you

If you took your own direction
If only you practice what you preach
If you follow your advice
You wouldn't be burning bridges all the time

Don't close your eyes to injustice
Listen, being brave ain't chicken shit
A man without any valor
Has nothing worth living for

Due to lack of interest in you
The light at the end of the tunnel
Was turned off
And something I noticed
Beating you is thrilling me
I've got a secret for you

If you took your own direction
If only you practice what you preach
If you follow your advice
You wouldn't be burning bridges all the time

If you took your own direction
If only you practice what you preach
If you follow your advice
You wouldn't be burning bridges all the time

If you took your own direction
If only you practice what you preach
If you follow your advice
You wouldn't be burning bridges all the time
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,ar[2000],ans,ap,k1,k2,un,nun,c1,c2;
vector<long> v[1000];
long h1[2000],h2[2000];
long anss[2000],sz1,sz2;

int main(){
//freopen("unionday.in","r",stdin);
//freopen("unionday.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
n*=2;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 v[ar[i]].push_back(i);   
}

ans=0;
for (int i=10;i<=99;i++)
if (v[i].size()==1)un++;

for (int i=10;i<=99;i++)
if (v[i].size()>1)nun++;

for (int u1=0;u1<=un&&u1<=n;u1++)
{
 k1=u1;
 k1+=nun;
 if (k1>n)k1=n;
 k2=un-u1;
 if (k2>n)continue;
 k2+=nun;
 if (k2>n)k2=n;
 if (k1*k2>ans)
 {ans=k1*k2;ap=u1;}
}

//cout<<ans<<" "<<ap<<endl;

cout<<ans<<endl;
sz1=sz2=n/2;
k1=ap;
k2=un-ap;
for (int i=10;i<=99;i++)
{
 if (v[i].size()==0)continue;
 if (v[i].size()==1){if (k1>0){sz1--;k1--;anss[v[i][0]]=1;continue;}
                      if (k2>0){sz2--;k2--;anss[v[i][0]]=2;continue;}   }
}

//cout<<sz1<<" "<<sz2<<endl;

for (int i=10;i<=99;i++)
{
 if (v[i].size()<2)continue;
 nun--;
 long ps=0;
 if (sz1>nun){anss[v[i][ps]]=1;--sz1;++ps;}
 if (sz2>nun){anss[v[i][ps]]=2;--sz2;++ps;}
 while (ps<v[i].size()&&sz1>nun){anss[v[i][ps]]=1;--sz1;++ps;}
 while (ps<v[i].size()&&sz2>nun){anss[v[i][ps]]=2;--sz2;++ps;}   
}

for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<anss[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}