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
#define bs 1000000007
//#define szz 400
using namespace std;
string st1;
long fl,ar[2000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st1;
for (int i=0;i<st1.size();i++)
ar[st1[i]]++;

cin>>st1;
for (int i=0;i<st1.size();i++)
ar[st1[i]]++;
cin>>st1;
for (int i=0;i<st1.size();i++)
ar[st1[i]]--;

fl=0;
for (int i=0;i<300;i++)
if (ar[i])fl++;
if (fl)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}