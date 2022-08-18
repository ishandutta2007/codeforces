/*
We do what we do 'cause we fucking want to
Never give a shit what others say to you
They try to give advice just to find we're cold as ice
Worthless opinions need not be spoken twice
We're proud of what me do, call us Trash we won't argue
We'll never be ashamed if our children ever knew
Forever we'll confirm and we're flattered by the term
Those embarrassed by it never should have tried it!

With my head held high
Standing dignified
I have my integrity
Never gave an inch
And I never flinch
When it came to my loyalty
100% all out nothing less
Aggressive, relentless and mean
When the chips are down
You'll never see us frown
You'll only see
Trash Under Pressure!

Heavy fuckin' sound , pound your head into the ground
Where others try and fail, we're glory bound
It's what we love to hear, we've done it for so many years
Rolling into town and blowing out your ears
Parents are against, they try and keep their children
Fenced in from the world and the evil influence
Like birds of a feather we'll always flock together
We want you to know we'll always thrash forever!
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
string st;
set<char> set1,set2;
set<char> ::iterator it;
char c1,c2;

bool bad()
{
 it=set1.begin();
 c1=(*it);
 it=set2.begin();
 c2=(*it);
 return (c1==c2);
}
int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>st;
 for (int j=0;j<st.size();j++)
 {
  if (j==i||j+i==st.size()-1)
  set2.insert(st[j]);
  else set1.insert(st[j]);
 }
}

if (set1.size()>1||set2.size()>1||bad())cout<<"NO"<<endl;
else cout<<"YES"<<endl;
 
cin.get();cin.get();
return 0;}