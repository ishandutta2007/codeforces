/*
Diving head first into this hopeless world.
I was born to breathe not to choke.
Can you see my wounds.
Can you feel my pain.
Cease to breathe.
ease to suffer.
I choose to face this fucking world.
And hold it down until the end.
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long ps;
string st;

bool badchar(char c)
{
 if (c>='a'&&c<='z')
  return false;
 if (c>='A'&&c<='Z')
  return false;
  if (c>='0'&&c<='9')
   return false;
  if (c=='_')
   return false;
 return true;
}

bool invalid(string st)
{
 if (st.size()<1||st.size()>16)return true;
 for (int i=0;i<st.size();i++)
  if (badchar(st[i]))
   return true;
 return false;
}

vector<string> split(string st)
{
 vector<string> res;
 string temp;
 for (int i=0;i<st.size();i++)
 {
  if( st[i]=='.')
   res.push_back(temp),
   temp="";
  else temp+=st[i];
 }
 res.push_back(temp);
return res;
}

string solve(string st)
{
 ps=-1;
 for (int i=0;i<st.size();i++)
 {
  if (st[i]=='/')
  {
   ps=i;
   break;
  }
 }
 
 if (ps!=-1)
 {
  string temp="";
  for (int i=ps+1;i<st.size();i++)
  {
   temp+=st[i];
  }
  if (invalid(temp))return "NO";
  while (st[st.size()-1]!='/')
   st.erase(st.end()-1);
   st.erase(st.end()-1);
 }
 
 ps=-1;
 for (int i=0;i<st.size();i++)
 {
 if (st[i]=='@')
  ps=i;
 }
 
 if (ps==-1)
  return "NO";
  
 string temp1,temp2;
 for (int i=0;i<ps;i++)
  temp1+=st[i];
 for (int i=ps+1;i<st.size();i++)
  temp2+=st[i];
 if (invalid(temp1))return "NO";
 if (temp2.size()>32)return "NO";
 vector<string> V=split(temp2);
 for (int i=0;i<V.size();i++)
  if (invalid(V[i]))return "NO";
 return "YES";
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cout<<solve(st)<<endl;

cin.get();cin.get();
return 0;}