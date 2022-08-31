/*
I caught a chill and it's still frozen on my skin
I think about why I'm alone by myself no one else to explain
How far do I go no one knows
If the end is so much better why don't we just live forever?

Don't tell me I'm the last one in line
Don't tell me I'm too late this time

I don't wanna live to waste another day
Underneath the shadow of mistakes I've made
'Cuz I feel like I'm breaking inside

I, I, I, I don't wanna fall and say I lost it all
'Cuz maybe there's a part of me that hit the wall
Leaving pieces of me behind
And I feel like I'm breaking inside

Out here nothing's clear
Except the moment I decided to move on and I ignited
Disappear into the fear
You know there ain't no coming back when you're still carrying the past

You can't erase, separate
Cigarette in my hand, hope you all understand
I won't be the last one in line
I finally figured out what's mine

I don't wanna live to waste another day
Underneath the shadow of mistakes I've made
'Cuz I feel like I'm breaking inside

I, I, I, I don't wanna fall and say I lost it all
'Cuz maybe there's a part of me that hit the wall
Leaving pieces of me behind, leaving pieces of me behind
And I feel like I'm breaking inside

I won't be the last one in line
I finally figured out what's mine

I don't wanna live to waste another day
Underneath the shadow of mistakes I've made
'Cuz I feel like I'm breaking inside

I, I, I, I don't wanna fall and say I lost it all
'Cuz maybe there's a part of me that hit the wall
Leaving pieces of me behind, leaving pieces of me behind
And I feel like I'm breaking inside

And I feel like I'm breaking
And I feel like I'm breaking inside
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

long n,k;
string st;
vector<long long> vec;
long long mask,calc;
long long ans;

long long parse(string st)
{
 st+=".";
 vector<long long> v;
 long val=0;
 for (int i=0;i<st.size();i++)
 {
  if (st[i]=='.'){v.push_back(val);val=0;}
  else val=val*10+st[i]-48;
 }
 long long res=0;
 res=v[0]*(1l<<24)+v[1]*(1ll<<16)+v[2]*256+v[3];
 return res;
}

long long gener(long long pref)
{
 long long res=0;
 for (int i=1;i<=32;i++)
  if (i<=pref)
   res+=(1ll<<(32-i));
 return res;
}

long long val;

long solve(long long mask)
{
 set<long long> dif;
 for (int i=0;i<vec.size();i++)
 {
  val=vec[i];
  val&=mask;
  dif.insert(val);
 }
 return dif.size();
}
 
int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>st;
    vec.push_back(parse(st));
}

for (int pref=1;pref<=31;pref++)
{
 mask=gener(pref);
 calc=solve(mask);
 if (calc==k&&ans==0)ans=mask;
}
if (ans==0)cout<<-1<<endl;
else
{
 cout<<ans/(1ll<<24)<<'.';
 ans%=(1ll<<24);
 cout<<ans/(1ll<<16)<<".";
 ans%=(1ll<<16);
 cout<<ans/256<<"."<<ans%256<<endl;
}

cin.get();cin.get();
return 0;}