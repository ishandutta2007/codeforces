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

long n,col,s1,s2;
string st;

int main(){
//freopen("peacefulsets.in","r",stdin);
//freopen("peacefulsets.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>col;
cin>>st;
if (col==2)
{
    for (int i=0;i<st.size();i++)
    if (i%2==0&&st[i]=='A')
    s1++;
    else if (i%2==1&&st[i]=='B')s1++;
    else s2++;
    cout<<min(s1,s2)<<endl;
    for (int i=0;i<st.size();i++)
    if (s1<s2)
    {
              if (i%2)cout<<'A';else cout<<'B';
              }
              else
              {if (i%2)cout<<'B'; else cout<<'A';}       
cout<<endl;
}
else
{
 for (int i=1;i<st.size();i++)
 {
     if (st[i]==st[i-1])
     {
      long q='A';
      while (st[i-1]==q||(i+1<st.size()&&st[i+1]==q))++q;
      ++s1;st[i]=q;
     }
 }   
 cout<<s1<<endl;
 cout<<st<<endl;
}

cin.get();cin.get();
return 0;}