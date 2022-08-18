/*
This is for the kids who have no where to turn
Who have nothing to live for
You think you haven't the will to persist
You have to search within yourself

All the work that you've done in vain
Been overlooked and taken for granted
Only you can end your suffering
You must be honest with yourself

You have nothing left to lose
You feel that everyone's out to get you
Been beaten down but the hate still breathes
Confined by consequence, it's your soul you must release

It's our struggles that define us
And the hardships we endure
Your spirit can't be broken now
You've come too far

All your life you told yourself you were never alone
All your time spent on the problems that have no solutions
In your mind giving up was never an option
Out of spite hold onto the hate, it's helped you stay focused

You are one but you're never alone
You can't atone for every promise you've broken
In this moment there's no way you will fail
You must be honest with yourself

Use your pain to achieve your goals
Make amends while you can and stay focused
You can't be burdened by your lack of control
Never stray from the path you have chosen

It's our struggles that define us
And the hardships we endure
Your spirit can't be broken now
You've come too far

All your life you told yourself you were never alone
All your time spent on the problems that have no solutions
In your mind giving up was never an option
Out of spite hold onto your hate, it's helped you stay focused

This is for the kids who have no where to turn
Who have nothing to live for
You think you haven't the will to persist
You have to search within yourself

This spirit can't be broken
This spirit can't be broken
This spirit can't be broken
It's who you are

It's our struggles that define us
And the hardships we endure
Your spirit can't be broken now
You've come too far

Forever, forever
Forever convicted
Forever, forever
Convicted
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

long long pw1[1<<23],pw2[1<<23];
string zr;

long n,m;
pair<long long, long long> tp1,tp2;
long q,ri;
long er;
long long ans;

long long pw(long long a,long long b)
{
 if (b==0)return 1;
 if (b%2) return a*pw(a,b-1)%bs;
 return pw(a*a%bs,b/2);
}

long long s1[1<<21],s2[1<<21];

pair<long long, long long> get_hash(long l,long r)
{
 long long val1,val2;
 val1=s1[r]-s1[l-1]+bs;
 val2=s2[r]-s2[l-1]+bs;
 val1%=bs;
 val2%=bs;
 val1*=pw1[2000000-l];
 val2*=pw2[2000000-l];
 val1%=bs;
 val2%=bs;
 return make_pair(val1,val2);
}


int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
getline(cin,zr);
getline(cin,zr);

pw1[0]=1;
pw2[0]=1;

for (int i=1;i<=2000000;i++)
{
 pw1[i]=pw1[i-1]*137%bs;
 pw2[i]=pw2[i-1]*173%bs;
}

ri=0;
er=0;
ans=1;

for (int i=0;i<zr.size();i++)
{
    s1[i+1]=s1[i]+zr[i]*pw1[i];
    s2[i+1]=s2[i]+zr[i]*pw2[i];
    s1[i+1]%=bs;
    s2[i+1]%=bs;
}
for (int i=0;i<m;i++)
{
 cin>>q;
 if (q>ri)
 {
  ans=ans*pw(26,q-ri-1);
  ans%=bs;
  ri=q+zr.size()-1;
 }
 tp1=get_hash(1,ri-q+1);
 tp2=get_hash(zr.size()-(ri-q),zr.size());
 if (tp1.first!=tp2.first||tp1.second!=tp2.second) er=1;
 ri=q+zr.size()-1;
}

if  (ri>n)
 er=1;
else
{
    ans=ans*pw(26,n-ri)%bs;
}
if (er)cout<<0<<endl;
else cout<<ans<<endl;

cin.get();cin.get();
return 0;}