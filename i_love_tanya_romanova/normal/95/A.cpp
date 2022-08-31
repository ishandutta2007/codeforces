/*
Sometimes there's a time
You must say goodbye
Though it hurts you must learn to try
I know, I've got to let you go

But I know, anywhere you go, you'll never be far
'Cause like the light of a bright star
You'll keep shining in my life
You're gonna be right

Here in my heart, that's where you'll be
You'll be with me, here, here in my heart
No distance can keep us apart
Long as you're here in my heart

Won't be any tears
Falling from these eyes
'Cause when love's true, love never dies
It stays alive forever

Time can't take away what we had
I will remember our time together
You might think our time is through
But I'll still have you

Here in my heart, that's where you'll be
You'll be with me, here in my heart
No distance can keep us apart
Long as you're here in my heart

I know, you'll be back again
And till then, my love is waiting

Here in my heart, that's where you'll be
You'll be with me, here in my heart
No distance can keep us apart
Long as you're here in my heart

Here, here in my heart, that's where you'll be
You'll be with me, here in my heart
No distance can keep us apart
Long as you're here in my heart
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

string z[2000];
string st;
char bl;
long tests,er,bad[2000];

char gett(char x)
{
 if (x>='A'&&x<='Z')
  return x-'A'+'a';
 return x;
}

long flag;
bool upper(char x)
{
 if (x>='A'&&x<='Z')return 1;
 return 0;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (int i=1;i<=tests;i++)
{
 cin>>z[i];
}
cin>>st;
cin>>bl;

for (int i=0;i<st.size();i++)
{
 for (int j=1;j<=tests;j++)
 {
  er=0;
  if (i+z[j].size()>st.size())continue;
  for (int p=0;p<z[j].size();p++)
  {
   if (gett(z[j][p])!=gett(st[i+p]))
    er=1;
  }
  if (er==0)
   for (int p=0;p<z[j].size();p++)
    bad[p+i]=1;
 }
}

for (int i=0;i<st.size();i++)
{
 if (bad[i]==0){cout<<st[i];continue;}
 flag=0;
 if (upper(st[i]))
 {
  st[i]=st[i]-'A'+'a';
  flag=1;
 }
 if (st[i]==bl&&bl=='a')st[i]='b';
 else if (st[i]==bl&&bl!='a')st[i]='a';
 else st[i]=bl;
 if (flag){st[i]=st[i]-'a'+'A';}
 cout<<st[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}