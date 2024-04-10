/*
I ain't got a fever got a permanent disease 
It'll take more than a doctor to prescribe a remedy 
I got lots of money but it isn't what I need 
Gonna take more than a shot to get this poison out of me 
I got all the symptoms count 'em 1,2,3 

First you need 
That's what you get for falling in love 
Then you bleed 
You get a little but it's never enough 
On your knees 
That's what you get for falling in love 
And now this boy's addicted cause your kiss is the drug 

Your love is like bad madicine 
Bad medicine is what I need 
Shake it up, just like bad madicine 
There ain't no doctor that can 
Cure my disease 

Bad, bad medicine 
Bad, bad medicine 

I don't need no needle 
To be giving me a thrill 
And I don't need no anesthesia 
Or a nurse to bring a pill 
I got a dirty down addiction
It doesn't leave a track 
I got a jone for your affection 
Like a monkey on my back 

There ain't no paramedic 
Gonna save this heart attack 

When you need 
That's what you get for falling in love 
Then you bleed 
You get a little but it's never enough 
On your knees 
That's what you get for falling in love 
Now I'm addicted and your kiss is the drug 

Your love is like bad madicine 
Bad medicine is what I need 
Shake it up, just like bad madicine 
So let's play doctor, baby 
Cure my disease 

Bad, bad medicine 
Bad, bad medicine 

I need a respirator cause I'm running out of breath 
You're an all night generator wrapped is stockings and a dress 
When you find your medicine you take what you can get 
Cause if there's something better baby well thay haven't found it yet 

Your love is like bad madicine 
Bad medicine is what I need 
Shake it up, just like bad madicine 
There ain't no doctor that can 
Cure my disease 

Your love is like bad madicine 
Bad medicine is what I need 
Shake it up, just like bad madicine 
Your love's the potion that 
Can cure my disease 

Bad, bad medicine 
Bad, bad medicine
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