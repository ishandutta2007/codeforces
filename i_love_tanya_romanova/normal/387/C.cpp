/*
Consequence...now the panic comes
You've dabbled in magik your fingers are burned
Lost as you run towards the light
And deep in your heart you have nothing but fear

Your future is hanging by a strand
Your master makes his just demands
Game of life's price coming due
A swell of fear erupts in you

Your time is now!
Never a prayer, just silence rings
Charity works won't change a thing
Your balance of life is on our side
There's never a place to hide

What's so real is plain in sight
Cost to play: eternal life
For when we play - we play for keeps
Satan's marks forever we speak

Your time is now!
With screams you defy still silence rings
Prayers to some god won't change a thing
Gleam in your eyes reduced to tears
And deep in your heart you've nothing but fear

Why object to "rewards" you know you've earned them
Why reject all your fantasy
You can't betray what your works have bargained for you
No use to fear what you have in store
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

string st,st1,st2;
string s1,s2;
long ans;
long tt;
long p;
string gener(long start,long l)
{
 string res="";
 for (int i=start;i<start+l;i++)
 res+=st[i];
 l+=start;
 while(l<st.size()&&st[l]=='0'){res+=st[l];++l;}
 return res;
}

int main(){
//freopen("exchange.in","r",stdin);
//freopen("exchange.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
p=1;
s1=gener(0,p);
ans=1;
//cout<<s1<<endl;
tt=s1.size();
while (true)
{
      if (tt==st.size())break;
      s2=gener(tt,1);
      if (s2.size()>tt||(s2.size()==tt&&s2>s1))
      ans=1;
      else++ans;
      s1+=s2;
      tt+=s2.size();
     // cout<<s1<<" "<<s2<<endl;
      if (tt==st.size())break; 
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}