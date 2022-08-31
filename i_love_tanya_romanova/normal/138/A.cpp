/*
My wounds are bleeding my hate for you
I'm sick of your fucking plastic smile.
As I bleed you dry
You lose your shallow eyes
As I bleed you dry
You lose that fakes ass smile
Lose it all.
I've suffered for the last time
Now you're destined to burn in the flames of hell
Condemned to burn in the flames of hell.
My hate is killing you piece by piece
The death of your fucking world is coming.
Prepare to meet your destiny
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