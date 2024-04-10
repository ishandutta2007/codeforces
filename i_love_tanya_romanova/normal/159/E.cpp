/*
Humanity peeled from our bones
Deprived of integuments that make us real
Shadows of flesh to maintain the system
Our own blood splashes as we kneel

So meticulously machined
Into these obedient devices
Puppets, fine tuned, submissive drones
Replicas of each other, clones

We're dormant accumulations of flesh
In a crimson filtered twilight
Mute witnesses to the game
Wrenches to keep the bolts of lies tight

We're the fabric concealing the stains
The red tainted existence
The gullibles to bless your sins away
Rags to wipe your blooded trails

We give in to the atrophy
To the twining of self-thought knowledge
The purpose of the human mind reviled
Everlasting ignorance realized
The scarlet flood that inundates our powerless thoughts
Defenseless minds with the lies overfed

Every thought stained, defiled
Painted the color, the shade of electric red
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

using namespace std;

long long n,c,s,cnt;
vector<pair<pair<long long, long long> ,long long> > v;
long long bst[300000],bp[300000],a1,a2;
long long ans;
vector<pair<long long, long long> > cng;
long nw;
long am1,am2;
vector<long long> v1,v2;
vector<long long> res;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>c>>s;
 v.push_back(make_pair(make_pair(c,s),i));
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());

for (int i=0;i<=200000;i++)
 bst[i]=-1e18;

s=0;

for (int i=0;i<v.size();i++)
{
 if (i>0&&v[i].first.first!=v[i-1].first.first)
 {cnt=0;s=0;
  for (int j=0;j<cng.size();j++)
  {
      bst[cng[j].first]=cng[j].second;
      bp[cng[j].first]=nw;
  }
  cng.clear();
 }
 
 cnt++;
 s+=v[i].first.second;
 if (s+bst[cnt+1]>ans)
 {
  ans=s+bst[cnt+1];
  a1=bp[cnt+1];
  am1=cnt+1;
  a2=v[i].first.first;
  am2=cnt;
 }
 if (s+bst[cnt]>ans)
 {
  ans=s+bst[cnt];
  a1=bp[cnt];
  am1=cnt;
  a2=v[i].first.first;
  am2=cnt;
 }
 if (s+bst[cnt-1]>ans)
 {
  ans=s+bst[cnt-1];
  a1=v[i].first.first;
  am1=cnt;
  a2=bp[cnt-1];
  am2=cnt-1;
 }
 if (s>bst[cnt])
 {
  cng.push_back(make_pair(cnt,s));
  nw=v[i].first.first;
/*  bst[cnt]=s;
  bp[cnt]=v[i].first.first;*/
 }
}


cout<<ans<<endl;
cout<<am1+am2<<endl;
for (int i=0;i<v.size();i++)
{
 if (v[i].first.first==a1&&am1>0)--am1,v1.push_back(v[i].second);
 if (v[i].first.first==a2&&am2>0)--am2,v2.push_back(v[i].second);
}

for (int i=0;i<v1.size();i++)
{
 res.push_back(v1[i]);
 if (i<v2.size())res.push_back(v2[i]);
}
for (int i=0;i<res.size();i++)
{
 if (i)cout<<" ";
 cout<<res[i];   
}
cout<<endl;
cin.get();cin.get();
return 0;}