/*
One two
One two three four

Total eclipse hides the earth
The night of doom has come
Antichrist soldiers are proclaimed
Send souls to Hell

Catastrophe destruction
Mankind without mercy
Suphul clouds are in the air
Legions winds corrose the universe

The Messiah, redeemers of mankind
Chained in the valley of hades
Crowds blinded by evil
Only death is real
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

long long n,k,ar[4500000];
long long p;
vector<pair<long long, long long> > tv;
vector<long long> vec,nvec;
vector<pair<long long, long long> > tvec;
long long p1,m;
long long todel,lwr,temp,temp1,temp2;
long long ans;
long long ttl;
pair<long long, long long> tp;
long cd[8500000];



int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

p=1;
for (int i=2;i<=n;i++)
{
 if (ar[i]>ar[i-1])continue;
 if (i!=p+1)
 {
  tv.push_back(make_pair(p,i-1));
 }p=i;
}

if (ar[n]>ar[p])tv.push_back(make_pair(p,n));

vec.push_back(1e17);
for (int i=0;i<tv.size();i++)
{
 if (i>0)vec.push_back(ar[tv[i-1].second]-ar[tv[i].first]);
 vec.push_back(ar[tv[i].second]-ar[tv[i].first]);
}

for (int i=0;i<tv.size();i++)
ans+=ar[tv[i].second]-ar[tv[i].first];

//if (vec.size()>1000){cout<<ans<<endl;return 0;}

vec.push_back(1e17);

ttl=tv.size();

if (k<ttl)m=ttl-k;
else m=0;

while (m>0)
{
 tvec.clear();
 for (int i=0;i<vec.size();i++)
 tvec.push_back(make_pair(vec[i],i));
 p1=m;
 if (p1>=vec.size())p1=vec.size();
 random_shuffle(tvec.begin(),tvec.end());
 nth_element(tvec.begin(),tvec.begin()+p1-1,tvec.end());
 
 for (int i=0;i<vec.size();i++)
 cd[i]=0;
 
 for (int i=0;i<p1;i++)
 cd[tvec[i].second]=1;
 //todel=tvec[p1-1];
/* p1=m;
 nth_element(tvec.begin(),tvec.begin()+p1-1,tvec.end());
 lwr=tvec[p1-1];
 */
 nvec.clear();
 for (int i=0;i<vec.size();i++)
 {
  if (i>0&&i+1<vec.size()&&vec[i]<=vec[i-1]&&vec[i]<=vec[i+1])continue;else cd[i]=0;
 }
 
 while (vec.size())
 {
  temp=vec.back();
  vec.pop_back();
  if (m>0&&cd[vec.size()]==1)
  {
   temp1=vec.back();
   vec.pop_back();
   temp2=nvec.back();
   nvec.pop_back();
   temp2=temp2+temp1-temp;
   ans-=temp;
   nvec.push_back(temp2);
   if (vec.size()){temp=vec.back();vec.pop_back();nvec.push_back(temp);}
   --m;
  }
  else nvec.push_back(temp);
 }
 vec=nvec;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}