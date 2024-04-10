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
string st;
long p;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>st;
p=0;
while (st[p]!='.')++p;
if (st[p-1]>'8'){cout<<"GOTO Vasilisa."<<endl;}
else
{if (st[p+1]>'4')st[p-1]++;
 for (int i=0;i<p;i++)cout<<st[i];
 cout<<endl;
}
cin.get();cin.get();
return 0;}