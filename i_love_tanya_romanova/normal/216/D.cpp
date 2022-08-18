/*
As the sun breaks, above the ground,
An old man stands on the hill.
As the ground warms, to the first rays of light
A birdsong shatters the still.

His eyes are ablaze,
See the madman in his gaze.

Fly on your way, like an eagle,
Fly as high as the sun,
On your way, like an eagle,
Fly and touch the sun.

Now the crowd breaks and a young boy appears
Looks the old man in the eye
As he spreads his wings and shouts at the crowd
In the name of God my father I fly.

His eyes seem so glazed
As he flies on the wings of a dream.
Now he knows his father betrayed
Now his wings turn to ashes to ashes his grave

Fly, on your way, like an eagle,
Fly as high as the sun,
On your way, like an eagle,
Fly as high as the sun.
On your way, like an eagle,
Fly, touch the sun
On your way, like an eagle,
Fly

Fly as high as the sun.
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n,sz[10000];
vector<long> v[10000];
long long ans,lb,rb,ld,ul,dl;
long long l1,l2;

long long solve(long long b,long long h)
{
     if (v[b].size()==0)return 0;
     if (v[b][0]>h)return 0;
     long l,r,m;
     l=0;
     r=v[b].size()-1;
     while (l<r)
     {
      m=l+r+1;m/=2;if (v[b][m]>h)r=m-1;
      else l=m;
     }
     return l+1;
}

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>sz[i];
    
    v[i].resize(sz[i]);
    
    for (int j=0;j<sz[i];j++)
    cin>>v[i][j];
    
    sort(v[i].begin(),v[i].end());
}

for(int i=1;i<=n;i++)
{
 for (int j=1;j<v[i].size();j++)
 {
  if (j==0)dl=0; else dl=v[i][j-1];
  ul=v[i][j];
  if (i==1)lb=n; else lb=i-1;
  if (i==n)rb=1;else rb=i+1;
  l1=solve(lb,ul)-solve(lb,dl);
  l2=solve(rb,ul)-solve(rb,dl);
 // if (i==7&&j==2)
 // cout<<l1<<" # "<<l2<<endl;
  
  if (l1!=l2){++ans; //cout<<i<<" "<<j<<endl;
   } 
 }       
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}