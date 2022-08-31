#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-11 
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long long l,r,a,ans,fs;
void check(long long a)
{
 long long p=a%10;
 while (a>9)a/=10;
 if (p==a)++ans;    
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>l>>r;
while (l<1000&&l<r){check(l);++l;}
if (r-l<1000)
{
             for (long long i=l;i<=r;i++)
             check(i);
}
else
{
    ans+=r/10-l/10-1;
    
a=l;
while (a>9)a/=10;
fs=a;
if (fs>=l%10)++ans;
a=r;
while (a>9)a/=10;
fs=a;
if (fs<=r%10)++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}