/*
Endless days
We search for what we hold inside
So hard to find, luck turns
Will the fallen ever reach within and rise again

For the rest of my life
I will find the answers that were always here
I will find the meaning this time
I will fight the end till the end is here

Wasted time
With words that seem to break our will
They bind us still without a care
They tarnish what we hold so dear, what was once so clear

For the rest of my life
I will find the answers that were always here
I will find the meaning this time
I will fight the end till the end is here
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define count adsgasdgasdg

using namespace std;

long long n,k,S,ar[1<<10];
vector<long long> v1,v2;
vector<pair<long long, long long> > V1,V2;
map<pair<long long, long long> ,long long> cnt;
long long ans;
long long fact[1<<20];
long long val,used,rem,need;
pair<long long, long long> tp;

vector<pair<long long, long long> > generate(vector<long long> v)
{
 vector<pair<long long, long long> > res;
 long n=v.size();
 
 long ttl=1;
 for (int i=0;i<v.size();i++)
  ttl=ttl*3;
 
 for (int mask=0;mask<ttl;mask++)
 {
  long oflow=0;
  long long s=0;
  long bits=0;
  long qm=mask;
  
  for (int i=0;i<v.size();i++)
  {
   if (qm%3==0)
   {
    bits++;
    if (v[i]>20){oflow=1;}
    else s+=fact[v[i]];
    if (s>1e17)oflow=1;
   }
   else if (qm%3==1)
   {
    s+=v[i];
    if (s>1e17)oflow=1;
   }
   qm/=3;
  }
   if (oflow==0)
    res.push_back(make_pair(s,bits));
 }
// cout<<"%"<<ttl<<" "<<res.size()<<endl;
 return res;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

fact[0]=1;
for (int i=1;i<=20;i++)
 fact[i]=fact[i-1]*i;
 
cin>>n>>k>>S;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=1;i<=n/2;i++)
 v1.push_back(ar[i]);

for (int i=n/2+1;i<=n;i++)
 v2.push_back(ar[i]);

V1=generate(v1);
V2=generate(v2);
/*
for (int i=0;i<V1.size();i++)
{
 cout<<V1[i].first<<" "<<V1[i].second<<endl;
}
cout<<endl;

for (int i=0;i<V2.size();i++)
{
 cout<<V2[i].first<<" "<<V2[i].second<<endl;
}
cout<<endl;
*/
for (int i=0;i<V2.size();i++)
{
 cnt[V2[i]]++;
}

for (int i=0;i<V1.size();i++)
{
 val=V1[i].first;
 used=V1[i].second;
 rem=k-used;
 if (rem<0)continue;
 need=S-val;
 for (int j=0;j<=rem;j++)
 {
  tp=make_pair(need,j);
  ans+=cnt[tp];
 }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}