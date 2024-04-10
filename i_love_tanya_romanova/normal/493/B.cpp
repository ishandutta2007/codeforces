/*
That's when I hit pay dirt
Sink or swim, I'm jumpin' in
Huddled masses cling together
But the herd gets thin

Self assured
With those fighting words
Your so called figure of speech
Won't be hard

I'll never lose my shirt
Someday I'll hit, pay dirt
I'd rather die of thirst

Fast moving, fast ducking fast
Running fast from the blast
I'm here to carry my weight
Murder will out the ingrates

No tampering with the soul
I'm sidestepping your phony idols
That's when I'll hit pay dirt
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long n,q,s1,s2;
vector<long long> v1,v2;
long long lst;

bool cmp(vector<long long> v1,vector<long long> v2)
{
 for (int i=0;i<v1.size();i++)
 {
  if (i==v2.size())return true;
  if (v1[i]>v2[i])return true;
  if (v1[i]<v2[i])return false;
 }
 return false;
}

int main(){
//freopen("knockout.in","r",stdin);
//freopen("knockout.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (;n;--n)
{
 cin>>q;
 if (q<0)v2.push_back(-q);
 else v1.push_back(q);
 if (q<0)lst=2;
 else lst=1;
}

s1=s2=0;
for (int i=0;i<v1.size();i++)
 s1+=v1[i];
for (int i=0;i<v2.size();i++)
 s2+=v2[i];
if (s1>s2)
 cout<<"first"<<endl;
 else if (s1<s2)
 cout<<"second"<<endl;
 else if (cmp(v1,v2)==1)
  cout<<"first"<<endl;
  else if (cmp(v2,v1)==1)
   cout<<"second"<<endl;
  else if (lst==1)
   cout<<"first"<<endl;
   else cout<<"second"<<endl;
   
cin.get();cin.get();
return 0;}