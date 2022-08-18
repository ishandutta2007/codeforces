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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
using namespace std;
long p1,p2,p3,p4,a,b,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>p1>>p2>>p3>>p4;
cin>>a>>b;
p1=min(p1,p2);
p1=min(p1,p3);
p1=min(p1,p4);
p1=min(p1,b+1);
if (p1<a)ans=0;else ans=p1-a;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}