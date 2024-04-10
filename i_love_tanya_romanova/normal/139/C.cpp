/*
This is no ordinary demon
I've been down this road before
Driven by the wounds I couldn't hide
I know exactly where it goes
So I guess there's no tomorrow
And I can't remember yesterday
Locked in a time lapse
And it's soul crushing to say

At the end of my elbow
You'll find one golden rule
A ferocious discharge
You will hit the ground hard

I don't know, I don't care
And I don't understand
Why they dignify iniquity
I don't know, I don't care
And I don't understand
Why they justify rapacity

Left humanity behind long ago
Take a look into my world
So many places where I don't belong
Eradicate what I've become

A ferocious discharge
You will hit the ground hard

I don't know, I don't care
And I don't understand
Why they dignify iniquity
I don't know, I don't care
And I don't understand
Why they justify rapacity
I don't know, I don't care
And I don't understand
There's an oven waiting for you in hell
You'll be reaping what you sow in life
What you sow in life
What you sow in life

Had to put you in the place
And wipe that smile off your face
You can put a king's cloths on a scarecrow
In the end it's still just a scarecrow
Still just a scarecrow

I don't know, I don't care
And I don't understand
Why they dignify iniquity
I don't know, I don't care
And I don't understand
Why they justify rapacity
I don't know, I don't care
And I don't understand
There's an oven waiting for you in hell
You'll be reaping what you sow in life
What you sow in life
What you sow in life

You're the affliction
You'll pay what you owe

Don't understand
You're the affliction
Why they justify
You'll pay what you owe

Don't understand
You're the affliction
Why they dignify
You'll pay what you owe

Don't understand
You're the affliction
Why they justify
You'll pay what you owe

Don't understand
You're the affliction
Why they dignify
You'll pay what you owe
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

long abab,abba,aabb,n,k;
string st[1000];
string suf[1000];

bool nice(char c)
{
 if(c=='a')
  return true;
 if (c=='e'||c=='o'||c=='i'||c=='u')
  return true;
 return false;
}

string gett(string st,long k)
{
 string temp="";
 for (int i=st.size();i+1;--i)
 {
  if (nice(st[i]))--k;
  temp+=st[i];
  if (k==0)break;
 }
 if (k)
 {
  for (int i=0;i<=10;i++)
   temp+=rand();
 }
 reverse(temp.begin(),temp.end());
 return temp;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

abab=abba=aabb=1;
cin>>n>>k;
for (;n;--n)
{
 for (int i=1;i<=4;i++)
 {
  cin>>st[i];
 }
 for (int i=1;i<=4;i++)
 {
  suf[i]=gett(st[i],k);
 }
 if (suf[1]!=suf[2]||suf[3]!=suf[4])
  aabb=0;
 if (suf[1]!=suf[3]||suf[2]!=suf[4])
  abab=0;
 if (suf[1]!=suf[4]||suf[2]!=suf[3])
  abba=0;
}

if (abab&&abba&&aabb)
 cout<<"aaaa"<<endl;
else if (abab)
 cout<<"abab"<<endl;
 else if (abba)
  cout<<"abba"<<endl;
  else if (aabb)
   cout<<"aabb"<<endl;
   else cout<<"NO"<<endl;
   
cin.get();cin.get();
return 0;}