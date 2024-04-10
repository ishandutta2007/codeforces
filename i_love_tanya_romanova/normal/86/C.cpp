/*
Flames are gushing
The world set free
Nothing will stay
Nothing be the same
War is Hell
Hard on man
Marching on the warriors
As missiles crush the ground

Warfare
Warfare
Hell from the sky
You know you're gonna die
Warfare

Toxic radiation
The sky's turning black
Now the Judgement's done
No one will be back
Thirst for destruction
Kills your gun
Nightmare, holocaust
The war can't be won

Warfare
Warfare
Hell from the sky...

Desolates in Hell
Destruction ends me
Nuclear war
Gone against we
Genocide of man
A nuclear battle
Men of the war
Summoned like cattle

Warfare
Warfare...
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
#define bs 1000000009
#define bsize 256
 
using namespace std;

long n,m;
vector<string> pref;
long mov[500][500];
string temp;
string inp[500];
long er,td;
long bst[2000];
string tst;
long dp[4][500][500];
long nend,t,ncvrd,answ;

void ad(long &a,long b)
{
 a+=b;
 if (a>=bs)a-=bs;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>inp[i];
 for (int j=0;j<inp[i].size();j++)
  inp[i][j]=inp[i][j]-'A'+'a';
}
pref.push_back("");
for (int i=1;i<=m;i++)
{
 temp="";
 for (int j=0;j<inp[i].size();j++)
 {
  temp+=inp[i][j];
  pref.push_back(temp);
 }
}

// mov pclc
for (int i=0;i<pref.size();i++)
{
 bst[i]=-1;
 for (int j=1;j<=m;j++)
 {
  if (inp[j].size()>pref[i].size())continue;
  er=0;
  if (bst[i]>=0&&inp[j].size()<=inp[bst[i]].size())continue;
  td=pref[i].size()-inp[j].size();
  for (int q=0;q<inp[j].size();q++)
   if (pref[i][q+td]!=inp[j][q])
    {er=1;break;}
  if (er==0)
   bst[i]=j;
 }
}

for (int i=0;i<pref.size();i++)
 for (int ad=0;ad<26;ad++)
 {
  mov[i][ad]=-1;
  tst=pref[i];
  tst+=char('a'+ad);
  for (int j=0;j<pref.size();j++)
  {
   if (pref[j].size()>tst.size())continue;
   er=0;
   td=tst.size()-pref[j].size();
   if (mov[i][ad]!=-1&&pref[mov[i][ad]].size()>pref[j].size())continue;
   for (int q=0;q<pref[j].size();q++)
   if (pref[j][q]!=tst[td+q]){er=1;break;}
   if (er==0) mov[i][ad]=j;
  }
 }
/*
for (int i=0;i<pref.size();i++)
 cout<<pref[i]<<endl;

for (int i=0;i<pref.size();i++)
 cout<<mov[i][0]<<" "<<mov[i][1]<<" "<<mov[i][2]<<endl;
 */
 
dp[0][0][0]=1;
for (int i=0;i<n;i++)
 {
  for (int j=0;j<=pref.size();j++)
   for (int q=0;q<=i;q++)
    dp[1-i%2][j][q]=0;
  for (int end=0;end<pref.size();end++)
   for (int cvrd=0;cvrd<=i;cvrd++)
   if (cvrd>=i-25)
   if (dp[i%2][end][cvrd])
    for (int achar=0;achar<26;achar++)
    {
     nend=mov[end][achar];
     t=bst[nend];
     if (t>-1&&inp[t].size()+cvrd>i)
      ncvrd=i+1;
      else ncvrd=cvrd;
     ad(dp[1-i%2][nend][ncvrd],dp[i%2][end][cvrd]);//dp[1-i%2][nend][ncvrd]=(dp[1-i%2][nend][ncvrd]+dp[i%2][end][cvrd])%bs;
    }
 }

answ=0;
for (int end=0;end<pref.size();end++)
 ad(answ,dp[n%2][end][n]);//answ=(answ+dp[n%2][end][n])%bs;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}