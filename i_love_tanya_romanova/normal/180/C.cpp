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
long ans,tans;
long calc;

bool dn(char c)
{
     if (c<'a')return false;
     if (c>'z')return false;
     return true;
}
int main(){
//freopen("mitm.in","r",stdin);
//freopen("mitm.out","w",stdout);
cin>>st;
for (int i=0;i<st.size();i++)
if (dn(st[i]))++calc;
ans=calc;
tans=ans;
for (int i=st.size()-1;i+1;i--)
{
    if (dn(st[i]))--tans;
    else ++tans;
    ans=min(ans,tans);
   // cout<<tans<<" "<<ans<<endl;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}