/*
We die, we all

Cool night gave my truth for a lie
Will you be here when I try?
I'm not set, cannot do it yet
Will you be here when I try?

Our wealth breeds emptiness
Another day to compress

We die, we all
We die, we all

Lips are dry, you gave me drugs to try
Hold me when I die
The sky has frozen to a wall
We die, we all

Lips are dry, you gave me drugs to try
Hold me when I die
The sky has frozen to a wall
We die, we all

Our wealth breeds emptiness

We die, we all
We die, we all
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
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

string st;
long ev;
long ps;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 if (st[i]%2==0)
  ev=1;
}

if (ev==0)
{
 cout<<-1<<endl;
 return 0;
}

for (int i=0;i<st.size();i++)
{
 if (st[i]<st[st.size()-1]&&st[i]%2==0)
 {
  swap(st[i],st[st.size()-1]);
  cout<<st<<endl;
  return 0;
 }
}

for (int i=st.size()-1;i+1;i--)
{
    if (st[i]%2==0)
    {
     swap(st[i],st[st.size()-1]);
     cout<<st<<endl;
     return 0;
    }
}
cin.get();cin.get();
return 0;}