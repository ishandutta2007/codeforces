//#pragma comment(linker, "/STACK:16777216")
//#include <fstream>
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
 
#define  INF 100000000
#define eps 1e-9
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

long n,k,t,ans;

long g(long n)
{long r=0;
while(n)
{ long t=n%10;
if (t==4||t==7)r++;n/=10;}
return r;}

int main(){
//freopen("horse.in","r",stdin);
//freopen("horse.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>t;
 if (g(t)<=k)
 ++ans;   
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}