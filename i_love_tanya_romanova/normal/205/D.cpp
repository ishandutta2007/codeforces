/*
Unity is a rare thing
Blind eyes of society bring
The category of minority
Now what are we supposed to be?
Born free to be
Powerless to change the world
With our lives in the hands of madmen

Now in times when society needs us
This is where the sin begins
We're aware they're going to free us
Rage from our hearts within
Born of this world
Which is a living hell
But we'll be closer to heaven

So now, this is the art
To shred... it's only emotion
*/

#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-11 
#define M_PI 3.141592653589793
//#define max 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long n,ans,f,p,a[200000],b[200000],t;
set<long> usd;
map<long, long> calc;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>n;

for (int i=0;i<n;i++)
{
    scanf("%d",&a[i]);
    scanf("%d",&b[i]);
    
    calc[a[i]]++;
    if (a[i]!=b[i]){calc[b[i]]++;}
}

ans=10000000;

for (int i=0;i<n;i++)
{
    t=a[i];
    if (calc[t]*2>=n&&usd.find(t)==usd.end())
    {
     p=0;
     for (int j=0;j<n;j++)
     if (a[j]==t)++p;
     f=0;
     while (p*2<n){++p;++f;}
     ans=min(ans,f);
     usd.insert(t);
    }    
    t=b[i];
    if (calc[t]*2>=n&&usd.find(t)==usd.end())
    {
     p=0;
     for (int j=0;j<n;j++)
     if (a[j]==t)++p;
     f=0;
     while (p*2<n){++p;++f;}
     ans=min(ans,f);
     usd.insert(t);
    }
}

if (ans>200000)ans=-1;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}