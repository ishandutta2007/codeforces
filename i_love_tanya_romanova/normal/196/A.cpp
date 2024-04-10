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
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
#define MAXN 1000000

string st;
long mu;
vector<char>v;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;

mu=-1;
for (int q='z';q>='a';--q)
for (int i=0;i<st.size();i++)
if (st[i]==q&&i>mu){mu=i;v.push_back(q);}
for (int i=0;i<v.size();i++)
cout<<v[i];
cout<<endl;
cin.get();cin.get();
return 0;}