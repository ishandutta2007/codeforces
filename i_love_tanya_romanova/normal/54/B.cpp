/*
How many tears do we have to cry
For all our broken dreams?
And all those silhouettes crossing our life
How could we think that we should last?

And we're all lost in the infinity

I thought I held my life in my hands
And I never cared about a better day
We are ephemeral sights in a flame
Our chance is to live day by day

And we're all lost in the infinity
And we're all a drop in eternity

Time after time, we must face our pain
Shall it last forever?
I'll cry and I'll fight in this endless game
'Cause I dance with destiny

Thinking about your past
You realize that nothing has changed
A restless soul who saw their first day
Will have to strive to their last one

And we're all lost in the infinity
And we're all a drop in eternity

Time after time, we must face our pain
Shall it last forever?
I'll cry and I'll fight in this endless game
'Cause I dance with destiny
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

set<long long> sett;
long n,m;
string st[100];
long long val;
long long pw1[200000],pw2[200000];

vector<pair<long, pair<long, long> > >ans;

long long get(long x1,long y1,long x2,long y2)
{
 long long bst=0;
 long long s=0;
 
 // normal
 for (int i=x1;i<x2;i++)
  for (int j=y1;j<y2;j++)
  {
   s=s+st[i][j]*pw1[i-x1]*pw2[j-y1];
  }
 bst=s;

 s=0;
 for (int i=y2-1;i>=y1;i--)
  for (int j=x1;j<x2;j++)
  {
   s=s+st[j][i]*pw1[y2-i-1]*pw2[j-x1];
  }
 bst=min(bst,s);
// cout<<s<<endl;
 s=0;
 for (int i=x2-1;i>=x1;--i)
  for (int j=y2-1;j>=y1;j--)
  {
   s=s+st[i][j]*pw1[x2-i-1]*pw2[y2-j-1];
  }
//  cout<<s<<endl;
 bst=min(bst,s);
 s=0;
 for (int i=y1;i<y2;i++)
  for (int j=x2-1;j>=x1;j--)
  {
   s=s+st[j][i]*pw1[i-y1]*pw2[x2-j-1];
  }
 bst=min(bst,s);
 return bst;
}

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=0;i<n;i++)
{
 cin>>st[i];
}

pw1[0]=pw2[0]=1;
for (int i=1;i<=10000;i++)
{
 pw1[i]=pw1[i-1]*173;
 pw2[i]=pw2[i-1]*137;
}

for (int a=1;a<=n;a++)
 for (int b=1;b<=m;b++)
 {
  sett.clear();
  if (n%a)continue;
  if (m%b)continue;
  for (int start1=0;start1<n;start1+=a)
   for (int start2=0;start2<m;start2+=b)
   {
    val=get(start1,start2,start1+a,start2+b);
 // cout<<val<<endl;
    sett.insert(val);
   }
//   cout<<sett.size()<<endl;
   if (sett.size()!=(n/a)*(m/b))continue;
   ans.push_back(make_pair(a*b,make_pair(a,b)));
 }

/*for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
}
*/
cout<<ans.size()<<endl;
sort(ans.begin(),ans.end());
cout<<ans[0].second.first<<" "<<ans[0].second.second<<endl;

cin.get();cin.get();
return 0;}