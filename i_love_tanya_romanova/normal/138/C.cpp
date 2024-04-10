/*
The times we had shared the same ideals
The times we had been holding hands
Now come to an end
Now my hands are crushing your neck.
So quick to wash away everything we've built
Now my memories fade to black
Just like your face within' my grasp
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

long n,m,a[1<<19],b[1<<19],h[1<<19],l[1<<19],r[1<<19];
vector<pair<long, pair<long, long> > > v;
long z[1<<19];
long sure;
double ans;
double pal;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

//cout<<log(2.0)<<endl;

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>a[i]>>h[i]>>l[i]>>r[i];
 if (l[i]>0)
  v.push_back(make_pair(a[i]-h[i],make_pair(-1000000,l[i]))),
  v.push_back(make_pair(a[i],make_pair(-1000000,-l[i])));
 if (r[i]>0)
  v.push_back(make_pair(a[i],make_pair(1000000,r[i]))),
  v.push_back(make_pair(a[i]+h[i],make_pair(1000000,-r[i])));
}

for (int i=1;i<=m;i++)
{
 cin>>b[i]>>z[i];
 v.push_back(make_pair(b[i],make_pair(i,i)));
}

sort(v.begin(),v.end());

pal=0;
for (int i=0;i<v.size();i++)
{
 if(abs(v[i].second.first)<100000)
 {
  if (sure>0)continue;
  ans+=exp(pal)*z[v[i].second.second];
  continue;
 }
 if (v[i].second.second>0) // add
 {
  if (v[i].second.second==100){++sure;continue;}
  pal+=log(1.0-v[i].second.second*0.01);
 }
 if (v[i].second.second<0)// delete
 {
  if(v[i].second.second==-100){--sure;continue;}
  pal-=log(1.0+v[i].second.second*0.01);
 }
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}