/*
This voice, it spake
Tempted me to keep awake
Thus I realized
When there is no truth, there are no lies
You're here, so sincere
To fathom the deepest fear
Misguide, this life
Away from truth, away from its line

Hey, away
Today's less painful than tomorrow here
Hey hey, this way
These words won't carry out a promise here

This voice, now gone
My part here is finally done
Now I do realize
There was no truth, there were no lies
This greed to breathe
The will I am longing to wreathe
No words, no lies
All foul will last, all beautiful dies

A dream, a nightmare
A spasm of fleeting joy
So sincere, enchanting
A spasm of tempting void

Awaken, words taken
All hollow, so shallow
These words have no meaning
These words carry out no truth here
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

string st;
vector<string> v;

bool z(string st)
{
 if (st==".")return true;  
  if (st==",")return true;  
 if (st=="!")return true;  
 if (st=="?")return true;  
return false;
}
long tp(char c)
{
 if (c==' ')return 1;
 if (c>='a'&&c<='z')return 2;
 return 3;
}

vector<string> parse(string st)
{
 string temp;
 temp="";
 vector<string> v;
 for (int i=0;i<st.size();i++)
 {
  if (tp(st[i])!=tp(st[i-1])){if (temp.size())v.push_back(temp);temp="";}
  if (st[i]!=' ')temp+=st[i];
 }
 if(temp.size())v.push_back(temp);
 return v;
}

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

getline(cin,st);
v=parse(st);
for (int i=0;i<v.size();i++)
{
 if (i>0&&z(v[i])==0)cout<<" ";
 cout<<v[i];
}cout<<endl;

cin.get();cin.get();
return 0;}