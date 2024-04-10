/*
Righteous defamation, dexterity in days of divinity
Sinister gods of destruction and war take over their roll
Obliteration of the sacred force the campaign of propaganda

Banished from this dying world
The campaign of propaganda
Blood soaked enlightenment and brutal crusades
Have been spanned over death and burned amd the stake
Banished from the fortress of this dying world
Force the campaign of propaganda

Banished from this dying world
The campaign of propaganda

Sworn to poverty!
Blood soaked enlightenment and brutal crusades
Have been spanned over death

Burned at the stake!
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

string st1,st2;
long n,m;
long pref[1<<20],suf[1<<20],er;
long s[1<<18][28];
long temp;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1>>st2;

n=st1.size();
m=st2.size();
for (int i=1;i<=m;i++)
{
 for (int j=0;j<26;j++)
 {
  s[i][j]=s[i-1][j]+(st2[i-1]==j+'a');
 }
}

for (int j=0;j<=26;j++)
 s[m+1][j]=s[m][j];
 
for (int i=1;i<=n;i++)
{
 pref[i]=pref[i-1];
 if (pref[i]<m&&st2[pref[i]]==st1[i-1])++pref[i];
}
suf[n+1]=m+1;

for (int i=n;i>=1;--i)
{
 suf[i]=suf[i+1];
 if (suf[i]>1&&st2[suf[i]-2]==st1[i-1])--suf[i];
}

for (int i=1;i<=n;i++)
{
    if (pref[i-1]+1<suf[i+1]-1)
    {
     er=1;break;
    }
  //  cout<<pref[i-1]+1<<" "<<suf[i+1]-2<<endl;
    
    temp=s[pref[i-1]+1][st1[i-1]-'a'];
    if (suf[i+1]>1)temp-=s[suf[i+1]-2][st1[i-1]-'a'];
//cout<<i<<"  "<<temp<<endl;
    if (temp==0)er=1;    
}

if (er)cout<<"No"<<endl;
else cout<<"Yes"<<endl;

cin.get();cin.get();
return 0;}