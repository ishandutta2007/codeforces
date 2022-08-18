/*
Wash your back, so you won't stab mine
Get in bed with your own kind
Live your life, so you don't see mine
Drape your back, so you won't shine

Wash your back, so you won't stab mine
Get in bed with your own kind
Live your life, so you don't see mine
Drape your back, so you won't shine

Ooh, then she holds my hand
And I lie to get a smile
Ooh, then she holds my hand
And I lie to get a smile

Using what I want
To get what you want
Using what I want
To get what you want

Using what I want
To get what you want
Using what I want
To get what you want

Ooh, sweet Amber
How sweet are you?
How sweet does it get?
How sweet are you?
How sweet does it get?

Chase the rabbit, fetch the stick
She rolls me over 'til I'm sick
She deals in habits, deals in pain
I run away but I'm back again

Chase the rabbit, fetch the stick
She rolls me over 'til I'm sick
She deals in habits, deals in pain
I run away but I'm back again

Ooh, then she holds my hand
And I lie to get a smile
And she squeezes tighter
I still lie to get a smile

Using what I want
To get what you want
Using what I want
To get what you want

Using what I want
To get what you want
Using what I want
To get what you want

Ooh, sweet Amber
How sweet are you?
How sweet does it get?
How sweet are you?
How sweet does it get?

She holds the pen that spells the end
She traces me and draws me in
She holds the pen that spells the end
She traces me and draws me in

Ooh, sweet Amber
(Ooh, sweet Amber)

Ooh, sweet Amber
How sweet are you?
How sweet does it get?
How sweet are you?
How sweet does it get?

It's never as sweet as it seems
*/

#pragma comment(linker, "/STACK:16777216")
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

using namespace std;

vector<pair<long, long> > ans;
long p[20000],n,c[200000],q,ps;
long ttl,need;

void solve(long a,long b)
{
 ans.push_back(make_pair(a,b));
 swap(p[a],p[b]);
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>p[i];
for (int i=1;i<=n;i++)
{
 if (c[i]==0)
 {++ttl;
  q=i;while (c[q]==0)c[q]=1,q=p[q];}
}

cin>>need;
need=n-need;
if (ttl>need)
for (;ttl>need;--ttl)// merg
{
 for (int i=1;i<=n;i++)
  c[i]=0;
 ps=1;
 while (c[ps]==0)c[ps]=1,ps=p[ps];
 q=1;
 while (c[q])++q;
 solve(1,q);
}
else 
for (;ttl<need;ttl++)// splt
{
 for (int i=1;i<=n;i++)
  c[i]=0;
 ps=1;
 while (p[ps]==ps)++ps;
 q=ps;
 while (c[q]==0){c[q]=1;q=p[q];}
 q=ps+1;
 while (c[q]==0)++q;
 solve(ps,q);
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i].first<<" "<<ans[i].second;
}
cout<<endl;

cin.get();cin.get();
return 0;}