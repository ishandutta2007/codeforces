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
long fl;
char ar[200][200];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
for (int i=1;i<=3;i++)
for (int j=1;j<=3;j++)
cin>>ar[i][j];
for (int i=1;i<=3;i++)
for (int j=1;j<=3;j++)
if (ar[i][j]!=ar[4-i][4-j])fl++;
if (fl)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

 cin.get();cin.get();
return 0;}