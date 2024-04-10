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
long n;
string s[2000],c[2000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)cin>>s[i]>>c[i];
for (int i=1;i<=n;i++)
if (c[i][0]=='r')cout<<s[i]<<endl;
for (int i=1;i<=n;i++)
if (c[i][0]=='w'||c[i][1]=='h')cout<<s[i]<<endl;
for (int i=1;i<=n;i++)
if (c[i][0]=='m')cout<<s[i]<<endl;
for (int i=1;i<=n;i++)
if (c[i][2]=='p')cout<<s[i]<<endl;
cin.get();cin.get();
return 0;}