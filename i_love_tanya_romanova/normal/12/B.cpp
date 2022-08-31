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
string st1,st2;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st1;
cin>>st2;
for (int i=0;i<st1.size();i++)
for (int j=i+1;j<st1.size();j++)
{if (st1[i]>st1[j]&&(i!=0||st1[j]>'0'))swap(st1[i],st1[j]);
}
//cout<<st1<<endl;
if (st1==st2)cout<<"OK"<<endl;
else cout<<"WRONG_ANSWER"<<endl;
cin.get();cin.get();
return 0;}