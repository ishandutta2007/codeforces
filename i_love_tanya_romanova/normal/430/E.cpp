/*
Maybe one day I'll be an honest man
Up till now I'm doin' the I best I can, yeah
Long roads, long days of sunrise to sunset
Of sunrise to sunset

You dream on brother while you can
And you dream on sister, I hope you find the one, yeah
All of our lives, covered up quickly
By the tides of time

Spend your days full of emptiness
Spend your years full of loneliness
Wasting love in a desperate caress
Rolling shadows of nights

You dream on brother while you can
You dream on sister, I hope you find the one, yeah
All of our lives, covered up quickly
By the tides of time

Sands are flowing
The lines are in your hand
In your eyes, I see the hunger
And the desperate cry that tears the night

Spend your days full of emptiness
You spend your years full of loneliness
Wasting love in a desperate caress
Rolling shadows of nights

Oh, spend your days full of emptiness
Spend your years full of loneliness
Wasting love in a desperate caress
Rolling shadows of nights

Spend your days full of emptiness
Spend your years full of loneliness
Wasting love in a desperate caress
Rolling shadows of nights
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