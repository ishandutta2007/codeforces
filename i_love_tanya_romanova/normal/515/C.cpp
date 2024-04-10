/*
Mention this to me
Mention this to me

Watch the weather change
Watch the weather change
Watch the weather change
Watch the weather change

Mention this to me
Mention something
Mention anything
Mention this to me

Watch the weather change
Watch the weather change
Watch the weather change
Watch the weather change

Watch the weather change
Watch the weather change

Mention this to me
And mention something
Mention anything
Mention this to me

Watch the weather
Watch the weather change
Watch the weather change
Watch the weather
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
#define MAG 10000

using namespace std;

string st;
long n,q,tq,p,deg[1<<10];
vector<long> ans;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;

for (int i=0;i<st.size();i++)
{
 q=st[i]-48;
 for(int p=2;p<=q;p++)
 {
  tq=p;
 for (int j=2;j<=9;j++)
 {
  while (tq%j==0)
  {
   deg[j]++;
   tq/=j;
  }
 }
 }
}

for (int i=9;i>1;i--)
{
 while (deg[i]>0)
 {
  ans.push_back(i);
  for (int j=2;j<=i;j++)
  {
   tq=j;
   for (int p=2;p<=9;p++)
   {
    while (tq%p==0)
    {
     deg[p]--;
     tq/=p;
    }
   }
  }
 }
}

for (int i=0;i<ans.size();i++)
{
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}