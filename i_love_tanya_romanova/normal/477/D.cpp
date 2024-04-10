/*
Should we come to sail for the mellow and grey
Would it bring us comfort say, just a rainy day away
I've got a little something on my mind
A little line of evening rhyme, a boogie bubble refrain again

Come let's dream some, come take a ride in my dream machine
Let's make a funny one, let's take a ride in my dream machine

Should we come to stray in this nightmare play
I would like to ask you if I may dream today away
And for about a year we'd loose this fear
Of old men going nowhere near the grey to play the game

Come let's dream some, come take a ride in my dream machine
Let's make a funny one, let's take a ride in my dream machine
And when the dream is done, it's time to have another one
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long long pw[1<<20];
string st;
long long hash[1<<20];
pair<long,long >tp;
long mag[220];

// len - op
pair<long, long> better(pair<long, long> p1,pair<long, long> p2)
{
 if (p1.first>10000)return p2;
 if (p2.first>10000)return p1;
 if (p1.first>20&&p2.first<=20)
  return p2;
 if (p1.first<=20&&p2.first>20)return p1;
 
 if (p1.first<=20&&p2.first<=20)
 {
  if (p1.second+mag[p1.first]>p2.second+mag[p2.first])return p2;
  if (p1.second+mag[p1.first]<p2.second+mag[p2.first])return p1;
  return p1;
 }
 if (p1.first<p2.first)return p1;
 if (p1.first>p2.first)return p2;
 if (p1.second<p2.second)return p1;
 if (p1.second>p2.second)return p2;
 return p2;
}

long long ghash(long l,long r)
{
 return (hash[r+1]-hash[l])*pw[10000-l];
}

bool les(long p1,long p2,long span)
{
 long l,r;
 l=0;
 r=span;
 while (l<r)
 {
  long mid=l+r+1;
  mid/=2;
  long long h1,h2;
  h1=ghash(p1,p1+mid-1);
  h2=ghash(p2,p2+mid-1);
  if (h1==h2)
  l=mid;
  else r=mid-1;
 }
// if (p1==1&&p2==3)cout<<"%"<<l<<endl;
 if (l==span)return true;// equal
 //cout<<l<<" "<<endl;
 return st[p1+l]<st[p2+l];
}

void add(long&a,long&b)
{
 a+=b;
 if (a>=bs)a-=bs;
}

long dp[5010][5010],sums[5010][5010];
pair<long, long> bst[5010][5010];

long eval(long l,long r)
{
 long s=0;
 for (int i=l;i<=r;i++){s=s*2+st[i]-48;s%=bs;}
 return s;
}

long limm;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/rai06.in","r",stdin);
//freopen("C:/rai06.out","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pw[0]=1;
for (int i=1;i<=11111;i++)
 pw[i]=pw[i-1]*173;
 
cin>>st;

/*for (int i=0;i<5000;i++)
 st+=rand()%2+'a';
 cout<<st<<endl;
 */
for (int i=1;i<=st.size();i++)
{
 hash[i]=hash[i-1]+st[i-1]*pw[i];
}

for (int i=1;i<=30&&i<=st.size();i++)
 mag[i]=eval(st.size()-i,st.size()-1);
 
for (int i=st.size()+1;i<=st.size()+5;i++)
 hash[i]=hash[i-1];
 
int n=st.size();

long a,b;
//while (cin>>a>>b)
//cout<<eval(a,b)<<endl;

for (int i=0;i<=n+5;i++)
 for (int j=0;j<=n+5;j++)
  bst[i][j]=make_pair(1000000,0);
  
/*long a,b,c;
while (cin>>a>>b>>c)
cout<<les(a,b,c)<<endl;
*/
/*cout<<ghash(1,2)<<endl;
cout<<ghash(3,4)<<endl;
*/
for (long i=n-1;i+1;--i)
{
 for (long j=n-i;j>=1;--j)
 {
  bst[i][j]=better(bst[i][j],bst[i][j+1]);
  if (st[i]=='0')continue;
  if (j+i==n){bst[i][j]=make_pair(j,1);dp[i][j]=1;
  //cout<<eval(i,j-1)<<"   "<<i<<"  "<<j<<endl;
  }
  if (j*2+i<=n)// end here was the bug:)
  {
   limm=j+1;
   if (les(i,i+j,j))limm=j;
   add(dp[i][j],sums[i+j][limm]);
   tp=bst[i+j][limm];
  // cout<<i<<"  "<<j<<" "<<limm<<endl;
   tp.second++;
   if (tp.second==bs)tp.second=0;
   
   //if (sums[i+j][limm])
   bst[i][j]=better(bst[i][j],tp);
  }
 }
 for (int j=n;j+1;--j){
  add(sums[i][j],sums[i][j+1]);
  add(sums[i][j],dp[i][j]);}
}
/*
for (int i=0;i<n;i++)
{
 for (int j=0;j<=n;j++)
 cout<<dp[i][j]<<" ";
 cout<<endl;
}
cout<<endl;
for (int i=0;i<n;i++)
{
 for (int j=0;j<=n;j++)
 cout<<sums[i][j]<<" ";
 cout<<endl;
}*/

cout<<sums[0][1]<<endl;
//cout<<bst[0][1].first<<" "<<
long long res=bst[0][1].second;
//cout<<bst[0][1].first<<" "<<bst[0][1].second<<endl;
a=n-bst[0][1].first;
b=n-1;
res+=eval(a,b);
res%=bs;
cout<<res<<endl;

//cout<<bst[0][1].second<<endl;

cin.get();cin.get();
return 0;}