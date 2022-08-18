/*
I don't know how I'll get through this
What's even happening?
What did they find?

My mother's scared to say a word
My son screams silently
We're out of time

And I cannot accept this now
You say there's nothing that I can do
To be the one to lead you through

And I fall shattering my knees
You're the only one that I see
You're the only one who knows me

I pull you gently close to me
Lay your head down slow
I'm here I say

Your body is growing tired
The wind blows quietly
For you I pray

And I stare straight into your eyes
Tell you there's nothing you should fear
I promise your path will be clear

I sing you a lullaby
Fast spirits never die
Together you and I will fly

I'll keep you safe
Safe inside my rib cage
I'll keep you safe
Safe inside my
Safe inside my
Safe inside my
Rib cage

I'll keep you safe
Safe inside my rib cage
I, I, I, I'll keep you safe
Safe inside my rib cage
I'll keep you safe
Safe inside my
Safe inside my
Safe inside my
Rib cage
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
long n;
long v1,v2;
vector<long> g[1<<20],gr[1<<20];
vector<long> start,finish;
vector<long> ans;
char bev(int x)
{
 if (x<26)
  return x+'a';
 if (x<52)
  return x-26+'A';
 return x-52+'0';
}


long gett(char x)
{
 if (x>='a'&&x<='z')
  return x-'a';
 if (x>='A'&&x<='Z')
  return x-'A'+26;
 return x-'0'+52;
}

long eval(char a,char b)
{
 return gett(a)*62+gett(b); 
}

long ptr[1<<20];

void dfs(long v)
{
 if(v<0||v>=62*62)
  while (true);
// cout<<v<<"  "<<bev(v/62)<<" "<<bev(v%62)<<endl;
 
 for (;ptr[v]<g[v].size();)
 {
  long id=g[v][ptr[v]];
  ++ptr[v];
  dfs(id);
 }
 ans.push_back(v);
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<62*62;i++)
{
    int id=i%62;
    if (bev(id)=='>')
     while(true);
}
cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>st;
 v1=eval(st[0],st[1]);
 v2=eval(st[1],st[2]);
 g[v1].push_back(v2);
 gr[v2].push_back(v1);
}

for (int i=0;i<62*62;i++)
{
 if (g[i].size()==gr[i].size())continue;
 if (g[i].size()==gr[i].size()+1){start.push_back(i);continue;}
 if (g[i].size()+1==gr[i].size()){finish.push_back(i);continue;}
 cout<<"NO"<<endl;
 return 0;   
}

if (start.size()>1)
{
 cout<<"NO"<<endl;
 return 0;
}

if (start.size()==0)
{
 for (int i=0;i<62*62;i++)
  if (g[i].size())
   start.push_back(i);
}

//ans.push_back(bev(start[0]%62));

dfs(start[0]);
//ans.push_back(bev(start[0]/62));

reverse(ans.begin(),ans.end());

if (ans.size()!=n+1)
cout<<"NO"<<endl;
else
{
    cout<<"YES"<<endl;
    cout<<bev(ans[0]/62)<<bev(ans[0]%62);
    for (int i=1;i<ans.size();i++)
     cout<<bev(ans[i]%62);
    cout<<endl;
}

cin.get();cin.get();
return 0;}