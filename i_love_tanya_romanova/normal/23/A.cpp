#include <iostream>
//#include <fstream>
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
#define szz 400
using namespace std;
string st;
long l;
bool samme(long a,long b,long c)
{for (int i=0;i<c;i++)
if (st[a+i]!=st[b+i])return false;
return true;
 }
 
bool prov(long a)
{if (a==0)return true;
 for (int j=0;j+a<=st.size();++j)
 for (int v=j+1;v+a<=st.size();++v)
 if (samme(j,v,a))return true;
 return false;
 
 }
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
l=st.size();
while (prov(l)==0)--l;
cout<<l<<endl;

cin.get();cin.get();
return 0;}