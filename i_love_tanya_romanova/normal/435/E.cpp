/*
By the way
The more I think about this sad story
The more I feel deceived
Couldn't I have been betrayed after all?
Anyway
I understand that things have changed in your life
Should I feel guilty about that?
No I won't come maskless
Anymore...
All this ime
I did my best to protect my integrity
But it's a lost cause now
My will to belieave in humanity
Simply sank and faded away
The vanishing pride of a mortal man
Everyday
Since this evening of torment
This bloody argument
I felt so guilty
And evil
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

long n,m;
string st;
long ar[1200][1200],hi[1200][5][4],hj[1200][5][4];
vector<long> v[3];
long er,a,b;pair<long,long> ans;
long hmask1,hmask2,tmask1,tmask2;
long sett[50];

long cbits(long x)
{
 long r=0;
 for (int i=0;i<4;i++)
  if (x&(1<<i))r++;
 return r;
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
 {
  cin>>st;
  for (int j=1;j<=m;j++)
  {
   ar[i][j]=st[j-1]-48;
   hi[i][ar[i][j]][j%2]=1;
   hj[j][ar[i][j]][i%2]=1;
  }
 }

ans=make_pair(-1,-1);

for (int mask=0;mask<16;mask++)
 if (cbits(mask)==2)
 {
  v[0].clear();v[1].clear();
  for (int i=0;i<4;i++)
   if (mask&(1<<i))v[0].push_back(i);
   else v[1].push_back(i);
   er=0;
   for (int i=1;i<=n;i++)
   {
    a=v[i%2][0];
    b=v[i%2][1];
    tmask1=(1<<a);
    tmask2=(1<<b);
    hmask1=0;
    hmask2=0;
    for (int q=0;q<4;q++)
    {if (hi[i][q+1][0])hmask1|=(1<<q);
    if (hi[i][q+1][1])hmask2|=(1<<q);
    }
    
    if (((hmask1|tmask1)!=tmask1)||((hmask2|tmask2)!=tmask2))
    if (((hmask2|tmask1)!=tmask1)||((hmask1|tmask2)!=tmask2))
      er=1;
   }
  if (er==0)ans=make_pair(mask,0);
 }
 
 for (int mask=0;mask<16;mask++)
 if (cbits(mask)==2)
 {
  v[0].clear();v[1].clear();
  for (int i=0;i<4;i++)
   if (mask&(1<<i))v[0].push_back(i);
   else v[1].push_back(i);
   er=0;
   for (int i=1;i<=m;i++)
   {
    a=v[i%2][0];
    b=v[i%2][1];
     tmask1=(1<<a);
    tmask2=(1<<b);
    hmask1=0;
    hmask2=0;
    for (int q=0;q<4;q++){
    if (hj[i][q+1][0])hmask1|=(1<<q);
    if (hj[i][q+1][1])hmask2|=(1<<q);}
    
    if (((hmask1|tmask1)!=tmask1)||((hmask2|tmask2)!=tmask2))
    if (((hmask2|tmask1)!=tmask1)||((hmask1|tmask2)!=tmask2))
      er=1;
   }
  if (er==0)ans=make_pair(mask,1);
 }
 
// cout<<ans.first<<" "<<ans.second<<endl;
 
long mask=ans.first;

  v[0].clear();v[1].clear();
  for (int i=0;i<4;i++)
   if (mask&(1<<i))v[0].push_back(i+1);
   else v[1].push_back(i+1);

if (ans.second==-1)// nway
{
 cout<<0<<endl;
 return 0;
}
 
  v[0].clear();v[1].clear();
  for (int i=0;i<4;i++)
   if (mask&(1<<i))v[0].push_back(i);
   else v[1].push_back(i);
   er=0;
   
   //cout<<ans.first<<" "<<ans.second<<endl;
   
   for (int i=1;i<=(ans.second==1?m:n);i++)
   {
    a=v[i%2][0];
    b=v[i%2][1];
    tmask1=(1<<a);
    tmask2=(1<<b);
    hmask1=0;
    hmask2=0;
    for (int q=0;q<4;q++){
    if (ans.second==1?hj[i][q+1][0]:hi[i][q+1][0])hmask1|=(1<<q);
    if (ans.second==1?hj[i][q+1][1]:hi[i][q+1][1])hmask2|=(1<<q);}
   /* cout<<hmask1<<"   "<<hmask2<<endl;
    cout<<tmask1<<" ^ "<<tmask2<<endl;
   */ if (((hmask1|tmask1)!=tmask1)||((hmask2|tmask2)!=tmask2))
    swap(a,b);
    sett[0]=a+1;
    sett[1]=b+1;
    for (int j=1;j<=(ans.second==1?n:m);j++)
    {
     if (ans.second)ar[j][i]=sett[j%2];
     else ar[i][j]=sett[j%2];
    }
   }
 
 for (int i=1;i<=n;i++)
 {
  for (int j=1;j<=m;j++)
   cout<<ar[i][j];
   cout<<endl;
 }
 
cin.get();cin.get();
return 0;}