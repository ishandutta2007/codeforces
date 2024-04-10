/*
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long long tests,l,r,v1[1<<10],v2[1<<10],res[1<<10],ans;

long long gb(long long x)
{
 long long s=0;
 while (x){s+=x%2;x/=2;}
 return s;
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
    cin>>l>>r;
    for (int i=0;i<=60;i++)
    {
     if (l&(1ll<<i))v1[i]=1;else v1[i]=0;
     if (r&(1ll<<i))v2[i]=1;else v2[i]=0;
    }
    for (int i=60;i>=0;--i)
    {
     if (v1[i]==0&&v2[i]==0)
     {res[i]=0;continue;}
     if (v1[i]==1&&v2[i]==1)
     {res[i]=1;continue;}
     if (v1[i]==0&&v2[i]==1)
     {if (i==0){res[i]=1;continue;}
      res[i]=0;
      for (int j=i-1;j>=0;--j)
       res[j]=1;
       break;
     }   
    }
    ans=0;
    for (int i=60;i>=0;--i)
     if (res[i])ans+=(1ll<<i);
    if (gb(r)>gb(ans))// 1<<x-1
    ans=r;
cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}