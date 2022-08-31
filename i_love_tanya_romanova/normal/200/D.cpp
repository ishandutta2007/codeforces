/*
Black clouds on the horizon
Great thunder and burning rain
His chariot pounding, I heard the heavens scream his name

I watched as he shouted
To the giants that died that day
He held up his hammer high and called Odin for a sign

Thor the mighty, Thor the brave
Crush the infidels in your way
By your hammer let none be saved
Live to die on that final day
Gods, monsters and men
We'll die together in the end

God of thunder, God of rain
Earth shaker who feels no pain
The powerhead of the universe
Now send your never ending curse

I watched as he shouted
To the giants that died that day
He held up his hammer high and called Odin for a sign

Thor the mighty, Thor the brave
Crush the infidels in your way
By your hammer let none be saved
Live to die on that final day
Gods, monsters and men
We'll die together in the end

Swing your hammer to crack the sky
Lift your cape so that you might fly
Back to Odin and gods on high
And leave this mortal world

Thor the mighty, Thor the brave
Crush the infidels in your way
By your hammer let none be saved
Live to die on that final day
Gods, monsters and men
We'll die together in the end
Odin
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
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
vector<string> tvec;
map<string, string> mapp;
vector<vector<string> > v;
long m;
long qu;
string st1;

vector<string> parse(string st)
{
 vector<string> r;
 string temp;
 for (int i=0;i<st.size();i++)
 {
  if (st[i]==' '||st[i]==','||st[i]=='('||st[i]==')')
  {if (temp.size())r.push_back(temp);temp="";}
  else temp+=st[i];
 }
 return r;
}

int main(){
//freopen("keeper.in","r",stdin);
//freopen("keeper.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
getline(cin,st);

for (int i=1;i<=n;i++)
{
    getline(cin,st);
    tvec=parse(st);
    tvec.erase(tvec.begin());
    v.push_back(tvec);
}

cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>st;
 cin>>st1;
 mapp[st1]=st;   
}

cin>>qu;
getline(cin,st);
for (;qu;--qu)
{
    long ans=0;
 getline(cin,st);
 tvec=parse(st);
 for (int i=1;i<tvec.size();i++)
 {tvec[i]=mapp[tvec[i]];}
 for (int i=0;i<n;i++)
 {
  long flag=0;
  if (v[i].size()!=tvec.size())flag=1;
  if (flag==0)
   for (int j=0;j<tvec.size();j++)
   {
    if (tvec[j]!=v[i][j]&&v[i][j]!="T")flag=1;
   }
   if (flag==0)++ans;
 }
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}