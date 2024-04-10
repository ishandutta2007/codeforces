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
//#define bs 1000000007
//#define szz 400
using namespace std;
long a,b,c,d,q,w;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b>>c>>d;
q=c;w=d;
while (q&&w)q>w?q%=w:w%=q;
q+=w;
c/=q;d/=q;
q=a/c;w=b/d;
q=min(q,w);
cout<<c*q<<" "<<d*q<<endl;
cin.get();cin.get();
return 0;}