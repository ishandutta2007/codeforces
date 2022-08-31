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
string st1,st2;
long ar[2000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
getline(cin,st1);
getline(cin,st2);
for (int i=0;i<st1.size();i++)
ar[st1[i]]++;
for (int i=0;i<st2.size();i++)
ar[st2[i]]--;
for (int i=0;i<255;i++)
if (ar[i]<0&&i!=' '){cout<<"NO"<<endl;return 0;}
cout<<"YES"<<endl;
cin.get();cin.get();
return 0;}