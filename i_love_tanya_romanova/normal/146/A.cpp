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
//#define bs 7ll
//#define szz 400
//#define pb push_back
using namespace std;
long n,s,q,fl;
string st;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
cin>>st;
q=n/2;
fl=0;
for (int i=0;i<st.size();i++)
if (st[i]!='4'&&st[i]!='7')fl=1;
for (int i=0;i<q;i++)
s+=st[i];
for (int i=q;i<st.size();i++)
s-=st[i];

if (s||fl)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}