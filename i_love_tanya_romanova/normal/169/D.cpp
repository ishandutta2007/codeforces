/*
I guess this time you're really leaving
I heard your suitcase say goodbye
Well as my broken heart lies bleeding
you say true love is suicide

You say you've cried a thousand rivers
And now you're swimming for the shore
You left me drowning in my tears
And you won't save me anymore

Now I'm praying to God you'll give me one more chance, girl

I'll be there for you
These five words I swear to you
When you breathe I want to be the air for you
I'll be there for you
I'd live and I'd die for you
I'd steal the sun from the sky for you
Words can't say what love can do
I'll be there for you

I know you know we've had some good times
Now they have their own hiding place
Well I can promise you tomorrow
But I can't buy back yesterday

And Baby you know my hands are dirty
But I wanted to be your valentine
I'll be the water when you get thirsty, baby
When you get drunk, I'll be the wine

I'll be there for you
These five words I swear to you
When you breathe I want to be the air for you
I'll be there for you
I'd live and I'd die for you
Steal the sun from the sky for you
Words can't say what a love can do
I'll be there for you

And I wasn't there when you were happy
I wasn't there when you were down
I didn't mean to miss your birthday, baby
I wish I'd seen you blow those candles out

I'll be there for you
These five words I swear to you
When you breathe I want to be the air for you
I'll be there for you
I'd live and I'd die for you
Steal the sun from the sky for you
Words can't say what a love can do
I'll be there for you
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793

//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back

using namespace std;
vector <long> ans;
long long n,q,k,h,m[200000],v[200000];
pair <long, long> p;
pair <pair <long, long> ,long > pp;
vector <pair <pair <long, long> ,long > > ve;
long double l,mm,r;

int main(){
//freopen("C:/aver.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>n>>k>>h;

for (int i=1;i<=n;i++)
{
    cin>>m[i];
}

for (int i=1;i<=n;i++)
{
    cin>>v[i];
}

for (int i=1;i<=n;i++)
{p=make_pair(m[i],v[i]);
pp=make_pair(p,i);
ve.push_back(pp);
}

l=0;
r=h*k;

sort(ve.begin(),ve.end());

long iters=0;

while (iters<100)
{
      ++iters;
      q=0;
      mm=l+r;
      mm/=2;
      
      for (int i=0;i<ve.size();i++)
      {
          if (q<k)
          if (h*(q+1)<=mm*ve[i].first.second)q++;
      }
      if (q==k)r=mm; else l=mm;
}

//cout<<mm<<endl;
q=0;
mm=r;

    for (int i=0;i<ve.size();i++)
      {
          if (q<k)
          if (h*(q+1)<=mm*ve[i].first.second+1e-14){q++;ans.push_back(ve[i].second);}
      }
    
for (int i=0;i<ans.size();i++)
{if (i)cout<<" ";
 cout<<ans[i];}
 
 cout<<endl;
 

cin.get();cin.get();
return 0;}