/*
We are the servants of the only King
He is worthy
Given dominion over everything
He is worthy

We will declare it with one voice
We will stand up and make a holy noise
And make a holy noise

Glory and honor, glory and power
Glory and honor unto the Lamb
Glory and honor, glory forever
Glory and honor unto the Lamb

We offer Him a sacrificial praise
He is worthy
No one among us is above His grace
He is worthy

We will declare it with one voice
He has become the reason we rejoice
The reason we rejoice

Glory and honor, glory and power
Glory and honor unto the Lamb
Glory and honor, glory forever
Glory and honor unto the Lamb

Glory, honor and power
Be to the Lamb of God forever and ever
Glory, honor and power
Be to the Lamb forever

The Son of Heaven who would die for us
He is worthy
Eternal word of God alive in us
He is worthy

We will declare it with one voice
We will declare that we have made our choice
And make a holy noise

Glory and honor, glory and power
Glory and honor unto the Lamb
Glory and honor, glory forever
Glory and honor unto the Lamb

Glory and honor, glory and power
Glory and honor unto the Lamb
Glory and honor, glory forever
Glory and honor unto the Lamb
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

using namespace std;

long calc[3000][100];
string st;
string cur[3000];
long k,tests,id;
char c;
long p;
long dp;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>k;
cin>>st;
for (int i=0;i<st.size();i++)
 for (int j=0;j<k;j++)
  calc[j][st[i]-'a']++;

for (int j=0;j<k;j++)
 cur[j]=st;

cin>>tests;
for (;tests;--tests)
{
 cin>>id>>c;
 p=0;
 while (calc[p][c-'a']<id)
 {
  id-=calc[p][c-'a'];
  ++p;
 }
 dp=0;
 for (int j=0;j<cur[p].size();j++)
 {
  if (cur[p][j]==c){if (id==1)dp=j;--id;}
 }
 --calc[p][c-'a'];
 cur[p].erase(cur[p].begin()+dp);
}

for (int i=0;i<k;i++)
 cout<<cur[i];
cout<<endl;
 
cin.get();cin.get();
return 0;}