/*
What would be my thoughts if the bleeding skies should be burn
and should be the last light on the earth?
What would be my thoughts if I live my end like
my dream which I too often saw and hoped?

Humans are the fear and the hate!
We are the shame of us.
Humans are the plague and the dust!
We are the end of ourselves.

Although I called upon our morbid end
I have always dread and hope to life still
stay in weakness until I crave the life
guarding pride and ready to fuckin' die...

What would be my thoughts if I live my end like
my dream which I too often saw and hoped?

Through the virgin sky
I see red flames on the earth
I am afraid to see darkness replaces lives...

Apocalyptic day... A world which I liked too much
Apocalyptic day... A thousand falling skies...

The universal genocide arrives from this red sky
You always lived through the eyes of others
The flames will fall down burning humanity
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
 
using namespace std;

long n,x[1<<19],y[1<<19],tests,ans[1<<19],tx,ty,ll,rr;
long r[1<<19];

vector<pair<long, long> > v;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>x[i]>>r[i];
 v.push_back(make_pair(x[i],i));
 ans[i]=1e9;
}

sort(v.begin(),v.end());

long iter=0;

cin>>tests;
for (;tests;--tests)
{
    ++iter;
 cin>>tx>>ty;
 ll=0;
 rr=n-1;
 if (tx<x[v[0].second]-r[v[0].second])continue;
 while (ll<rr)
 {
  long mid=ll+rr+1;
  mid/=2;
  if (x[v[mid].second]-r[v[mid].second]<=tx)
   ll=mid;
   else rr=mid-1;
 }
 if ((tx-x[v[ll].second])*(tx-x[v[ll].second])+(ty-y[v[ll].second])*(ty-y[v[ll].second])<=r[v[ll].second]*r[v[ll].second])
  ans[v[ll].second]=min(ans[v[ll].second],iter);
 // cout<<ll<<" %"<<endl;
 if (ll==0)continue;--ll;
 if ((tx-x[v[ll].second])*(tx-x[v[ll].second])+(ty-y[v[ll].second])*(ty-y[v[ll].second])<=r[v[ll].second]*r[v[ll].second])
  ans[v[ll].second]=min(ans[v[ll].second],iter);
 
}

long cnt=0;
for(int i=1;i<=n;i++)
 if (ans[i]<1e6)
  cnt++;

cout<<cnt<<endl;
for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    if (ans[i]>1e6)ans[i]=-1;
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}