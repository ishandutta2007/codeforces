/*
Gentle storm, thundering silence
Inferior force, uncontrolled calm
Vital unlike, logic, chaos, logic

The tone of which his birth ascend
The beat that of a heart descend
Repeating in the infinite
An insight made it clear
Order stormed the surface
Where chaos set the norm
Had there always been balance?
Surely not
Therein lies the beauty

It was solid
Yet everchanging
It was different
Yet the same
So I starve myself for energy

The song around his soul will bend
The notes that in this hole will melt
Crawl out of science
A dreamland if you dare
Disorder clawed the boundaries
We're ordered to stand clear
Was it always different
Never the same?
Therein lies the beauty

It was solid
Yet everchanging
It was different
Yet the same
So I starve myself for energy

As there were no witnesses
There was nothing to be told
As nothing could be grasped
The story could unfold
Superimposed on the elements of anger
Fear, anxiety, hate, despair, remorse

So break from all that fear, hold fast
Exposed, now turn to all you lack
Let echoes be the answers
Return from all the screams
Wordless now, the last attack
So silent, it hurts to listen
Was it always solid
To never change?
Therein lies the beauty

It was solid
Yet everchanging
It was different
Yet the same
So I starve myself for energy
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

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long fst[1200000],lst[1200000],nxt[1200000][7];
long tests;
string st,st1,st2;
long temp;
long v1,v2;
long res;
long cur;

long gval(long l,long r)
{
 long res=0;
 for (int i=l;i<=r;i++)
  {
  res=res*30;
  if (cur==1)res+=st[i]-'a'+1;
  if (cur==2)res+=st1[i]-'a'+1;
  if (cur==3)res+=st2[i]-'a'+1;
  }
  
  for (int i=r+1;i<l+4;i++)
   res*=30;
   
 return res;
}

long c1,c2,bst;
set<pair<long, long> > done;
map<pair<long, long> ,long> ans;
long sz1,sz2;

long solve(long v1,long v2)
{
 if (done.find(make_pair(v1,v2))!=done.end())
  return ans[make_pair(v1,v2)];
 done.insert(make_pair(v1,v2));
 pair<long, long> tp=make_pair(v1,v2);
 
 if (fst[v1]==-1||fst[v2]==-1){ans[tp]=1e9;return 1e9;}

 bst=1e9;
 c1=fst[v1];
 c2=fst[v2];
// cout<<" "<<c1<<" "<<c2<<endl;
 while (c2<500000&&c1<500000)
 {
 // cout<<c1<<"  "<<c2<<"   "<<bst<<endl;
  while (nxt[c1][sz1]<=c2)c1=nxt[c1][sz1];
  if (c1>500000)break;
  if (c1<=c2)
  bst=min(bst,max(c2+sz2,c1+sz1)-c1);
  c2=nxt[c2][sz2];
 }
 //cout<<"%"<<endl;
 ans[tp]=bst;
 return bst;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;

for (int i=0;i<=1000000;i++)
 fst[i]=lst[i]=-1;

for (int i=0;i<=1000000;i++)
 for (int j=0;j<=5;j++)
  nxt[i][j]=1e9;
 
for (int i=0;i<st.size();i++)
{
 for (int j=i;j<i+4&&j<st.size();j++)
 {
  cur=1;
  temp=gval(i,j);
  
  if (fst[temp]==-1)
   fst[temp]=lst[temp]=i;
  else 
   {
    nxt[lst[temp]][j-i+1]=i;
    lst[temp]=i;
   }
  
//   cout<<i<<" ^^^ "<<j<<" "<<temp<<endl;
 }
}
/*
cin>>tests;

while (cin>>st)
{
 cur=1;
long pp=st.size();
 v1=gval(0,st.size()-1);
 cout<<v1<<endl;
 c1=fst[v1];
 while (c1<500000){cout<<c1<<" ";c1=nxt[c1][pp];}
}
*/
cin>>tests;
for (;tests;--tests)
{
 cin>>st1>>st2;
 cur=2;
 v1=gval(0,st1.size()-1);
 cur=3;
 v2=gval(0,st2.size()-1);
 
 if (v1==v2)// sme sngs
 {
  if (fst[v1]==-1)cout<<fst[v1]<<"\n";
  else cout<<st1.size()<<"\n";
  continue;
 }
 sz1=st1.size();
 sz2=st2.size();
 res=solve(v1,v2);
 swap(sz1,sz2);
 res=min(res,solve(v2,v1));
 if (res>1e7)res=-1;
 cout<<res<<endl;
}

cin.get();cin.get();
return 0;}