/*
I can't remember anything
Can't tell if this is true or dream
Deep down inside I feel to scream
This terrible silence stops me

Now that the war is through with me
I'm waking up, I cannot see
That there is not much left of me
Nothing is real but pain now

Hold my breath as I wish for death
Oh please God, wake me

Back in the womb it's much too real
In pumps life that I must feel
But can't look forward to reveal
Look to the time when I'll live

Fed through the tube that sticks in me
Just like a wartime novelty
Tied to machines that make me be
Cut this life off from me

Hold my breath as I wish for death
Oh please God, wake me

Now the world is gone, I'm just one
Oh God help me
Hold my breath as I wish for death
Oh please God, help me

Darkness imprisoning me
All that I see
Absolute horror
I cannot live
I cannot die
Trapped in myself
Body my holding cell

Landmine has taken my sight
Taken my speech
Taken my hearing
Taken my arms
Taken my legs
Taken my soul
Left me with life in hell
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
 
 long n,q;
 vector<long> v,v1;
 long ans;
 vector<long> v0;
 
 void solve(vector<long> v0,vector<long> v1,long ps)
 {
  if (v0.size()+v1.size()>ps+2)return;
  sort(v0.begin(),v0.end());
  sort(v1.begin(),v1.end());
  /*for (int i=0;i<v0.size();i++)
  cout<<v0[i]<<" ";
  cout<<endl;
  for (int i=0;i<v1.size();i++)
  cout<<v1[i]<<" ";
  cout<<endl;
  cout<<"%"<<ps<<endl;
  */
   if (ans)return;
  if (ps==-1)
  {
   if (v0.size()+v1.size()==0)ans=1;
   return;
  }
  
  vector<long> vn0,vn1;
  
  for (int i=0;i<v0.size();i++)
   if (v0[i]>v[ps]&&(i==0||v0[i]!=v0[i-1]))
   {
    vn0=v0;vn1=v1;
    vn0.erase(vn0.begin()+i);
    vn1.push_back(v0[i]-v[ps]);
    if (v[ps]>1)vn0.push_back(v[ps]-1);
    solve(vn0,vn1,ps-1);
   }
  for (int i=0;i<v1.size();i++)
   if (v1[i]>=v[ps]&&(i==0||v1[i]!=v1[i-1]))
   {
    vn0=v0;vn1=v1;
    vn1.erase(vn1.begin()+i);
    if (v1[i]>v[ps])vn1.push_back(v1[i]-v[ps]);
    if (v[ps]>1)vn0.push_back(v[ps]-1);
    solve(vn0,vn1,ps-1);
   }
 }
 
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>q;
 v.push_back(q);
}
sort(v.begin(),v.end());
long calc=0;
for (int i=0;i<v.size();i++)
 if (v[i]==1)++calc;
 if (calc*2>=n-4){
 if (v[n-1]>1)
v0.push_back(v[n-1]-1);
v.pop_back();
solve(v0,v1,n-2);
}
if (ans)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}