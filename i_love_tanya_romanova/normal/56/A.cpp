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
long s,ans,tests;
string st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>tests;
vector <string> v;
v.push_back("ABSINTH");
v.push_back("BEER");
v.push_back("BRANDY");
v.push_back("CHAMPAGNE");
v.push_back("GIN");
v.push_back("RUM");
v.push_back("SAKE");
v.push_back("TEQUILA");
v.push_back("VODKA");
v.push_back("WHISKEY");
v.push_back("WINE");
for (;tests;--tests)
{cin>>st;
 for (int i=0;i<v.size();i++)if (v[i]==st)ans++;
  s=0;
  for (int i=0;i<st.size();i++)
  s=s*10+st[i]-48;
  if (s<18&&s>=0)ans++;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}