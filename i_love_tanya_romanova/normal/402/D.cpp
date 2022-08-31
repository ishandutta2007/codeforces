/*
Every time I think about how you act 
You got no life, you got no respect 
Yeah every time I think about how you act 
You got nothing, nothing left... 

Leeches and hypocrites 
They even steal the air we breathe 
Pretending and faking it 
To be something they cannot be... 

You come around when you know you need something 
Stick around and try to get anything 
But I know who's really down with me 
Back tha fuck up you bumbklaatt enemy... 

Boom 
Watchugot? 
Watchuwatchugot? 
Watchugot? 
Boom 

Happiness is to give back 
Love one another, have respect 
Give more to receive less 
Give life, soul and fire 

Using people like they are tools 
Treating them like they're just fools 
Always quiet but I know what you do 
God knows and you will too... 

Fuck you, you fuckin' disgrace 
And then you act like everything's the same 
I don't dig it, I don't play mind games 
Don't fuck with me and my friends 

Give more to receive more 
Give life, soul and fire
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,ar[200000];
set<long> bad;
long q;
long ans,s,tans;
long temp;
long gcd(long a,long b)
{
 while( a&&b)a>b?a%=b:b%=a;
 return a+b;
}

set<long>done;
map<long, long> val;
long ps,tcost;

long gett(long x)
{
 long xx=x;
 if (done.find(x)!=done.end())return val[x];
 done.insert(x);
 long cost=0;
 
 for (int i=2;i*i<=x;i++)
 {
  while (x%i==0)
  {
   if (bad.find(i)!=bad.end())
   cost--;
   else cost++;
   x/=i;
  }
 }
 
 if (x>1)
 {
  if (bad.find(x)==bad.end())
   cost++;
   else cost--;
 }
// cout<<"%"<<xx<<" "<<cost<<endl;
 val[xx]=cost;
 return cost;
}

void showw(long x)
{
 for (int i=2;i<=x;i++)
 {
  while(x%i==0){cout<<i<<" ";x/=i;}
 }
 cout<<endl;
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=1;i<=m;i++)
{
  cin>>q;
  bad.insert(q);
}

while (true)
{
 ps=0;
 temp=0;
 tcost=0;
 
 for (int i=1;i<=n;i++)
 {
  temp=gcd(temp,ar[i]);
  if (gett(temp)<0)ps=i,tcost=temp;
  //cout<<temp<<" "<<gett(temp)<<endl;
  //showw(temp);
 }
 if (ps==0)break;
 for (int i=1;i<=ps;i++)
 ar[i]/=tcost;
// cout<<ps<<endl;
 
}

for (int i=1;i<=n;i++)
ans+=gett(ar[i]);

cout<<ans<<endl;

cin.get();cin.get();
return 0;}