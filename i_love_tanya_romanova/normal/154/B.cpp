/*
You fell away,
what more can I say?
The feelings evolved,
I wont let it out,
I can't replace
your screaming face
feeling the sickness inside

Why won't you die?
your blood in mine
we'll be fine
then your body will be mine

So many words,
Can't discribe my face
This feelings evolved
So soon to break out
I can't relate
To a happy state
feeling the blood run inside

Why won't you die
your blood in mine
We'll be fine,
then your body will be mine

Why is everything so fucking hard for me?
keep me down to what you think I should be
Must you tempt me and provoke the ministry
Keep on trying I'm not dying so easily
(I will not die)
Why is everything so fucking hard for me? (I will not die)
Why is everything so fucking hard for me? (I will not die)

Why wont you die?
your blood in mine
we'll be fine
then your body will be mine

Why would you die
your blood in mine
we'll be fine
then your body will be mine
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

long n,m,pr[200000];
vector<long> vec[200000];
long used[200000],active[200000],er;
string st;
long val;
long temp;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
pr[1]=1;
for (int i=2;i<=100000;i++)
 if (pr[i]==0){
  for (int j=i*2;j<=100000;j+=i)
  {
   pr[j]=1;
   vec[j].push_back(i);
  }
  vec[i].push_back(i);}

for (;m;--m)
{
 cin>>st;
 if (st=="+")
 {
  cin>>val;
  if (used[val]){cout<<"Already on"<<endl;continue;}
  er=0;
  for (int j=0;j<vec[val].size();j++)
  {
   temp=vec[val][j];
   if (active[temp])er=active[temp];
  }
  if (er){cout<<"Conflict with "<<er<<endl;}
  else
  {
   cout<<"Success"<<endl;
   for (int j=0;j<vec[val].size();j++)
   {
    temp=vec[val][j];
    active[temp]=val;
   }
   used[val]=1;
  }
 }
 else
 {
  cin>>val;
  if(used[val]==0)
  cout<<"Already off"<<endl;
  else
  {
   cout<<"Success"<<endl;
   used[val]=0;
   for (int j=0;j<vec[val].size();j++)
   {
    temp=vec[val][j];
    active[temp]=0;
   }
  }
 }
}

cin.get();cin.get();
return 0;}