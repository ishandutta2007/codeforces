/*
I watch the sky and it's turning to grey
My emotions are like a storm deep inside me
I don't want to feel, but it's so fucking real
This shit is back again and it's killing me

I want to tell you, but I can not explain
In my words selfish, uncontrollable rage
I feel the fear, I feel the hate
And I feel I am going insane

Look at me, I hit the bottom
I'm out of my mind, I lose the control
Give me something, the pain is killing me
You are my shelter, you are my shelter

I'm going through changes, I don't understand
It came from nothing and now I feel it everywhere
I'm in secure, im going down
I feel so lonely in this deep and dark hole

Give me your hand, I need your help
Even if I hurt you, please try to forgive me
Now I'm not myself, now I'm someone else
Show me the way, I want to come back

Look at me, I hit the bottom
I'm out of my mind, I lose control
Give me something, the pain is killing me
You are my shelter, you are my shelter
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

long n,m,a,b;
vector<pair<long, long> > v;
long clev,plev,cl[200000],cr[200000],pl[200000],pr[200000];

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 v.push_back(make_pair(a,b));
}
sort(v.begin(),v.end());

clev=0;
plev=1;
pl[0]=pr[0]=1;

long i=0;

while (true)
{
// cout<<"$"<<i<<" "<<clev<<" "<<plev<<endl;
 //cout<<pl[0]<<" "<<pr[0]<<endl;
 
 if (i==m)break;
 clev=0;
 
 if ((i==0&&v[i].first>1)||(i>0&&v[i].first!=v[i-1].first+1))
 plev=1,pr[0]=n;
 //cout<<pl[0]<<" "<<pr[0]<<endl;
 
 long r=i;
 while (r<m&&v[r].first==v[i].first)++r;
 --r;
 long lp=1;
// cout<<r<<endl;
 // cur lev  segm
 for (int k=i;k<=r;k++)
 {
  if (v[k].second>lp)
  {
   cl[clev]=lp;cr[clev]=v[k].second-1;++clev;
  }
  lp=v[k].second+1;
 }
 
 //cout<<"$"<<cl[0]<<" "<<cr[0]<<endl;
 
 if (lp<=n)
 {
  cl[clev]=lp;cr[clev]=n;++clev;
 }
 
 // intr prev
 lp=0;
 for (int k=0;k<clev;k++)
 {
  while (lp<plev&&pr[lp]<cl[k])
  ++lp;
  if (lp==plev||pl[lp]>cr[k])
  cr[k]=cl[k]=2e9+5;
  else cl[k]=max(cl[k],pl[lp]);
 }
 
 plev=0;
 for (int k=0;k<clev;k++)
 {
  if (cl[k]<2e9){pl[plev]=cl[k];pr[plev]=cr[k];++plev;}
 }
 
 if (plev==0)
 {
  cout<<-1<<endl;
//  cin.get();cin.get();
  return 0;
 }
 i=r+1;
// cout<<pl[0]<<" "<<pr[0]<<" "<<plev<<endl;
}

/*for (int i=0;i<plev;i++)
cout<<pl[i]<<" "<<pr[i]<<"#";
cout<<endl;
*/

if (v[m-1].first!=n)
{
 plev=1;pr[0]=n;
}
if (pr[plev-1]==n)
cout<<2*n-2<<endl;
 else cout<<-1<<endl;
 
cin.get();cin.get();
return 0;}