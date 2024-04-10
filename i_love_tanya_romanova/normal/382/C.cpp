/*
A last embrace, last words to say
Before the war took their fate away
Before to kill became his forced task
And bleeding fields were covered with sins
His wounded heart is crying out for home

Away away my love to where all darkness will be gone
Away away to our land
Where you will be forever in my arms again

Days of dust, of cruelty and death
Broke his soul until there was nothing left
Only her love that carried him through all

Away away my love to where all darkness will be gone
Away away to our land
Where you will be forever in my arms again

He passed high mountains and rough rivers
He wrote a 1000 letters to be near
He walked a 1000 miles
Just to see her smile again
Just for returning home

Away away my love to where all darkness will be gone
Away away to our land
Where you will be forever in my arms again

Tell the wind I'll survive just to feel you again
I will fight 'till the end to lay my promised love
Forever in your hands
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
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,q;
vector<long> v;
long t,span;
set<long> ans;
vector<long> dif;
vector<long> taa;
long tt;
set<long>::iterator it;
vector<long> udif;
long temp;
void addans(long x)
{
 ans.insert(x);
}
void showw()
{
 cout<<ans.size()<<endl;
 for (it=ans.begin();it!=ans.end();++it)
 {
 if (it!=ans.begin())cout<<" ";
 cout<<(*it);
 }
 cout<<endl;
}

void solve()
{
 if (v.size()==1){cout<<-1<<endl;return;}// ea+
 if (v.size()==2)
 {
  span=v[1]-v[0];
  tt=span/2;
  if (tt*2==span)// -+t
  {addans(v[0]+tt);}
   addans(v[0]-span);addans(v[1]+span);
   showw();
  return;
 }
 
 for (int i=1;i<v.size();i++)
 {
  dif.push_back(v[i]-v[i-1]);
 }
 sort(dif.begin(),dif.end());
 for (int i=0;i<dif.size();i++)
 if (i==0||dif[i]!=dif[i-1])udif.push_back(dif[i]);
 
 if (udif.size()==1)// nce
 {
  addans(v[0]-udif[0]);
  addans(v[v.size()-1]+udif[0]);
 }
 
 if (udif.size()==2)// qp+|
 {
  temp=udif[0]*2;
  if (temp==udif[1])
  {
   for (int i=1;i<v.size();i++)
   if (v[i]-v[i-1]==temp)taa.push_back(v[i-1]+udif[0]);
   if (taa.size()==1)
   addans(taa[0]);
  }
 }
 showw();
}
int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>q;
 v.push_back(q);
}

sort(v.begin(),v.end());
solve();

cin.get();cin.get();
return 0;}