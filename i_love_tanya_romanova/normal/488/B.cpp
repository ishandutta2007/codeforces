/*
I will not leave a letter, nothing at all
I'm sure you won't notice that I'm even gone
I won't break this silence we've shared for so long
I will be strong

I will not leave a letter, nothing at all
I'm sure you won't notice that I'm even gone
Why did I stake here, stake for so long
When we're so far gone

I feel so stupid taking this fall
I should have seen it, known all along
Won't break this silence we've shared for so long
I will be strong

What did you possibly want from me
Can't you see I'm already gone
Well, everything we thought we'd be
I still don't feel sorry for this loss

I will not waste a moment thinking these thoughts
For caring comes easy, I never cared at all
Hurt became hate, now I'm feeling the strain
There's just too much pain

Fell into pieces, got swept away
Left all our pictures in the sun to fade
I won't break this silence we've shared for so long
I will be strong

What did you possibly want from me
Can't you see I'm already gone
Well, everything we thought we'd be
I still don't feel sorry for this loss

You don't have to say anything at all
I won't stop you from walking away, I'll do nothing at all

Sitting here, I waste a day
While the memories fade away
You know I expected so much more from you
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

long n,ar[1<<10];
long x;
long ans;
vector<long> v;

void show(vector<long> v)
{
 cout<<"YES"<<endl;
 for (int i=0;i<v.size();i++)
 {
  cout<<v[i]<<endl;
 }
}

bool check(vector<long> v)
{
 sort(v.begin(),v.end());
 return (v[0]+v[3]==v[1]+v[2]&&v[0]*3==v[3]);
}

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

if (n<2)
{
 x=ar[1];
 if (x==0)x++;
 cout<<"YES"<<endl;
 if (n==0)cout<<x<<endl;
 cout<<x<<"\n"<<x*3<<"\n"<<x*3<<"\n";
}
else
if (n==4)
{
 for (int i=1;i<=n;i++)
  v.push_back(ar[i]);
 if (check(v))
 cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}
else if (n==3)
{
 for (int i=1;i<=1666;i++)
 {
  v.clear();
  for (int j=1;j<=3;j++)
   v.push_back(ar[j]);
   v.push_back(i);
  if (check(v)==1&&ans==0)
  {
   ans=1;
   cout<<"YES"<<endl;
   cout<<i<<endl;
  }
 }
 if (ans==0)
  cout<<"NO"<<endl;
}
else if (n==2)
{
 for (int i=1;i<=1666;i++)
 for (int p=1;p<=1666;p++)
 {
  v.clear();
  for (int j=1;j<=2;j++)
   v.push_back(ar[j]);
   v.push_back(i);
   v.push_back(p);
  if (check(v)==1&&ans==0)
  {
   ans=1;
   cout<<"YES"<<endl;
   cout<<i<<endl;
   cout<<p<<endl;
  }
 }
 if (ans==0)
  cout<<"NO"<<endl;
}

cin.get();cin.get();
return 0;}