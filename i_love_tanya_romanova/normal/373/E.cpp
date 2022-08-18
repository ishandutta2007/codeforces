/*
Where is the rain that purifies and retaliates?
Where is the one I begged for strength to carry on?
Speak to me, I have followed through.
Deliver me from guilt. Take me home

To the source of white light I offer my place.
My sacrifice for its life.
The guilt that stains me vanishes on the other side.

Where is the rain that purifies and retaliates?
Where is the one I begged for strength to carry on?
Walking along the river's flow.
A journey away from original sin.

You and I merge, we become one.
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
#define eps 1e-11
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
#define double long double

using namespace std;

vector<pair<long, long> > ev;
long n,m,d,a,b,t;
long long ans;
long dp[310][155000];
long span;
stack<pair<long, long> > s1;
stack<pair<long, long> > s2;
long long answ;

void clean()
{
     while (s1.size())s1.pop();
     while (s2.size())s2.pop();
}

long tval;

void add(long val)
{ 
 if (s1.size())tval=s1.top().second;
 else tval=-1e9;
 
 tval=max(tval,val);
 s1.push(make_pair(val,tval));
}

long gett()
{
long res=-1e9;
//cout<<s1.size()<<" "<<s2.size()<<" "<<s1.size()endl;
//if (s1.size()+s2.size()==0)cout<<"%"<<endl;

if (s1.size())res=max(res,s1.top().second);
if (s2.size())res=max(res,s2.top().second);
return res;
}

void dodel()
{
 if (s2.size()==0)
 {
  long mx=-1e9;
  while (s1.size())
  {
   long tt=s1.top().first;
   mx=max(mx,tt);
   s2.push(make_pair(tt,mx));
   s1.pop();
  }
 }
 s2.pop();
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>d;
for (int i=1;i<=m;i++)
{
 cin>>a>>b>>t;
//a=b=t=1;
 ev.push_back(make_pair(t,a));
 ans+=b;
}

sort(ev.begin(),ev.end());

for (int i=1;i<=n;i++)
dp[0][i]=-abs(ev[0].second-i);

for (int i=1;i<m;i++)
{
 
 clean();
 
 span=ev[i].first-ev[i-1].first;
 if (n/d<span)span=n;else span*=d;
 for (int j=1;j<=span+1&&j<=n;j++)
 {
     add(dp[i-1][j]);
 }
 for (int j=1;j<=n;j++)
 {
     if (j>1&&j+span<=n)add(dp[i-1][j+span]);
     if (j-span>1)dodel();
     dp[i][j]=gett();
     
     long temp=-1e9;
     for (int q=1;q<=n;q++)
     if (abs(q-j)<=span)temp=max(temp,dp[i-1][q]);
   /*  if (temp!=gett()){
     cout<<i<<" ^^"<<j<<" "<<" "<<temp<<" "<<gett()<<" "<<endl;
     if (s1.size())cout<<s1.size()<<"   "<<" "<<span<<" "<<
     s1.top().first<<" "<<s1.top().second<<endl;}
    */
     //cout<<gett()<<endl;
     
     dp[i][j]-=abs(j-ev[i].second);
     
 }
}


answ=-1e9;
for (int i=1;i<=n;i++)answ=max(answ,0ll+dp[m-1][i]);
//cout<<answ<<endl;

answ+=ans;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}