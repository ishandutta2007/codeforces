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
//#define bs 1000000007
//#define szz 400
using namespace std;
string st,z;
long s,q;

long find(char a)
{q=0;
while (z[q]!=a)++q;
 return q+8;}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

z="><+-.,[]";
cin>>st;
s=0;
for (int i=0;i<st.size();++i)
{s=s*16+find(st[i]);
 s%=1000003;
}
cout<<s<<endl;
cin.get();cin.get();
return 0;}