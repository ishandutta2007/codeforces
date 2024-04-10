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
#define EPS 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long q,w,a,b;
long long maskk(long long a)
{q=0;
 while (a)
 {if (a%10==4||a%10==7){q=q*10+a%10;}
  a/=10;
 }
 w=0;
 while (q)
 {w=w*10+q%10;
 q/=10;
       }
       return w;
 }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b;++a;
while (maskk(a)!=b)++a;
cout<<a<<endl;
cin.get();cin.get();
return 0;}