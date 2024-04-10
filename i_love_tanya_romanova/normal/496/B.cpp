/*
We are not machines
we are not machines programmed, encoded
we are so much more, we are so much more

oh the lights
burning like fireflies caught in a web
electricity hums in our heads
we're overwhelmingly fearless

when diamond eyes light up the sky, I promise you that we can change the world
when diamond eyes light up the sky, I promise you that we can change...

we are not your routines
we are not your routines despite what you've told us
we are all one, we are all one...

...when lights like freeways burning mirrors and melting skylines haunt your door
you should swing to connect, swing to connect the cord
color, I see the rhythm in waves and onward still
color, I see the rhythm in waves, the white and red, the red and white, forever we'll know
in and of itself, nothing is whole
here at the end of it all I still see...
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st,bst,temp;
char tc;
long n;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
bst=st;
for (int start=0;start<st.size();start++)
{
 temp="";
 for (int i=start;i<st.size();i++)
 {
  tc=st[i]-st[start]+'0';
  if (tc<'0')tc+=10;
  temp+=tc;
 }
 for (int i=0;i<start;i++)
 {
  tc=st[i]-st[start]+'0';
  if (tc<'0')tc+=10;
  temp+=tc;
 }
 if (temp<bst)bst=temp;
}
cout<<bst<<endl;

cin.get();cin.get();
return 0;}