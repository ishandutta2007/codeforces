/*
Sell your soul for a dime, they promise you a paradise.
They try to control what you think!

They want to own your individuality!
They just want only one number more!

They try to tie you in their beliefs!
Your gates of Eden will turn into barbed wire.

You live enslaved by thy Christ,
and will never know life at all!
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long tests,x[10],y[10],ans,dx[10],dy[10];

bool nice(vector<pair<long, long> > v)
{
     long dx1,dx2,dy1,dy2,dx3,dy3;
     
 dx1=v[1].first-v[0].first;
 dx2=v[2].first-v[0].first;
 dx3=v[3].first-v[0].first;
 dy1=v[1].second-v[0].second;
 dy2=v[2].second-v[0].second;
 dy3=v[3].second-v[0].second;
 long long l1,l2;
 l1=dx1*dx1+dy1*dy1;
 l2=dx2*dx2+dy2*dy2;
 if (l1!=l2)return false;
 if (dx3!=dx2+dx1)return false;
 if (dy3!=dy2+dy1)return false;
 if (dx1==0&&dy1==0)return false;
 if (dx1*dx2+dy1*dy2!=0)return false;
 return true;
}

bool square()
{
 vector<pair<long, long> > v;
 
 for (int i=0;i<4;i++)
 {
  v.push_back(make_pair(x[i],y[i]));
 }
 sort(v.begin(),v.end());
 do
 {
                         if (nice(v))return true;
 }while (next_permutation(v.begin(),v.end()));
 return false;
}

void rotate(long id)
{
     long tx,ty;
 tx=x[id]-dx[id];
 ty=y[id]-dy[id];
 x[id]=dx[id]-ty;
 y[id]=dy[id]+tx;
}

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
 ans=1e9;
 for (int i=0;i<4;i++)
  cin>>x[i]>>y[i]>>dx[i]>>dy[i];
 
 for (long i=0;i<4;i++)
  {
   for (int j=0;j<4;j++){
    for (int q=0;q<4;q++){
     for (int w=0;w<4;w++)
    {
      if (square())ans=min(ans,i+j+q+w);
     rotate(3);
    }rotate(2);}rotate(1);}
    rotate(0);
 }
 if (ans>1e7)cout<<-1<<endl;
 else cout<<ans<<endl;
}
cin.get();cin.get();
return 0;}