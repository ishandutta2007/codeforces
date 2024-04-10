/*
A dying romance, bleeding for my sensation
Would Death unmask the azure of the creation?
Oh, stay far from my crown of certainties

A dying romance, the blindman's torch of ideals
Men of stories, don't try to robe my morningstar
Cause it will never shine in your eden

A dying romance, withered by your naivity
The scent that I perceive comes from words
Which escaped your mouth of flies
Selfish, fetid romance
You lick the shit of this world

Men's quintessence sways in streams of hope
Drowning in silvercups always used at funerals
Marvellous, when even Death tries to flee from you
The flames leave their candles, soon they will die, too

Immune to life... I'll always die
In the palms of heaven, where serpents lie
Bedeviled Paradise... web of all sin
Ethereal shadows rise, postmortem redeemed!
Selfish, fetid romance
You lick with a tongue of thorns!
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
//#include <memory.h>

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
//#define N 120000

using namespace std;

long n;
long pr[300000];
vector<pair<long, long> > ans;
vector<long> vec;
long used[300000];
long calc[2000];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
pr[1]=1;
for (int i=2;i<=100000;i++)
 if (pr[i]==0)
  for (int j=i*2;j<=100000;j+=i)
   pr[j]=1;

for (int i=3;i*2<=n;i++)
 if (pr[i]==0)
 {
  vec.clear();
  for (int j=i;j<=n;j+=i)
  {
   if (used[j]==0)
    vec.push_back(j);
  }
  if (vec.size()%2)
  {
   vec.erase(vec.begin()+1,vec.begin()+2);
  }
  /*for (int j=0;j<vec.size();j++)
   cout<<vec[j]<<"% ";
   cout<<endl;
  */for (int j=0;j<vec.size();j+=2)
  {
   ans.push_back(make_pair(vec[j],vec[j+1]));
   used[vec[j]]=used[vec[j+1]]=1;
  }
 }

vec.clear();

for (int i=2;i<=n;i++)
{
 if (used[i]==0&&i%2==0)
  vec.push_back(i);
}
 
  for (int j=0;j+1<vec.size();j+=2)
  {
   ans.push_back(make_pair(vec[j],vec[j+1]));
   used[vec[j]]=used[vec[j+1]]=1;
  }

/*for (int i=0;i<ans.size();i++)
 calc[ans[i].first]++,calc[ans[i].second]++;

for (int i=1;i<=100;i++)
 if (calc[i]>1)cout<<"%"<<i<<endl;
 */
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
 
cin.get();cin.get();
return 0;}