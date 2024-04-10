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
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
using namespace std;
string z,st1,st2,st3;
long p1,p2;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
z="6789TJQKA";
cin>>st1;
cin>>st2>>st3;

while (st2[0]!=z[p1])++p1;
while (st3[0]!=z[p2])++p2;

if (st2[1]==st3[1]&&p1>p2)
cout<<"YES"<<endl;
else 
     if (st2[1]==st1[0]&&st3[1]!=st1[0])cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
cin.get();cin.get();
return 0;}