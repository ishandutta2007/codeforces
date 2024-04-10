/*
Crazy little mama, is your heart still meant today?
Feeling alive in some peculiar way
Baby come home
Baby come home

Pretty little woman, please come back today
It's just gotta be wrong to throw my love away
Baby come home
Baby come home
Baby come home from heartbreak city, yeah

First Avenue
First Avenue
First Avenue
I'm back from First Avenue

Hey, ma, is your heart still meant today?
Well, I'm feeling alive in some peculiar way
Baby come home
Baby come home
You just gotta come home from heartbreak city, yeah
Oh

Little woman come home
First Avenue
My baby is home
First Avenue
Gotta, gotta come
First Avenue
Ooooh-hoooo
First Avenue
I tell ya, I'm coming home
First Avenue
Oooooh
First Avenue
Help me go
First Avenue
Can't make it on my own
First Avenue
Take, take it home
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

using namespace std;

long ar[1<<20],station[1<<20],dir,cur;
long long dist[1<<20];
long n,m,cnt[1<<20],diff;
long long ans;
long long temp;

void move1(long ps)
{
 int st=station[ps];
 if (cnt[st]==0)
  ++diff;
 --cnt[st];
 if (cnt[st]==0)
  --diff;
}
void move2(long ps)
{
 int st=station[ps];
 if (cnt[st]==0)
  ++diff;
 ++cnt[st];
 if (cnt[st]==0)
  --diff;
}


int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    station[i]=i;
}
dir=-1;
cur=n-1;
for (int i=n+1;i<=800000;i++)
{
 ar[i]=ar[cur];
 station[i]=cur;
 if (cur==1)
  dir=1;
 if (cur==n)
  dir=-1;
 cur+=dir;
}
/*
for (int i=1;i<=20;i++)
 cout<<i<<" "<<ar[i]<<" "<<station[i]<<endl;
 */
for (int i=2;i<=800000;i++)
 dist[i]=dist[i-1]+abs(ar[i]-ar[i-1]);

cin>>m;
for (int i=1;i<=m;i++)
{
    cin>>temp;
    cnt[temp]++;
}

for (int i=1;i<=n;i++)
{
 if (cnt[i]) 
  diff++;   
}

ans=-1;

for (int i=1;i<m;i++)
{
    move1(i);
}


for (int i=1;i<=600000;i++)
{
 move1(i+m-1);

 if (diff==0)
 {
  temp=dist[i+m-1]-dist[i];
  if (ans==-1)
   ans=temp;
  else if(ans!=temp)
  {
  /* cout<<i<<" "<<ans<<" "<<temp<<endl;
   cin.get();
   */
   ans=-2;
  }
 }   
 move2(i);
}

if (ans<0)
 cout<<-1<<endl;
 else cout<<ans<<endl;
 
cin.get();cin.get();
return 0;}