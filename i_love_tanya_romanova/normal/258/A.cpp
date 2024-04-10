//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
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
#include <memory.h>

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh


#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

string st;
long ps;

int main(){
//freopen("peacefulsets.in","r",stdin);
//freopen("peacefulsets.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
ps=1000000;
for (int i=st.size()-1;i+1;--i)
if (st[i]=='0')ps=i;

if (st.size()==1)
cout<<0<<endl;
else{
if (ps>st.size())ps=0;
for (int i=0;i<st.size();i++)
if (i!=ps)cout<<st[i];
cout<<endl;
}
cin.get();cin.get();
return 0;}