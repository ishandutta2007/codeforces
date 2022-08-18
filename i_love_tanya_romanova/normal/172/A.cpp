//#pragma comment(linker, "/STACK:16777216")
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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-6 
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

string st[200000];
long l,bd[2000],n,p;

int main(){
//freopen("input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
cin>>st[i];

l=st[0].size();

bd[l]=1;
for (int q=0;q<l;q++)
for (int i=1;i<n;i++)
if (st[i][q]!=st[0][q])bd[q]=1;
p=0;

while (bd[p]==0)++p;
cout<<p<<endl;

cin.get();cin.get();
return 0;}