/*
Once again the same thing's on your mind
Increasing pulse from what goes on inside
Will you pay for what you've done? Hatred
Payback's such a bitch, her vengeance haunts you

So what's wrong tough guy, why the tears?
You drove me to this now you disappear

Now all those acts repaid, your turn to be afraid
Not longer almost done, oh God just what have I become
Now all those acts repaid, your turn to be afraid
Not longer almost done, oh God just what have I become

Try to fight you only make things worse
Screams of agony your final verse
Now you're begging for your life, breathless
All the times I bled my vengeance takes you

So what's wrong tough guy, why the tears?
You drove me to this now you disappear

Now all those acts repaid, your turn to be afraid
Not longer almost done, oh God just what have I become
Now all those acts repaid, your turn to be afraid
Not longer almost done, oh God just what have I become

Your sweetest dreams turn into fears
It's almost done, they're almost gone
Our darkest days they fade away
It's almost done, they're almost gone

So what's wrong tough guy, why the tears?
You drove me to this now you disappear
So what's wrong tough guy, why the tears?
You drove me to this now you disappear

Now all those acts repaid, your turn to be afraid
Not longer almost done, oh God just what have I become
Now all those acts repaid, your turn to be afraid
Not longer almost done, oh God just what have I become
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
#define bs 1000000000000000007ll
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long long pw[1<<20];
string st;
long m,n;
long long s;
multiset<pair<long long,long> > S;
pair<long long, long> tp;
long long ts;

long long mult(long long a,long long b)
{
 if (b==0) return 0;
 if (b%2) return (a+mult(a,b-1))%bs;
 return mult(a*2%bs,b/2);
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pw[0]=1;
for (int i=1;i<=777777;i++)
 pw[i]=mult(pw[i-1],137);
 
cin>>n>>m;
for (int i=0;i<n;i++)
{
 cin>>st;
 s=0;
 for (int j=0;j<st.size();j++)
  s+=mult(st[j],pw[j]),s%=bs;
 for (int j=0;j<st.size();j++)
  for (int q='a';q<='c';q++)
  {
      if (q==st[j])continue;
      ts=s-mult(pw[j],st[j])+bs;
      ts+=mult(pw[j],q)+bs;
      ts%=bs;
      S.insert(make_pair(ts,st.size()));
  }
}
for (int i=0;i<m;i++)
{
 cin>>st;
 s=0;
 for (int j=0;j<st.size();j++)
  s+=mult(st[j],pw[j]),s%=bs;
 tp=make_pair(s,st.size());
 if (S.find(tp)==S.end())
  cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}

cin.get();cin.get();
return 0;}