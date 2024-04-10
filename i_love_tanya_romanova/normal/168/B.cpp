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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-9
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std;  
     
     string st,tst,st1;
     long fl;
     
     bool good(string st)
     {
          for (int i=0;i<st.size();i++)
          {
              if (st[i]==' ')continue;
              if (st[i]=='#')return true;
              return false;
          }
          return false;
          
     }
     string norm(string st)
     {
            string r="";
            for (int i=0;i<st.size();i++)
            {
                if (st[i]==' ')continue;
                r+=st[i];
            }
            return r;
     }
     
int main(){
//freopen("length.in","r",stdin);
//freopen("length.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

while (getline(cin,st))
{
      if (good(st))
      {
                   if (fl)cout<<tst<<endl;
                   tst="";fl=0;
                   cout<<st<<endl;
      }
      else
      {
          fl=1;
          st1=norm(st);
          tst+=st1;
      }
}
if (fl)cout<<tst<<endl;

cin.get();cin.get();
return 0;}