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

string st,st1;
long long ans,diff;

long long getn(string st)
{
     long long r=0;
     
     for (int i=0;i<st.size();i++)
     r=r*10+st[i]-48;
     return r;
}

int main(){
//freopen("peacefulsets.in","r",stdin);
//freopen("peacefulsets.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st>>diff;

long ps=st.size()-1;
long long ans=getn(st);
while (ps>0)
{
      st1=st;
      for (int i=ps;i<st.size();i++)
      st1[i]='9';
//      cout<<st<<endl;
      if (st1>st){st1[ps-1]--;}
      long long aa=getn(st);
      long long bb=getn(st1);
     // cout<<aa<<" "<<bb<<endl;
      if (aa-bb<=diff)
      ans=bb;
      --ps;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}