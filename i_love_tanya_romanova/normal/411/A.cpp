/*
Loads of times on the losing end
It's the same old situation
Just another constellation
Daggers drawn with a steady head
You push the aggravation
To your final destination

Cut me out in card board
Use me as a dartboard
Down at your feet now
How does it feel now

As you get yourself some
Self-esteem and then some
Heed of your own

In your eyes - in your mind
I'm two out of seven
In your eyes - in your life
Just two out of seven

As you watch my world from the outside
You think that your are strong
And you dream that you belong
You're supreme cause
You know how to spell right
You drown in salivation
You set off from frustration

Living on a card board
Use me as a dartboard
I know that lately
Your phrasing's been stately

As you get yourself some
Self-esteem and then some
Heed of your own

In your eyes - in your mind
I'm two out of seven
In your eyes - in your life
Maybe two out of seven
In your eyes - in your mind
I'm three out of ten
Out of nine I'm just fine
I'm only whatever

In your eyes - in your mind
I'm two out of seven
In your eyes - in your life
I'm two out of seven
What the fuck? Suck my cock!
I'm only a seven out of twelve
When I wank at the bank
I'm ten out of ten my friend
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

bool nice()
{
 if (st.size()<5)return false;
 long fl=0;
 for (int i=0;i<st.size();i++)
  if (st[i]>='a'&&st[i]<='z')fl=1;
 if (fl==0)return false;
 fl=0;
 for (int i=0;i<st.size();i++)
  if (st[i]>='A'&&st[i]<='Z')fl=1;
  if (fl==0)return false;
 fl=0;
 for (int i=0;i<st.size();i++)
  if (st[i]>='0'&&st[i]<='9')fl=1;
  if (fl==0)return false;
  return true;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
if (nice())cout<<"Correct"<<endl;
else cout<<"Too weak"<<endl;
cin.get();cin.get();
return 0;}