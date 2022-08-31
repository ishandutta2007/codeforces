#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
long ps;
string st,zr;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
zr="hello+";ps=0;
cin>>st;
for (int i=0;i<st.size();i++)
if (st[i]==zr[ps])ps++;
if (ps==5)cout<<"YES"<<endl; else cout<<"NO"<<endl;
cin.get();cin.get();
return 0;
}