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
string st;
long n;
int main(){
//freopen("intput.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>n;
st="ROYGBIV";
for (int i=1;i<=n/7;i++)
{cout<<st;}
for (int i=1;i<=n%7;i++)
{if (n%7<4)cout<<st[i+2]; else cout<<st[i-1];}

cin.get();cin.get();
return 0;}