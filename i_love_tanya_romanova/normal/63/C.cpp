/*
When you were here before
Couldn't look you in the eye
You're just like an angel
Your skin makes me cry
You float like a feather
In a beautiful whirl
I wish I was special
You're so very special

But I'm a creep
I'm a weirdo
What the hell am I doing here?
I don't belong here

I don't care if it hurts
I want to have control
I want a perfect body
I want a perfect soul
I want you to notice when I'm not around
You're so very special
I wish I was special

But I'm a creep
I'm a weirdo
What the hell am I doing here?
I don't belong here

She's running out the door
She's running
She runs runs runs runs
Runs

Runs

Whatever makes you happy
Whatever you want
You're so very special
I wish I was special

But I'm a creep
I'm a weirdo
What the hell am I doing here?
I don't belong here
I don't belong here
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
vector<string> v,v1;
string zr;
long a,b;
pair<long, long> tp;

pair<long, long> check(string a,string b)
{
 pair<long, long> r;
 r.first=r.second=0;
 for (int i=0;i<a.size();i++)
  for (int j=0;j<b.size();j++)
  if (a[i]==b[j])
  {
   if (i==j)r.first++;
   else r.second++;  
  }
return r;
}

bool ok(string st)
{
 for (int i=0;i<st.size();i++)
  for (int j=i+1;j<st.size();j++)
   if (st[i]==st[j])return false;
   return true;
}

void generate(string st)
{
 if (st.size()==4){if (ok(st))v.push_back(st);return;}
 st+=" ";
 for (int i=48;i<58;i++)
 {st[st.size()-1]=i;generate(st);}
}

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
generate("");

/*for (int i=0;i<v.size();i++)
cout<<v[i]<<endl;
*/

for (int i=1;i<=n;i++)
{
 v1.clear();
 cin>>zr;
 cin>>a>>b;
 for (int j=0;j<v.size();j++)
 {
     tp=check(zr,v[j]);
     if (tp.first==a&&tp.second==b)
     v1.push_back(v[j]);
 }   
 v=v1;
}

if (v.size()==0)cout<<"Incorrect data"<<endl;
else if (v.size()>1)cout<<"Need more data"<<endl;
else cout<<v[0]<<endl;

cin.get();cin.get();
return 0;}