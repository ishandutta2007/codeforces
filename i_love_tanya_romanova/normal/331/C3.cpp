/*
In amidst the madness
That only tears into myself
The mist of sadness
It turns into my hell

Burns into the frail
All this speak of death

My honesty in death
Modesty until the end
Honesty in death

In amidst the anguish
My only prayers are to myself
Resistance crashes
As clemency compels

Turning not to face
Only speak of death

My honesty in death
Honesty adorns the end
Modesty's intent

My honesty in death
Modesty until the end
Honesty in death

My honesty in death
Honesty adorns the end
Modesty's intent
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

//ans - OH
long long n;
set<pair<long long, long long> > solved;
map<pair<long long, long long> , pair<long long, long long> > dp;

pair<long long, long long> solve(long long num,long long pre)
{
 if (num<=0)return make_pair(0,-num);
 if (num<10)return make_pair(1,max(0ll,-(num-pre)));
 pair<long long, long long> kval=make_pair(num,pre);
 if (solved.find(kval)!=solved.end())return dp[kval];
 long long a=1;
 while (a<=num/10){a*=10;}
 long long tans=0;
 
 while (num>0)
 {
   long long rem=num%a;
   long long fdg=num/a;
   pair<long long, long long> mov=solve(rem,max(fdg,pre));
   tans+=mov.first;
   num=num-rem-mov.second;
   if (mov.second==0&&fdg>0){++tans;num-=max(pre,fdg);}    
 }
 solved.insert(kval);
 dp[kval]=make_pair(tans,-num);
 return dp[kval];
}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cout<<solve(n,0).first<<endl;

cin.get();cin.get();
return 0;}