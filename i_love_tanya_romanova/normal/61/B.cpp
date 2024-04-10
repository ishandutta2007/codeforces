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
long n;
string st,st1,st2,st3;

string parse(string st)
{string st1;
 for (int i=0;i<st.size();i++)
 if (st[i]!='_'&&st[i]!=';'&&st[i]!='-')st1+=st[i];
 for (int i=0;i<st1.size();i++)
 if (st1[i]>='a')st1[i]=st1[i]-'a'+'A';
 return st1;
 
 }

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>st1>>st2>>st3;
st1=parse(st1);
st2=parse(st2);
st3=parse(st3);
cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>st;
    st=parse(st);
    if (st1+st2+st3==st||st1+st3+st2==st||st2+st3+st1==st||st2+st1+st3==st||st3+st1+st2==st||st3+st2+st1==st)
    cout<<"ACC"<<endl; else cout<<"WA"<<endl;
}
 cin.get();cin.get();
return 0;
 }