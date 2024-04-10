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
string st;
long fl;

bool upper(char c)
{if (c<'A')return false;
 if (c>'Z')return false;
 return true;
}

char change(char c)
{if (upper(c))return c-'A'+'a';
return c-'a'+'A';}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
fl=0;
for (int i=1;i<st.size();i++)
{if (upper(st[i])==0)fl=1;
}
if (fl==0)
for (int i=0;i<st.size();i++)
{st[i]=change(st[i]);}
cout<<st<<endl;
cin.get();cin.get();
return 0;}