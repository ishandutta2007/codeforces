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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
using namespace std;
string st;
vector <char> ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
while (st.size())
{if (st.size()==1||st[0]=='.'){ans.push_back('0');st.erase(st.begin());}
else {
     if (st[1]=='.'){ans.push_back('1');}else ans.push_back('2')
     ;st.erase(st.begin(),st.begin()+2);}}
for (int i=0;i<ans.size();i++)
cout<<ans[i];
cout<<endl;
cin.get();cin.get();
return 0;}