/*
If you're leaving close the door
I'm not expecting people anymore
Hear me grieving, I'm lying on the floor
Whether I'm drunk or dead, I really ain't too sure

I'm a blind man, I'm a blind man and my world is pale
When a blind man cries, Lord you know, there ain't no sadder tale

Had a friend once in a room
Had a good time but it ended much too soon
In a cold month in that room
We found a reason for the things we had to do

I'm a blind man, I'm a blind man, now my room is cold
When a blind man cries, Lord you know, he feels it from his soul
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

long long n,m,ar[1<<20],ts,k,l,r,mid;
vector<long long> ans;
long long cp;
long long s;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 ts+=ar[i];
}
if (ts<k){cout<<-1<<endl;return 0;}

l=0;
r=1e9;
while (l<r)
{
 mid=l+r+1;
 mid/=2;
 s=0;
 for (int i=1;i<=n;i++)
 {
     if (ar[i]<mid)s+=ar[i];
     else s+=mid;
     if (s>k)s=k+1;
 }
// cout<<mid<<" "<<k<<"  "<<s<<endl;
 if (s>k)r=mid-1;
 else l=mid;
}

for (int i=1;i<=n;i++)
{
 if (ar[i]<=l)
  {k-=ar[i];ar[i]=0;}
 else k-=l,
 ar[i]-=l;
}

for (int i=1;i<=n;i++)
{
 if (ar[i]>0&&k>0){cp=i;--k;}
}

for (int i=cp+1;i<=n;i++)
 if (ar[i]>0)
  ans.push_back(i);
for (int i=1;i<=cp;i++)
 if (ar[i]>1)ans.push_back(i);

for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}