/*
When you come to a fork in road
You can almost taste it
Never knowing which way to go
It's not been tested
All alone you try to take it, to fake it
And is the road less traveled taken
Or forsaken?

Now
It's up to you
The path that you choose
Gotta do something different
Now
It's all the same
No one to blame
Gotta do something different
Now
So you head down the road that you chose
Just keep pushing forward
And the window is trying to close
Just to shut you out
All alone you try to take it, to fake it
And is the road less traveled taken
Or forsaken?

Now
It's up to you
The path that you choose
Gotta do something different
Now
It's all the same
No one to blame
Gotta do something different

Something different

It's up to you
The path that you choose
Gotta do something different
Now
It's all the same
No one to blame
Gotta do something different

Now
It's up to you
The path that you choose
Gotta do something different
Gotta do something different
Now.
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long long ar[220000],start,ans;
vector< long long> has;
long long n,t,span,dv;
long long cur;

void nw()
{
 has.clear();
 if (ar[cur]!=-1)
 has.push_back(cur);
 start=cur;
 ans++;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
has.clear();

start=1;
ans=1;
for (int i=1;i<=n;i++)
{
 cur=i;
 cin>>ar[i];
 if (ar[i]==-1){if (has.size()<2)continue;//cout<<" %"<<span<<endl;
 t=has.back();if (ar[t]+(i-t)*1ll*span<=0)nw();
 continue;}
 if (has.size()>=2)
 {
  t=has.back();
  if ((ar[i]-ar[t])!=1ll*span*(i-t)){nw();continue;}
 } 
 if (has.size()==0)
 {
  has.push_back(i);
  continue;
 }
 t=has.back();
 span=i-t;
 dv=ar[i]-ar[t];
 if (dv%span){nw();continue;};
 dv/=span;
 span=dv;
 t=ar[i]-1ll*dv*(i-start);
 if (t<=0){nw();continue;}
// cout<<"%"<<endl;
 has.push_back(i);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}