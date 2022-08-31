/*
On the edge of the rainbow where eagles learn to fly
All of our dreams they seemed so clear
Into the mornin', into the light of dawn
We're flyin' higher than before

And when I see the light that's shining from your eyes
Even brighter than before
We're ridin' the wind to reach the golden dawn
We have done it all before, before, before

Here I stand, call on you again
But my heart is filled with fear
Like an eternal flame our love will remain
As we sail the lake of tears

Sometimes I wonder you're so close but you're so far
Seems life will never be the same
Sigh for the morning to find the light of day
Dream of fortune fades away

Here I stand, call on you again
But my heart is filled with fear
Like an eternal flame our love will remain
As we sail the lake of tears

Here I stand, call on you again
But my heart is filled with fear
Like an eternal flame our love will remain
As we sail the lake

Here I stand, call on you again
But my heart is filled with fear
All the tears that I've cried for the love of my life
As I sailed the lake of tears

Like an eternal flame our love will remain
As we sail the lake of tears
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
#define bsize 1024

using namespace std;

long long n,t[1200000],ar11[1200000],ar12[1200000],ar21[1200000],ar22[1200000];
vector<long> v;
map<long, long> mapp;
long calc;
long long temp,temp1;
long long ans;

long long gett1(long x)
{
 long long res=0;
 for (int i=0;i<x/bsize;i++)
  res+=ar11[i];
 for (int i=x/bsize*bsize;i<=x;i++)
 res+=ar12[i];
 return res;
}
long long gett2(long x)
{
     if(x<0)return 0;
 long long res=0;
 for (int i=0;i<x/bsize;i++)
  res+=ar21[i];
 for (int i=x/bsize*bsize;i<=x;i++)
 res+=ar22[i];
 return res;
}

void sett1(long x,long val)
{
 ar11[x/bsize]+=val;
 ar12[x]+=val;
}
void sett2(long x,long val)
{
 ar21[x/bsize]+=val;
 ar22[x]+=val;
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
cin>>t[i];
v.push_back(t[i]);
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
if (i==0||v[i]!=v[i-1])
{
 mapp[v[i]]=calc;++calc;
}    
}

for (int i=1;i<=n;i++)
{
 temp=mapp[t[i]];
 temp1=gett1(temp);
 sett1(temp,1);
 sett2(temp,temp1);
 temp1=gett2(temp-1);
 ans+=temp1;
}
/*
for (int i=0;i<n;i++)
cout<<ar22[i]<<" ";
cout<<endl;
*/
/*
for (int i=1;i<=n;i++)
{
 temp=mapp[t[i]];
 cout<<temp<<" %"<<" "<<gett2(temp-1)<<endl;
 
 ans+=temp1;
}
*/
cout<<ans<<endl;

cin.get();cin.get();
return 0;}