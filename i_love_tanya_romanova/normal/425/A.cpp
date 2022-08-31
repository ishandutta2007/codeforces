/*
She used to be a viper
An expert of the kill
A deadly assassin
Of outstanding skills
Master of the sword
Champion of the fight
Beware - here comes the bride

Angry and wild
Screaming out for vengeance
Driven by the fire of revenge
Severing heads
In the blink of an eye
Taking back her pride

Without a warning
The angel appears
Taking her right
Without a warning
Beware of the bride
Deadly vipers

Bang bang her baby
Shot her straight through the head
She stayed alive
Refusing to be dead
And now she's back
From the years in the night
Beware - here comes the bride

Eye for an eye
Merciless and cold
She serves the meal at its best
Hunting down the vipers
One by one
She will not rest

Without a warning
The angel appears
Taking her right
Without a warning
Beware of the bride

Out in the desert
He kissed her goodbye
Bleeding and sentenced to die
Shot through the head
But barely alive
The bride did survive

Angry and wild
Screaming out for vengeance
Pleasing her hunger for revenge
They took it all
And now they're gonna pay
And she's on her way

Without a warning
The angel appears
Taking her right
Without a warning
Beware of the bride
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
#define bs 1000000009
#define bsize 256

using namespace std;

vector<long> f,has;
long ar[20000];
long n,k,ans,s;
long ts;

void ad(long x)
{
long q=0;
while (q<has.size()&&has[q]<=x)++q;
has.insert(has.begin()+q,x);
}

void er(long x)
{
 long q=0;
 while (f[q]!=x)++q;
 f.erase(f.begin()+q);
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>k;

ans=-1e9;

for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int start=1;start<=n;start++)
{
 f.clear();
 
 for (int i=1;i<=n;i++)
 f.push_back(ar[i]);
 sort(f.begin(),f.end());
 reverse(f.begin(),f.end());
 
 has.clear();
 s=0;
 for (int i=start;i<=n;i++)
 {
  ad(ar[i]);
  s+=ar[i];
  er(ar[i]);
  /*for (int j=0;j<has.size();j++)
  cout<<has[j]<<" ";
  cout<<endl;
  */
  ts=s;
//  cout<<s<<endl;
  for (int j=0;j<k&&j<has.size()&&j<f.size();j++)
   if (has[j]<f[j])
   ts=ts-has[j]+f[j];
  ans=max(ans,ts);
 }
 
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}