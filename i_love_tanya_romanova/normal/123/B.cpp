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
long long aabs(long long a)
{if (a<0)return -a; else return a;
 }
long long a,b,x1,x2,y1,y2,s1,s2,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b;

cin>>x1>>y1>>x2>>y2;

s1=(x1+y1+2000000000ll*2*a)/(2*a);
s2=(y2+x2+2000000000ll*2*a)/(2*a);
ans=aabs(s1-s2);
//cout<<s1<<" "<<s2<<endl;
s1=(x1-y1+2000000000ll*2*b)/(2*b);
s2=(x2-y2+2000000000ll*2*b)/(2*b);
ans=max(ans,aabs(s1-s2));

//cout<<s1<<" "<<s2<<endl;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}