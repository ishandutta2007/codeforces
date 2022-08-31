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
long a,b,c,d;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b>>c;
a=a*4+b*2+c;
cin>>b>>c>>d;
b=b*4+c*2+d;
if ((a^b)!=7)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
cin.get();cin.get();
return 0;}