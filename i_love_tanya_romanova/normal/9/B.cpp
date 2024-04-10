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
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long n,ansp;
double x[10000],cx,cy,ans,vb,vs;

double d(double x1,double y1,double x2,double y2)
{
       x1=x1-x2;
       y1=y1-y2;
       x1*=x1;
       y1*=y1;
       x1+=y1;
       return sqrt(x1);
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>vb>>vs;
for (int i=0;i<n;i++)
cin>>x[i];
cin>>cx>>cy;

ans=1000000;

for (int i=1;i<n;i++)
{
    if (d(x[i],0,x[0],0)/vb+d(x[i],0,cx,cy)/vs<ans+eps)
    {
     ans=d(x[i],0,x[0],0)/vb+d(x[i],0,cx,cy)/vs;
     ansp=i+1;
    }
    
}

cout<<ansp<<endl;

cin.get();cin.get();
return 0;}