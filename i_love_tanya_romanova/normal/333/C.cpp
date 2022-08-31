/*
Flaunt your will at every wheel,
Parachute your chocolate soul,
Cobblestones under your wheels,
I got pictures on my mind,
I got pictures on my mind,
I got pictures on my mind,
I got pictures on my mind.

Circumvent your thick ego,
Wooden farts, they're on the go,
You can't tell me that I'm real,
I got pictures on my mind,
I got pictures on my mind,
I got pictures on my mind,
I got pictures on my mind.

Fear waits, for us,
When the present can't be sealed,
Away, gold dust,
Now the dishes can be cleared.
Fear waits, for us,
Till the moment is revealed,
Then turns to rust
For the mighty conquered meal.

Can't you lookat my shaved ass,
Ounce is gone, and God is once,
You can't see me suddenly,
I got pictures on my mind,
I got pictures on my mind,
I got pictures on my mind,
I got pictures on my mind.

I got pictures on my mind.
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

vector<long> v1;
vector<long> temp,temp1;
string tstring;
vector<string> good[11000];
vector<long> digs;
long q,num;

string vts(vector<long> v)
{
 string r="";
 for (int i=0;i<v.size();i++)
 r+=" ";
 for (int i=0;i<v.size();i++)
 r[i]=v[i]+48;
 return r;
}

long gval(long l,long r)
{
 long rr=0;
 for (int i=l;i<=r;i++)
 rr=rr*10+digs[i];
 return rr;
}

vector<long> solve(long l,long r)
{
 vector<long> res;
 res.push_back(gval(l,r));
 
 for (int cp=l;cp<r;cp++)
 {
     vector<long> lv,rv;
     lv=solve(l,cp);rv=solve(cp+1,r);
     for (int i=0;i<lv.size();i++)
     for (int j=0;j<rv.size();j++)
     {
         res.push_back(lv[i]+rv[j]);
         res.push_back(lv[i]-rv[j]);
         res.push_back(lv[i]*rv[j]);
     }
 }
 vector<long> res1;
 sort(res.begin(),res.end());
 for (int i=0;i<res.size();i++)
 if (i==0||res[i]!=res[i-1])
 res1.push_back(res[i]);
 return res;
}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=0;i<=9999;i++)
{
    long q=i;v1.clear();
    
    for (int j=0;j<4;j++)
    {
        v1.push_back(q%10);q/=10;
    }
    
    reverse(v1.begin(),v1.end());
    digs=v1;
//    cout<<"%"<<i<<endl;
    temp=solve(0,3);
    tstring=vts(v1);
    sort(temp.begin(),temp.end());
    temp1.clear();
    
    for (int j=0;j<temp.size();j++)
     if (j==0||temp[j]!=temp[j-1])
      temp1.push_back(temp[j]);
   
    for (int j=0;j<temp1.size();j++)
    {
     if (temp1[j]>=0)
     good[temp1[j]].push_back(tstring);
    }  
}

cin>>q>>num;
long usd=0;
long sdg;

for (int fdg=0;fdg<=9999;fdg++)
{
  sdg=abs(fdg-q);
  for (int j=0;j<good[fdg].size();j++)
  for (int q=0;q<good[sdg].size();q++)
  {if (usd>=num)break;
   cout<<good[fdg][j]<<good[sdg][q]<<endl;
   ++usd;
  }
}
cin.get();cin.get();
return 0;}