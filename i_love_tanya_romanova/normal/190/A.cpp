//#pragma comment(linker, "/STACK:16777216")
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-6 
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long n,m,minn,maxx;

int main(){
//freopen("input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>m;
if (n==0&&m>0)cout<<"Impossible"<<endl;
else
{
   minn=n+m-1;
   if (m==0)minn=n;
   maxx=n+m-min(n,m);
   cout<<maxx<<" "<<minn<<endl;
}


cin.get();cin.get();
return 0;}