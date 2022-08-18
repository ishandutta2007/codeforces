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
stack <char> s;
string v,st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
for (int i=0;i<st.size();i++)
{if (s.size()==0||s.top()!=st[i])s.push(st[i]);
 else s.pop();
}
while (s.size()){v.push_back(s.top());s.pop();}
//cout<<v<<endl;
for (int i=v.size();i;--i)cout<<v[i-1];
cout<<endl;
cin.get();cin.get();
return 0;}