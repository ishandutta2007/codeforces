/*
I am a factory girl, won't you pardon me?
See I can make my whole world in a backseat
Lost point, want a joint, show me how to treat a john
Someone save me, save me from what I'm on

Wait a minute girl, can you show me to the party?
I said wait a minute girl, can you show me to the party?
Please let me in through the backdoor
Just let me in through the backdoor, baby
Just let me in through the backdoor, just let me in
Wait a minute girl, can you show me to the party?

It's gonna be a real good time

I'm waiting for my man and hollywood and vine, so fine
Been done in the alley, son I'm on New York time
Take a look at those red lights, green lights, blowin' my mind
I'll show you somethin' if you show me a good time

Wait a minute girl, can you show me to the party?
Wait a minute girl, can you show me to the party?
I'll let you in through the backdoor
I'll let you in through the backdoor, baby
I'll let you in through the backdoor, I'll let you in
Wait a minute girl, can you show me to the party?

Here she comes, coming around again
Here she comes, coming around again
Here she comes, coming around again
Here she comes, coming again

Wait a minute girl, can you show me to the party?
I said wait a minute girl, can you show me to the party?

Wait a minute girl, can you show me to the party?
Wait a minute, wait a minute, wait a minute
Wait a minute, wait a minute, hey girl, can you show me, girl?
Can you show me to the party? Can you show me to the party?
Can you show me to the party?
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long tests;
long a,s1,s;
string temp;

long gett(string st)
{
 long s=0;
 long b=1;
 for (int i=1;i<st.size();i++)
 {
  b*=26;
  s+=b;
 }
 b=1;
 for (int i=st.size()-1;i+1;--i)
 {
     s+=(st[i]-'A')*b;
     b*=26;
 }
 return s+1;
}

bool nice(string st)
{
 long calc=0;
 for (int i=0;i<st.size();i++)
 {
     if (st[i]<='9'&&st[i-1]>'9')
     ++calc;
 }
 return (calc>1);
}

string eval(long num)
{
 --num;
 long ttl=26;
 long sz=1;
 while (num>=ttl){num-=ttl;++sz;ttl*=26;}
 vector<char> t;
 for (int i=1;i<=sz;i++)
 {
  t.push_back(num%26+'A');num/=26;
 }
 reverse(t.begin(),t.end());
 string res="";
 for (int i=0;i<t.size();i++)
 res+=t[i];
 return res;
}

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>st;
 if (nice(st))
 {
  a=1;s=0;
  while (st[a]!='C')
  {s=s*10+st[a]-48;++a;}
  ++a;
  s1=0;
  while(a<st.size())
  {
   s1=s1*10+st[a]-48;++a;
  }
  cout<<eval(s1)<<s<<endl;
 }
 else
 {
  temp="";
  for (int i=0;st[i]>'9';i++)
  {
   temp+=st[i];
  }
  cout<<"R";
  for (int i=0;i<st.size();i++)
  if (st[i]<='9')cout<<st[i];
  cout<<"C";
  cout<<gett(temp)<<endl;
 } 
}

cin.get();cin.get();
return 0;}