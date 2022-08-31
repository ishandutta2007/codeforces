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
#define bs 1000000007
//#define szz 400
using namespace std;
string st,st1,ans;
long n;
bool ispre(string a,string b)
{if (b.size()<a.size())return false;
for (int i=0;i<a.size();i++)
if (a[i]!=b[i])return false;
return true;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st;
cin>>n;
ans="";
for (int i=0;i<n;i++){cin>>st1;if (ispre(st,st1))ans=min(ans,st1);}
if (ans=="")cout<<st<<endl;
else cout<<ans<<endl;

cin.get();cin.get();
return 0;}