/*
A soldier's heart
Reflecting back at me
I keep seeing mutilated faces
Even in my dreams

Distorted images
Flashing rapidly
Psychotically abusing me
Devouring my brain

The eyes of the insane
On a demented campaign

Tortured spirits
Will not let me rest
These thoughts of mutilated faces
Completely possessed

Fragmented images
Flashing rapidly
Psychotically abusing me
Worming through my head

Shell shock, battle fatigue
Overwhelming anxiety
Flashbacks, panic attacks
Death raising it's ugly face at me

Go to make it stop
Can't take it anymore
The dead keep haunting me
They just keep coming back for more

The eyes of the insane
On a demented campaign
Flashbacks, panic attacks
Death raising his ugly face at me

Got to make it stop
Can't take it anymore
Death's face keeps haunting me
It just keeps coming back for more

Got to make it stop
Can't take it anymore
Death's face keeps haunting me
It just keeps coming back for more

A soldier
Of misfortune
I owe my pain and suffering
To this hell

These demons
Ripping through my soul
Evil's relentless hostility
Won't let me sleep

Shell shock, battle fatigue
Devastating insanity
Flashback, panic attacks
Death's riding, he's coming for me
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
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n;
string st;
long tp[200000],c[20000],used[20000];
vector<long> ans;
long h;
long ost;
vector<long> answ;

vector<long> pw(vector<long> a,long x)
{
 vector<long> r;
 r=a;
 for (int i=1;i<=x;i++)
 {
  ost=0;
  for (int j=0;j<r.size();j++) 
  {r[j]=r[j]*2+ost;ost=r[j]/10;r[j]%=10;}
  if (ost>0)r.push_back(ost);
 }
 return r;
}

vector<long> ad(vector<long> a,vector<long> b)
{
 if (a.size()<b.size())swap(a,b);
 ost=0;
 for (int i=0;i<a.size();i++)
 {
  a[i]+=ost;
  if (i<b.size())a[i]+=b[i];
  ost=a[i]/10;
  a[i]%=10;
 }
 if (ost)a.push_back(ost);
 return a;
}

vector<long> pww;
long lst;

void showw(vector<long> v)
{
 for (int i=v.size()-1;i+1;--i)
 cout<<v[i];
 cout<<endl;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>st;
 if (st=="win")tp[i]=1;else tp[i]=2;
 cin>>c[i];
}

for (int deg=5000;deg>=0;--deg)
{
 h=0;
 for (int i=1;i<=n;i++)
 {
  if (tp[i]==1&&c[i]==deg)h=i;
  if (used[i]==1)h=0;
  if (tp[i]==2&&c[i]==deg)
  {
   if (h==0)continue;
   ans.push_back(deg);
   for (int j=h;j<=i;j++)
    used[j]=1;
  }
 }
}

answ.push_back(0);

sort(ans.begin(),ans.end());
pww.push_back(1);
lst=0;

for (int i=0;i<ans.size();i++)
{
    
    answ=ad(answ,pw(pww,ans[i]-lst));
    pww=pw(pww,ans[i]-lst);
    lst=ans[i];
// cout<<ans[i]<<" ";   
}//cout<<endl;

showw(answ);

cin.get();cin.get();
return 0;}