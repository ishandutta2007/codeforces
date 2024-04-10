/*
I think you just forgot to tell me why
Why I was fading out again
Why my mask of sanity was slipping off again, my friend
Beware of hatred when your time stands still

Like the average stalker, forge to forgive
Like the average stalker

I'm just sliding, disappear into the night
Like a strange and a forgotten light
One, two, three, four and I'm at your door
Calculating infinity

In my silence where no one else can hear
What is right, what is wrong

In my silence where no one else forgives
Where the sane and insane strikes together as one

Like the average stalker, forge to forgive
Like the average stalker

Where is the fire, it makes no sense at all
I'm just hiding beneath the hour
Disabled through affliction I can't reach out
Reach out, reach out

In my silence where no one else can hear
What is right, what is wrong

In my silence where no one else forgive
Where the sane and insane strikes together as one

With a violent work of art I proceed
In this lack of faith I get what I need
What I need!

Like the average stalker, forge to forgive
Like the average stalker

Like a silent talker
Like the average stalker
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n;
vector<long> v;
long used[1<<20];
long temp;
long ans;
vector<long> av;

long t;

long long pw(long long a,long long b)
{
 if (b==0)return 1;
 if (b%2)return a*pw(a,b-1)%n;
 return pw(a*a%n,b/2);
}

long inverse(long long x)
{
 return pw(x,n-2);
}

long used1[1<<20],used2[1<<20];

bool check()
{
 for (int i=0;i<=n;i++)
  used1[i]=used2[i]=0;
 long long p=1;
 for (int i=0;i<av.size();i++)
 {
  p*=av[i];
  p%=n;
  used1[av[i]]=1;
  used2[p]=1;
 }
 for (int i=0;i<n;i++)
  if (used2[i]==0)
   return false;
 for (int i=1;i<=n;i++)
  if (used1[i]==0)
   return false;
  return true;
}
int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;

if (n==1)
{
 cout<<"YES"<<endl;
 cout<<1<<endl;
 return 0;
}

if (n==4)
{
 cout<<"YES"<<endl;
 cout<<1<<endl;
 cout<<3<<endl;
 cout<<2<<endl;
 cout<<4<<endl;
 return 0;
}

for (int i=2;i*i<=n;i++)
{
 if (n%i==0)
 {
  cout<<"NO"<<endl;
  return 0;
 }
}
/*
for (int i=1;i<=n;i++)
{
 v.push_back(i);
}
do
{
 for (int i=0;i<n;i++)
  used[i]=0;
  temp=1;
 for (int i=0;i<v.size();i++)
 {
  temp=temp*v[i];
  temp%=n;
  used[temp]=1;
 }
 long er=0;
 for (int i=0;i<n;i++)
  if (used[i]==0)
   er=1;
  if (er==0)ans=1;
 if (ans)
 {
  for (int i=0;i<v.size();i++)
   cout<<v[i]<<" ";
 cout<<endl;
 }
  if (ans)break;
}
while (next_permutation(v.begin(),v.end()));
*/
//cout<<ans<<endl;

av.push_back(1);
for (int i=2;i<n;i++)
{
 t=inverse(i-1);
 t=1ll*t*i%n;
// t%=n;
 av.push_back(t);
 used[t]=1;
}

av.push_back(n);

cout<<"YES"<<endl;
for (int i=0;i<av.size();i++)
 cout<<av[i]<<"\n";//" ";

//cout<<check()<<endl;

cin.get();cin.get();
return 0;}