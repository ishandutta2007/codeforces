/*
Arms have stretched
Beyond their reach
Craving for a false perfection
Safe
Under self-deception's wing
Craving for a false protection

Illusion is solace
Reflection is pain

Nothing loved - nothing lost
Nothing tried - nothing lost

I called on despair to guide me
Summoned the cold again
I bit from the grapes
Of seduction
Because reflection is pain

This is my wasteland
Empire without a king
Where resignation rules
Slaying the wolf within

Nothing loved - nothing lost
Nothing tried - nothing lost

Illusion is knowledge!
Rest in peace!
Illusion is solace!
Rest in peace!

I called on despair to guide me
Summoned the cold again
I bit from the grapes
Of seduction
Because reflection is pain!

This is my wasteland
Empire without a king
Where resignation rules
Slaying the wolf within

I would rather sense
Nothing at all
Than sense
What is true
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st1,st2;
long dp[1050][1050];
long par[1050][1050];
long n,m;
vector<pair<long, long> > ans;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1>>st2;
for (int i=0;i<=st1.size();i++)
 for (int j=0;j<=st2.size();j++)
 {
  dp[i][j]=1e9;
 }

n=st1.size();
m=st2.size();
//cout<<n<<" "<<m<<endl;

dp[0][0]=0;
for (int j=0;j<=st2.size();j++)
{
 for (int i=0;i<=st1.size();i++)
 {
  if (j>0&&dp[i][j-1]+1<dp[i][j])// insert
  {
   dp[i][j]=dp[i][j-1]+1;
   par[i][j]=1;
  }
  if (i>0&&dp[i-1][j]+1<dp[i][j])// delete
  {
   dp[i][j]=dp[i-1][j]+1;
   par[i][j]=2;
  }
  if (i>0&&j>0)
  {
   long tc=(st1[i-1]!=st2[j-1]);
   if (dp[i][j]>dp[i-1][j-1]+tc)
   {
    dp[i][j]=dp[i-1][j-1]+tc;
    par[i][j]=3;
   }
  }
 }
}

cout<<dp[n][m]<<endl;

while (n>0||m>0)
{
 if (par[n][m]==1)
 {
  ans.push_back(make_pair(1,m));
  --m;
 }
 if (par[n][m]==2)
 {
  ans.push_back(make_pair(2,m));
  --n;
 }
 if (par[n][m]==3)
 {
  if (st1[n-1]!=st2[m-1])
  {
   ans.push_back(make_pair(3,m));
  }
  --n;
  --m;
 }
}

reverse(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
{
 if (ans[i].first==3){cout<<"REPLACE "<<ans[i].second<<" "<<st2[ans[i].second-1]<<endl;
 //st1[ans[i].second-1]=st2[ans[i].second-1];
 }
 if (ans[i].first==2){cout<<"DELETE "<<ans[i].second+1<<endl;}//st1.erase(st1.begin()+ans[i].second);}
 if (ans[i].first==1){cout<<"INSERT "<<ans[i].second<<" "<<st2[ans[i].second-1]<<endl;//st1.insert(st1.begin()+ans[i].second-1,st2[ans[i].second-1]);
 }
}
/*cout<<st1<<endl;
cout<<st2<<endl;*/
cin.get();cin.get();
return 0;}