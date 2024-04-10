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
#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
string st;
long q,w;
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
cin>>st>>q;

if (q==1&&st=="front")cout<<'L'<<endl;
if (q==1&&st=="back")cout<<'R'<<endl;
if (q==2&&st=="back")cout<<'L'<<endl;
if (q==2&&st=="front")cout<<'R'<<endl;
// else cout<<"R"<<endl;
//cin.get();cin.get();
return 0;
}