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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-12
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n,m,x1,y1,x2,y2,dx,dy;
long solve(long a,long b)
{
     if (a>4||b>4)return 0;
     if (a>b)swap(a,b);
     if (a>2&&b==4)return 0;
     return 1;
     }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n>>m>>x1>>y1>>x2>>y2;
dx=abs(x1-x2);
dy=abs(y1-y2);
if (solve(dx,dy))
cout<<"First"<<endl;
else cout<<"Second"<<endl;

cin.get();cin.get();
return 0;}