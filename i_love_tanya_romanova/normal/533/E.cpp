/*
Discontent slowly drifting far away
Low feeling no healing a heart of stone
And as I plunder
As I fall astray
And if I should wander
Could you help me find my way
Intercept lonely tears along the way
No passage here after, you're on your own
And as I plunder
As I fall astray
And if I should wander
Could you help me find my way
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

using namespace std;

long long pw1[1<<20],pw2[1<<20];
long n;
string st1,st2;
long long s1[1<<20],s2[1<<20];

vector<pair<long, long> > S;
vector<pair<long, long> > V;
vector<pair<long, long> >::iterator it;
long ans;
pair<long, long> tp;

pair<long, long> get_hash(long ps,long ad)
{
 long long v1,v2;
 v1=s1[ps]+(s1[n]-s1[ps])*pw1[1]+ad*pw1[ps];
 v1%=bs;
 if (v1<0)v1+=bs;
 v2=s2[ps]+(s2[n]-s2[ps])*pw2[1]+ad*pw2[ps];
 v2%=bs;
 if (v2<0)v2+=bs;
 pair<long, long> res;
 res.first=v1;
 res.second=v2;
 return res;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st1;

/*st1="";
for (int i=0;i<100000;i++)
 st1+=rand()%26+'a';
 */
pw1[0]=1;
pw2[0]=1;
for (int i=1;i<(1<<20);i++)
{
 pw1[i]=pw1[i-1]*173%bs;
 pw2[i]=pw2[i-1]*137%bs;
}

for (int i=0;i<st1.size();i++)
{
    s1[i+1]=s1[i]+pw1[i]*st1[i];
    s2[i+1]=s2[i]+pw2[i]*st1[i];
    s1[i]%=bs;
    s2[i]%=bs;
}

for (int i=0;i<=st1.size();i++)
{
    for (int ad='a';ad<='z';ad++)
    {
     tp=get_hash(i,ad);
     S.push_back(tp);
/*     if (i==0&&ad=='t')
      cout<<tp.first<<" "<<tp.second<<endl;*/
    }
}

sort(S.begin(),S.end());
// -- copy paste

cin>>st1;
/*st1="";
for (int i=0;i<100000;i++)
 st1+=rand()%26+'a';
 */
for (int i=0;i<st1.size();i++)
{
    s1[i+1]=s1[i]+pw1[i]*st1[i];
    s2[i+1]=s2[i]+pw2[i]*st1[i];
    s1[i]%=bs;
    s2[i]%=bs;
}

for (int i=0;i<=st1.size();i++)
{
    for (int ad='a';ad<='z';ad++)
    {
     tp=get_hash(i,ad);/*
     if (i==2&&ad=='e')
      cout<<tp.first<<" "<<tp.second<<endl;
      */
     V.push_back(tp);
    }
}

sort(V.begin(),V.end());
for (int i=0;i<V.size();i++)
{
    if (i>0&&V[i]==V[i-1])continue;
    it=lower_bound(S.begin(),S.end(),V[i]);
    if (it!=S.end()&&(*it)==V[i])++ans;
//    if (S.find(V[i])!=S.end())++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}