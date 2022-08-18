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
long long p,pw,s,n;
string st;
long long geth(string st)
{
pw=1;
s=0;
for (int i=0;i<st.size();i++)
{s+=st[i]*pw;pw*=107;}
return s;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
map <long long ,long long> m;
for (int i=0;i<n;i++)
{
    cin>>st;
    p=geth(st);
    if (m[p]==0)
    {cout<<"OK"<<endl;}
    else cout<<st<<m[p]<<endl;
    m[p]++;
}

cin.get();cin.get();
return 0;}