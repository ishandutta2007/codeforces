/*
No way, I say no way
You can't put me down
I know who you are
I know what you want

You can say anything
You can say everything
I don't care anymore
'cause you need to know
that

No
One
Else
Only god can judge me

I am all your thoughts
'cause you're so envy
you just fuck up your energy
cause you need to know
that

No
One
Else
Only god can judge me
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

using namespace std;

string st1,st2,z1,z2;
long er;

bool check(string st)
{
 long fen,len;
 fen=1e9;
 len=-1e9;
 for (long i=0;i<st.size();i++)
 {
  if (i+z1.size()>st.size())break;
  er=0;
  for (int j=0;j<z1.size();j++)
   if (z1[j]!=st[i+j])er=1;
  if (er==0)fen=min(fen,i);
 }
 for (long i=0;i<st.size();i++)
 {
  if (i+z2.size()>st.size())break;
  er=0;
  for (int j=0;j<z2.size();j++)
   if (z2[j]!=st[i+j])er=1;
  if (er==0)len=max(len,i);
 }
// cout<<fen<<" "<<len<<endl;
 long zz=z1.size();
 return (fen+zz<=len);
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1;
st2=st1;
reverse(st2.begin(),st2.end());
cin>>z1>>z2;
if (check(st1)&&check(st2))
cout<<"both"<<endl;
else if (check(st1))cout<<"forward"<<endl;
else if (check(st2))cout<<"backward"<<endl;
else cout<<"fantasy"<<endl;

cin.get();cin.get();
return 0;}