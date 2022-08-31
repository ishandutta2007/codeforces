/*
You were born, your brother's keeper
Why can I see blood on your hands?
You became your brother's slayer
Embrace again in death

At the end of all this hatred lies even deeper hate
Their darkness has defeated you
Your lifeline running backwards

Remember sins of our fathers
A requiem for the countless dead
Blood is on your hands, the wages of sin

Future's eyes closing now
Soul eclipse taking place
Laments rise, tears of the dead
From the other side of the grave

You were born your brothers keeper
Why can I see blood on your hands?
Their darkness has defeated you
Your lifeline running backwards

Remember sins of our fathers
A requiem for the countless dead
Blood is on your hands, the wages of sin

Future's eyes closing now
Soul eclipse taking place
Laments rise, tears of the dead
From the other side of the grave
From the other side of the grave

Blood is on your hands
The wages of sin
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

string st[1000];
long n;
long arp[60][60][60][60];
long ans;

long gp(string st)
{
 if (st=="  ")return 53;
 long r=0;
 if (st[1]=='D')r=13;
 if (st[1]=='H')r=26;
 if (st[1]=='C')r=39;
 if (st[0]<='9')r+=st[0]-50;
 else if (st[0]=='A')r+=12;
 else if (st[0]=='K')r+=11;
 else if (st[0]=='Q')r+=10;
 else if (st[0]=='J')r+=9;
 else if (st[0]=='T')r+=8;
 return r;
}

long gf(string st)
{long r=0;
for (int i=0;i<st.size();i++)
if (st[i]!=' ')++r;
return r;}

void dfs(long sz,string st1,string st2,string st3)
{
  //   cout<<sz<<" "<<st1<<" "<<st2<<" "<<st3<<endl;
 string st0;long nsz;
 
 if (sz==0&&gf(st1)+gf(st2)+gf(st3)==2)ans=1;
 arp[sz][gp(st1)][gp(st2)][gp(st3)]=1;
 
 if (sz<=0)st0="  ";
 else st0=st[sz];
 //cout<<st0<<endl;
 
 if (sz>0)nsz=sz-1;
 else nsz=0;
 
 if (st3[0]==st0[0]||st3[1]==st0[1])
 if (arp[nsz][gp(st3)][gp(st1)][gp(st2)]==0)
 {dfs(nsz,st3,st1,st2);
 }
 if (st3[0]==st2[0]||st3[1]==st2[1])
 if (arp[nsz][gp(st0)][gp(st1)][gp(st3)]==0)
 {dfs(nsz,st0,st1,st3);
 }
}

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

string temp;
//while (cin>>temp)cout<<gp(temp)<<endl;

cin>>n;
for (int i=1;i<=n;i++)
cin>>st[i];
if (n==1)ans=1;
else if (n==2)dfs(0,"  ",st[1],st[2]);
else
dfs(n-3,st[n-2],st[n-1],st[n]);

if (ans)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}