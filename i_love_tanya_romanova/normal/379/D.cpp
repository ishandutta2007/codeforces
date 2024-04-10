/*
This time I'll try not to get hurt
This time I'll stay untouched with pain and dirt
This time I'll stick to what I've learned
This time I'll fly so low I won't get burned

Maybe it's not enough
Maybe this time it's just too much
Maybe I'm not that tough
Maybe this time the road is just too rough
Walk down, so I sit down, mmh...

I've walked this road so many years
I've worn down all my boots, I've cried all tears
So many crossroads left behind
So many choices burned into my mind

Maybe it's not enough
Maybe this time it's just too much
Maybe I'm not that tough
Maybe this time the road is just too rough
To take me home

To take me home
To take me home
To take me home
But I walk on
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long long k,x,n,m;
vector<pair<long long, pair<long long, long long> > > vec;
vector<pair<long long, pair<long long, long long> > > ok[200];
pair<long long, pair<long long, long long> > tp;
long ai,aj;

string gener(long sz,pair<long long, pair<long long, long long> > tp)
{
 string res="";
 if (tp.second.first==1)res+="C";//else res+="A";// pf
 //if (tp.first>0&&tp.second.first==1){--tp.first;res+="C";}// fst
 for (int i=1;i<=tp.first;i++)
 res+="AC";
 while (res.size()+1<sz)res+="B";
 if (res.size()<sz)if (tp.second.second==1)res+="A";else res+="B";
//cout<<sz<<" "<<res.size()<<endl;
 return res;
} 

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=100;i++)
for (int j=0;j<=100;j++)
{
 if (j*2+2<=i){ok[i].push_back(make_pair(j,make_pair(1,1)));}
 if (j*2+1<=i){ok[i].push_back(make_pair(j,make_pair(1,0)));}
 if (j*2+1<=i){ok[i].push_back(make_pair(j,make_pair(0,1)));}
 if (j*2<=i){ok[i].push_back(make_pair(j,make_pair(0,0)));}   
}

cin>>k>>x>>n>>m;

ai=aj=-1002;

for (int i=0;i<ok[n].size();i++)
 for (int j=0;j<ok[m].size();j++)
 {
  vec.clear();
  vec.push_back(ok[n][i]);
  vec.push_back(ok[m][j]);
  for (int p=2;p<k;p++)
  {
      tp.first=vec[p-2].first+vec[p-1].first;
      tp.second.first=vec[p-2].second.first;
      tp.second.second=vec[p-1].second.second;
      if (vec[p-2].second.second==1&&vec[p-1].second.first==1)
      ++tp.first;// Ii
      if (tp.first>x)tp.first=x+2;
      // dh oQ
      vec.push_back(tp);
  }
  if (vec[k-1].first==x){ai=i;aj=j;}
//  cout<<vec[k-1].first<<endl;
 }

if (ai+aj<0)cout<<"Happy new year!"<<endl;
else
{
    cout<<gener(n,ok[n][ai])<<endl;
    cout<<gener(m,ok[m][aj])<<endl;   
}

cin.get();cin.get();
return 0;}