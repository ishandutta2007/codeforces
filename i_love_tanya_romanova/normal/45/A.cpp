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
string st[200],st1;
long ps,q;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st1;
st[1]="January";
st[2]="February";
st[3]="March";
st[4]="April";
st[5]="May";
st[6]="June";
st[7]="July";
st[8]="August";
st[9]="September";
st[10]="October";
st[11]="November";
st[12]="December";
ps=1;
while (st[ps]!=st1)++ps;
cin>>q;
while (q){++ps;--q;if (ps>12)ps=1;}
cout<<st[ps]<<endl;
cin.get();cin.get();
return 0;}