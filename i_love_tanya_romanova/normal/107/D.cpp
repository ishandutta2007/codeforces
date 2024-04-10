/*
I'm nothing and all things
I drift between dimensions
I'm lifeless, immortal
Collapsed duality

My language is wordless
A silent scream to your ears
Enigma in plain sight
Time, space anomaly

Quantumleaper
Found unfound
Voice of reason
Lost its tongue

If you rise I'll fall, unknown once I was known
Choose where I can't go and I am there
If you rise I'll fall, unknown once I was known
Even when I'm gone you know I'm here

I'm right here and nowhere
Upon me rests creation
I am wave and lepton
The eerie paradox

Wrong focus, wrong methods
This way you'll never get me
Exclude flesh, include mind
And drift along with me

Quantumleaper
Found unfound
Voice of reason
Lost its tongue

If you rise I'll fall, unknown once I was known
Choose where I can't go and I am there
If you rise I'll fall, unknown once I was known
Even when I'm gone you know I'm here

You observe me in a grain of sand
Infinity beheld
Universe in the palm of your hand
Infinity unveiled

View this progress as an omen
When mind allows, feel it pull you further down

Quantumleaper
Found unfound
Voice of reason
Lost its tongue

If you rise I'll fall, unknown once I was known
Choose where I can't go and I am there
If you rise I'll fall, unknown once I was known
Even when I'm gone you know I'm here
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

long base;
vector<long> vec[2000];
long can[200][200];
long lcm[200];
long long n,k;

vector<vector<long> > mult(vector<vector<long> > a,
vector<vector<long> > b)
{
 vector<vector<long> > v;
 v.resize(a.size());
 for (int i=0;i<v.size();i++)
  v[i].resize(a[0].size());
 for (int i=0;i<v.size();i++)
  for (int j=0;j<v.size();j++)
   v[i][j]=0;
 
 for (int k=0;k<v.size();k++)
  for (int i=0;i<v.size();i++) 
   for (int j=0;j<v.size();j++)
    v[i][j]+=a[i][k]*b[k][j],
    v[i][j]%=base;
 return v;
}

vector<vector<long> > one(long sz)
{
 vector<vector<long> > v;
 v.resize(sz);
 for (int i=0;i<v.size();i++)
  v[i].resize(sz);
 for (int i=0;i<v.size();i++)
  for (int j=0;j<v.size();j++)
   v[i][j]=(i==j);
 return v;
}

vector<vector<long> > pw(vector<vector<long> > a,long long b)
{
 if (b==0)return one(a.size());
 if (b%2)return mult(a,pw(a,b-1));
 return pw(mult(a,a),b/2);
}

vector<long> decomp(long state)
{
 vector<long> res;
 for (int i=25;i>=0;--i)
  if (vec[i].size())res.push_back(state%lcm[i]),state/=lcm[i];
  else res.push_back(1);
 reverse(res.begin(),res.end());
 
 return res;
}

long mov(long a,long b)
{
 vector<long> v1,v2;
 v1=decomp(a);
 v2=decomp(b);
/* for (int i=0;i<v1.size();i++)
  cout<<v1[i]<<" ";
  cout<<endl;
  for (int i=0;i<v2.size();i++)
   cout<<v2[i]<<" ";
   cout<<endl;
   cout<<endl;
  */ 
 long free=0;
 long found =0;
 
 for (int i=0;i<26;i++)
 {
  if (vec[i].size()==0)continue;
  if ((v1[i]+1)%lcm[i]==v2[i])
  {
   if (lcm[i]==1)free++;
   else if (found==0)found=1;
   else return 0;
  }
   else if (v1[i]!=v2[i])return 0;
 } 
 if(found)return 1;// mv dng
 return free;// mv 1
}

string st;
long val;
long total;
long gcd(long a,long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}
vector<vector<long> > res;

bool bad(long x,long ps)
{
 for (int i=0;i<vec[ps].size();i++)
  if (x%vec[ps][i]==0)
   return false;
 return true;
}

bool check(vector<long> v)
{
 for (long i=0;i<26;i++)
 {
  if (vec[i].size()==0)continue;
  if (bad(v[i],i))return false;
 }
 return true;
}

void show(vector<vector<long > > v)
{
 for (int i=0;i<v.size();i++)
 {
  for (int j=0;j<v[i].size();j++)
   cout<<v[i][j]<<" ";
  cout<<endl;
 }
 cout<<endl;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

base=12345;

cin>>n>>k;

for (int i=1;i<=k;i++)
{
 cin>>st>>val;
 vec[st[0]-'A'].push_back(val);
 can[st[0]-'A'][val]=1;
}

total=1;
for (int i=0;i<26;i++)
if (vec[i].size())
{
 lcm[i]=1;
 for (int j=0;j<vec[i].size();j++)
 {
  long q=vec[i][j];
  lcm[i]=lcm[i]*q/gcd(lcm[i],q);
 }
 total*=lcm[i];
}

res.resize(total);
for (int i=0;i<res.size();i++)
 res[i].resize(total);
 
for (int i=0;i<total;i++)
 for (int j=0;j<total;j++)
  res[i][j]=mov(i,j);

//show(res);
res=pw(res,n);
//show(res);

long ans=0;


for (int i=0;i<total;i++)
 {
  vector<long> v=decomp(i);
  if (check(v))ans+=res[0][i],ans%=base;
 }
 cout<<ans<<endl;
 
cin.get();cin.get();
return 0;}