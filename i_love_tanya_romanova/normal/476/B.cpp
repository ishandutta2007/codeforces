/*
If you're hurt, why don't you tell someone?
Don't feel bad, you're not the only one, yeah

Don't go hiding, hiding, in the shade
Don't go hiding, hiding, in the shade

If you were abused, I'll find someone to help you
I know you were used, what are you gonna do?, Yeah

Don't go hiding, hiding, in the shade
Don't go hiding, hiding, in the shade

Don't go hiding, hiding, in the shade, oh
Don't go hiding, hiding, in the shade

Hiding, hiding, don't go hiding
Hiding, hiding, in the shade

Yeah, yeah in the shade, in the, in the shade
In the shade, in the shade, in the shade
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

string st;
long need,n;

string temp;
long t,ans,ttl;

string gen(long mask)
{
 string res="";
 for (int i=0;i<n;i++)
  if (mask&(1<<i))
   res+="+";
   else res+="-";
 return res;
}

long eval(string st)
{
 long s=0;
 for (int i=0;i<st.size();i++)
  if (st[i]=='+')++s;
  else --s;
 return s;
}

bool match(string st1,string st2)
{
 for (int i=0;i<st1.size();i++)
  if (st1[i]!='?'&&st2[i]!='?'&&st1[i]!=st2[i])return false;
 return true;
}

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
need=eval(st);
cin>>st;
n=st.size();

for (int mask=0;mask<(1<<n);mask++)
{
    string temp=gen(mask);
    if (match(temp,st)){++ttl;t=eval(temp);if (t==need)++ans;}
}

cout.precision(10);

cout<<fixed<<ans*1.0/ttl<<endl;

cin.get();cin.get();
return 0;}