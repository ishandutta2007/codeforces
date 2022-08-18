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
string st1,st2,st3;
long c(string st)
{long s=0;
 for (int i=0;i<st.size();i++)
 if (st[i]=='a')s++;
 for (int i=0;i<st.size();i++)
 if (st[i]=='o')s++;
 for (int i=0;i<st.size();i++)
 if (st[i]=='i')s++;
 for (int i=0;i<st.size();i++)
 if (st[i]=='e')s++;
 for (int i=0;i<st.size();i++)
 if (st[i]=='u')s++;
 return s;
 }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
getline(cin,st1);
getline(cin,st2);
getline(cin,st3);
if (c(st1)==5&&c(st2)==7&&c(st3)==5)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
cin.get();cin.get();
return 0;}