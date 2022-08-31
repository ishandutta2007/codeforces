/*
I had wrists donning slits flowing constantly
My broken body in a wreck, I'm wrapped around a tree
A crosswalk hit and run, the finish line for me
People clutter in the gutter, take a look and see

No escaping pain, you belong to me
Clingin' on to life by the skin of my teeth
No escaping pain, you belong to me
Clingin' on to life by the skin of my teeth

And my blood flows through the streets, deluge from the wounds
Empty jars of sleeping pills on the dresser in my room
And my wet brain neighbor cranes his neck to see
In time the white light's a train bearing down on me

No escaping pain, you belong to me
Clingin' on to life by the skin of my teeth
No escaping pain, you belong to me
Clingin' on to life by the skin of my teeth

I won't feel the hurt, I'm not trash any longer
You know that it doesn't kill me, it only makes me stronger
I need a ride to the morgue that's what 911 is for
So tag my toe and don't forget, ooh to close the drawer

No escaping pain, you belong to me
Clingin' on to life by the skin of my teeth
No escaping pain, you belong to me
Clingin' on to life by the skin of my teeth
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs1 1000000007ll
#define bs2 1000000009ll
#define P1 173
#define P2 187
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st,zr;
long long pw1[1<<20],pw2[1<<20],s1,s2;
pair<long long, long long> need;
long long n;
long long lent;
long long ts1[1<<20],ts2[1<<20],temp,dp[1<<20],val1,val2;
long long sdp[1<<20];
long long ans;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>zr;
pw1[0]=1;
pw2[0]=1;
for (int i=1;i<=300000;i++)
{
    pw1[i]=pw1[i-1]*P1%bs1;
    pw2[i]=pw2[i-1]*P2%bs2;
}

for (int i=0;i<zr.size();i++)
{
 s1=s1+zr[i]*pw1[i];
 s1%=bs1;
 s2=s2+zr[i]*pw2[i];
 s2%=bs2;
}

s1*=pw1[200000];
s2*=pw2[200000];
s1%=bs1;
s2%=bs2;
need=make_pair(s1,s2);

// upd dp here

n=st.size();

lent=-1;

dp[0]=1;
sdp[0]=1;

for (int i=1;i<=st.size();i++)
{
 ts1[i]=ts1[i-1]+st[i-1]*pw1[i-1];
 ts2[i]=ts2[i-1]+st[i-1]*pw2[i-1];
 ts1[i]%=bs1;
 ts2[i]%=bs2;
 temp=dp[i-1];
 dp[i]=temp;
 
 if (i>=zr.size()) // take it
 {
  val1=ts1[i]-ts1[i-zr.size()];
  val2=ts2[i]-ts2[i-zr.size()];
  val1*=pw1[200000-i+zr.size()];
  val2*=pw2[200000-i+zr.size()];
  val1%=bs1;
  val2%=bs2;
  if( val1<0)val1+=bs1;
  if (val2<0)val2+=bs2;
  if (val1==need.first&&val2==need.second)
   lent=i-zr.size();
//  cout<<st[i-1]<<" "<<val1<<"  "<<val2<<" "<<need.first<<" "<<need.second<<" "<<lent<<endl;
 }
 if (lent!=-1)
  {
   dp[i]+=sdp[lent];
   dp[i]%=bs1;
   ans=ans+sdp[lent];
   ans%=bs1;
  }
  sdp[i]=sdp[i-1]+dp[i];
  sdp[i]%=bs1;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}