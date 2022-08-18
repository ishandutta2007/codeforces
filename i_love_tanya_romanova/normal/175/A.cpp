
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-8
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long ans;
string st,st1,st2,st3;

string cop (string st,long a,long b)
{
       string st1;
       for (int i=a;i<b;i++)
       st1+=st[i];
       return st1;
}


long gp(string st)
{
long r=0;
for (int i=0;i<st.size();i++)
r=r*10+st[i]-48;
return r;
 }
 
bool isc(string st)
{
     if (st.size()>1&&st[0]=='0')return false;
     if (st.size()>7)return false;
     if (gp(st)>1000000)return false;
     return true;
}

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>st;
ans=-1;
for (int i=1;i<st.size();i++)
for (int j=i+1;j<st.size();j++)
{
    st1=cop(st,0,i);
    st2=cop(st,i,j);
    st3=cop(st,j,st.size());
    if (isc(st1)&&isc(st2)&&isc(st3))
    ans=max(ans,gp(st1)+gp(st2)+gp(st3));
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}