/*
Sunsets and butterflies don't exist in my world
Just trying to find something that to give me comfort as I hurt
This sadness and loneliness is like my siamese twins
But I'll never ever let... all this emptiness win
Till my last breath!

Till my last breath I'll be fighting mad
And you better believe I'll give it everything that I have
Till my last breath I'll refuse to retreat, and I ain't gonna be
Beat
No, no, no, no, no
Until my last breath I'll be a fighting man
Not just with my fist, but my mind and I got a plan
Till my last breath I'll be good to go, and everything should
Know
I got to get my mind to where my heart should be
To eliminate the hate, that get's the best to me
And what is left is the rest of necessity
To carry me on home

Till my last breath, I'm never letting go
Until my last breath, the whole world's gonna know
Until my last breath, I'll be keeping a score
Until my last breath, I'll be fighting for more

Until my last breath, I ain't nobodies bitch
Until my last breath, I'll keep pissin' on the rich
Until my last breath, I'm gonna do it, I ain't gonna just try
Until my last breath, I'm gonna hold my head up high
'Cause I know things ain't always gonna be the way that we
Want them to
And we're all gonna have to put up with something we don't
Wanna do
But let me tell you that's a hell of a lot better way
Then sitting on your ass and letting someone else lead the way
Fubb that

Till my last breath, I'm never letting go
Until my last breath, the whole world's gonna know
Until my last breath, I'll be keeping a score
Until my last breath, I'll be fighting for more

Sunsets and butterflies, slowly disappear
As screams from the underworld is all I seem to hear
Progress is slow to see, but yet I still believe
That if I fight the good fight
It'll never get the best of me!
Till my last breath

Never get the best of me, never get the best of me
Never get the best of me, never get the best of me

Till my last breath, until my last breath
Until my last breath, until my last breath
Never get the best of me!
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

bool nice(long x1,long y1,long x2,long y2)
{
 if (x1==x2)return false;
 if (y1==y2)return false;
 return true;
}

long a,b,ti,tj;
pair<pair<long, long> ,pair<long, long> > ans;
vector<pair<long, long> > v;
long s,af;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>a>>b;

for (int i=-1200;i<=1200;i++)
 for (int j=-1200;j<=1200;j++)
  if (i*i+j*j==b*b)v.push_back(make_pair(i,j));
  
for (int i=-1200;i<=1200;i++)
 for (int j=-1200;j<=1200;j++)
 {
  if (i*i+j*j!=a*a)continue;
  for (int q=0;q<v.size();q++)
  {
   ti=v[q].first;
   tj=v[q].second;
   s=i*tj-j*ti;
   s=abs(s);
//   cout<<s<<" "<<a*b*2<<endl;
   if (s!=a*b)continue;
   //cout<<i<<" "<<j<<" "<<ti<<" "<<tj<<endl;
   
   if (nice(0,0,i,j)&&nice(0,0,ti,tj)&&nice(i,j,ti,tj))
   {af=1;ans=make_pair(make_pair(i,j),make_pair(ti,tj));}
  }
 }

if (af==0)cout<<"NO"<<endl;
else
{
 cout<<"YES"<<endl;
 cout<<0<<" "<<0<<endl;
 cout<<ans.first.first<<" "<<ans.first.second<<endl;
 cout<<ans.second.first<<" "<<ans.second.second<<endl;
 
} 

cin.get();cin.get();
return 0;}