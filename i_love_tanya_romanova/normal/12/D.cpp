/*
Withered away I see it
Every day complacent
Desecrates the fabric of lies
Emptiness fills inside me
Bitterness has denied me
Faith that this world
Could every really give a shit

When I feel it
Come falling
I turn you away

I am the things that you fear
My leap of faith without a sound
Don't push my back against the wall
Yes I have strength will never fall

Withered inside
This soul has petrified
As concrete fills the skies
This life is disarray
Consequence every action
Brings violence from the passions
Loneliness the emotion
Buried inside

When I feel it
Come falling
I turn you away

I am the things that you fear
My leap of faith without a sound
Don't push my back against the wall
Yes I have strength will never fall

I feel around the falling sun
For so long I fade away..away
For years to now been holdin' on
For so long I fade away.. away

I have nothing left for nobody else
I have nothing left for nobody

Feel it
Come falling
I turn you away

I am the things that you fear
My leap of faith without a sound
Don't push my back against the wall
Yes I have strength will never fall
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,bb[600000],ii[600000],rr[600000];

vector<long> ub,ur,ui;
map<long, long> mi,mr;
long ci,cr;
vector<pair<long, pair<long, long> > > v;
long lupd;
pair<long, long> temp;
long tr,ans;

long ar1[777777],ar2[777777];

void update(pair<long, long> p)
{
 ar1[p.first]=max(p.second,ar1[p.first]);
 ar2[p.first/bsize]=max(p.second,ar2[p.first/bsize]);
}

long gett(long ps)
{
 long r=0;
 for (int i=0;i<ps/bsize;i++)
  r=max(r,ar2[i]);
  for (int i=ps/bsize*bsize;i<ps;i++)
  r=max(r,ar1[i]);
  return r;
}

int main(){
//freopen("scanner.in","r",stdin);
//freopen("scanner.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>bb[i];ub.push_back(bb[i]);}
for (int i=1;i<=n;i++)
{cin>>ii[i];ui.push_back(ii[i]);}
for (int i=1;i<=n;i++)
{cin>>rr[i];ur.push_back(rr[i]);}

sort(ub.begin(),ub.end());

++ci;++cr;
sort(ui.begin(),ui.end());reverse(ui.begin(),ui.end());
sort(ur.begin(),ur.end());//reverse(ur.begin(),ur.end());

for (int i=0;i<ui.size();i++)
{
    if (i==0||ui[i]!=ui[i-1])
    {mi[ui[i]]=ci;++ci;}
}

for (int i=0;i<ur.size();i++)
{
    if (i==0||ur[i]!=ur[i-1])
    {mr[ur[i]]=cr;++cr;//cout<<ur[i]<<" "<<mr[ur[i]]<<endl;
    }
}

for (int i=1;i<=n;i++)
{
 v.push_back(make_pair(bb[i],make_pair(mi[ii[i]],mr[rr[i]])));   
}

sort(v.begin(),v.end());
reverse(v.begin(),v.end());
lupd=0;
for (int i=0;i<v.size();i++)
{
 temp=v[i].second;
 //cout<<temp.first<<" "<<temp.second<<endl;
 
 if (i>0&&v[i].first!=v[i-1].first)
 {
  for (int j=lupd;j<i;j++)
   update(v[j].second);   
  lupd=i;
 }
 
 tr=gett(temp.first);
 if (tr>temp.second)++ans;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}