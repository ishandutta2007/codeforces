/*
Spreading your lies
And preaching like a prophet
For all those gone beyond
I'll never sacrifice my life.
I should be in fear of your judgment
But for now and ever I rise above them.
I won't hear you
Never feel you I don't bare your marks.
I should be in fear of your judgment
But for now and ever I rise above them
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st;
long cnt[100],cnt1[100],cnt2[100],c[100],s,bst,ans;
vector<long> ans1,ans2;
long ansv;
long c1[100],c2[100];

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 cnt[st[i]-48]++;
}

ansv=-1;
ans=cnt[0];
bst=ans;

for (int zeros=0;zeros<=cnt[0];zeros++)
for (int pp=0;pp<=9;pp++)
{
 for (int i=0;i<=9;i++)
  c1[i]=c2[i]=cnt[i];
 c1[0]-=zeros;
 s=zeros;
 if (c1[pp]==0||c2[10-pp]==0)continue;
 
 c1[pp]--;
 c2[10-pp]--;
 
 for (int i=0;i<=9;i++)
  s+=min(c1[i],c2[9-i]);
 s++;
 
 if (s>bst)
 {
  bst=s;
  ans=zeros;
  ansv=pp;
 }
}


for (int i=0;i<=9;i++)
 cnt1[i]=cnt2[i]=cnt[i];

for (int i=0;i<ans;i++)
{
 ans1.push_back(0);
 ans2.push_back(0);
 --cnt1[0];
 --cnt2[0];
}

if (ansv!=-1){
ans1.push_back(ansv);
--cnt1[ansv];
ans2.push_back(10-ansv);
--cnt2[10-ansv];
}

for (int i=0;i<=9;i++)
{
 for (int j=0;j<min(cnt1[i],cnt2[9-i]);j++)
 {
  ans1.push_back(i);
  ans2.push_back(9-i);
 }
 long q=min(cnt1[i],cnt2[9-i]);
 for (int j=0;j<q;j++)
  --cnt1[i],
  --cnt2[9-i];
  
}

for (int i=0;i<=9;i++)
 for (int j=0;j<cnt1[i];j++)
  ans1.push_back(i);

for (int i=0;i<=9;i++)
 for (int j=0;j<cnt2[i];j++)
  ans2.push_back(i);

reverse(ans1.begin(),ans1.end());
reverse(ans2.begin(),ans2.end());
for (int i=0;i<ans1.size();i++)
 cout<<ans1[i];
cout<<endl;
for (int i=0;i<ans2.size();i++)
 cout<<ans2[i];
 cout<<endl;
 
cin.get();cin.get();
return 0;}