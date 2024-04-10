/*
Sitting by the window
Staring out into the night
Waiting up for the light of day
And the sound of silence
The faintly flaring candle light
Parting has got me
Around to go insane

Alone I try to while away my time
Seconds turn to ages
As I close my eyes and wait
Sometimes I wonder
What's the reason why
We long for someone to embrace
And say hello to say goodbye

Carry on - and I will forever
Longing drives bad memories away
And still I carry on and I will forever
Cause when I see you smile
I dare to believe again

Is there anybody out there
To keep on looking for
If you don't know then lie to me
Blue eyed for a letdown
If this is what it takes
To maybe see the light
I'll dare to shed another tear

Oh I Know
The wind blows cold tonight
But anyhow I gotta go
Tell me girl where are you now

Carry on and I will forever...

I tried to build a wall
And let nobody in
To be on my own
Without love and without pain
Without pain
I don't know why
But every time
I look into your face
Into your face
I am caught and I relapse again

Carry on, it's forever
Longing drives and memories away

Carry on and I will forever...
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

set<long long> evs;
long long t,m,l,r,k,ans;
set<long long>::iterator it;
long long sp;

vector<vector<long long> > mult(vector<vector<long long> > v1,vector<vector<long long> > v2)
{
 vector<vector<long long> >res;
 res=v1;
 for (int i=0;i<2;i++)
  for (int j=0;j<2;j++)
   res[i][j]=0;
 for (int k=0;k<2;k++)
  for (int i=0;i<2;i++)
   for (int j=0;j<2;j++)
    res[i][j]+=v1[i][k]*v2[k][j];
 for (int i=0;i<2;i++)
  for (int j=0;j<2;j++)
   res[i][j]%=m;
   return res;
}

vector<vector<long long> > one()
{
 vector<vector<long long> >v;
 v.resize(2);
 v[0].resize(2);v[1].resize(2);
 for (int i=0;i<2;i++)
  for (int j=0;j<2;j++)
   v[i][j]=(i==j);
  return v;
}

vector<vector<long long> > pw(vector<vector<long long> > v,long long pwr)
{
 if (pwr==0)return one();
 if (pwr%2)return mult(v,pw(v,pwr-1));
 return pw(mult(v,v),pwr/2);
}

void solve(long long t)
{
 long long q=t;
 if (q==0)return;
 sp=l/q+(l%q>0);
 sp=-sp+r/q;
 sp++;
 if (sp>=k)
 ans=max(ans,q);
}
int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>l>>r>>k;
for (long long i=1;i*i<=l;i++)
{
 solve(i);
 t=l/i;
 solve(t);
solve(t-1);
 solve(t+1);
}
for (long long i=1;i*i<=r;i++)
{
 t=r/i;
// evs.insert(i);
 solve(i);solve(t);solve(t-1);solve(t+1);
}

for (it=evs.begin();it!=evs.end();it++)
{
 long long q=(*it);
 if (q==0)continue;
 sp=l/q+(l%q>0);
 sp=-sp+r/q;
 sp++;
 if (sp>=k)
 ans=max(ans,q);
}
//cout<<ans<<endl;
vector<vector<long long> > p=one();
p[1][0]=p[0][1]=1;
p[1][1]=0;
p=pw(p,ans);
/*for (int i=0;i<2;i++)
 for (int j=0;j<2;j++)
  cout<<p[i][j]<<" ";
  cout<<endl;
*/
cout<<p[0][1]<<endl;

cin.get();cin.get();
return 0;}