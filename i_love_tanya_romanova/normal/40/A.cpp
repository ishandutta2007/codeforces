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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long x,y,r,p;
bool issquare(long m)
{
     for (int i=0;i<=10000;i++)if (i*i==m)return true;
     return false;     
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>x>>y;
r=x*x+y*y;
if (issquare(r))cout<<"black"<<endl;
else 
{
     p=int(sqrt(r+0.0001));
     p+=(x*y<0);

if (p%2)cout<<"white"<<endl;
else cout<<"black"<<endl;
}
cin.get();cin.get();
return 0;}