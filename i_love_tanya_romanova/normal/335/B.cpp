/*  
Outta my way, outta my day
Outta your mind and into mine
Into no one, into no one
Into your step but outta time

Head strong, what's wrong?
I've already heard this song
Before... you arrived
But now it's time
To kiss your ass good-bye

*Draggin me down, why you around?
So useless
It ain't my fall, it ain't my call!
It ain't my bitch

Down on the sun, down and no fun
Down and out, where the hell ya been
Damn it all down, damn it unbound
Damn it all down to hell again

Stand tall, can't fall
Never even bend at all
Before... you arrived
But now it's time
To kiss your ass good-bye

[* Repeat]

No way but down, why you around?
No foolin'
It ain't my smile, it ain't my style
It ain't my bitch

Ain't mine, your kind
Your steeping outta time
Ain't mine, your kind
Your steppin outta time

Draggin me down, why you around?
No foolin'
It ain't my fall, it ain't my call
It ain't my...

Bitch... you ain't mine
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

string st;
long n,nxt[100000][30],prev[100000][30],lst[100000],bst[60000][110];
bool has[60000][110];
long a,b,par[60000][110];
long answ;
string res;
long aps;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
/*for (int i=1;i<=105;i++)
st+='a';
*/
n=st.size();

for (int i=0;i<=n;i++)
for (int j=0;j<=26;j++)
{
 nxt[i][j]=n+2;
 prev[i][j]=-100;   
}

    for (int j=0;j<=26;j++)
    lst[j]=n+3;
    
    
for (int i=n-1;i+1;i--)
{
    for (int j=0;j<=26;j++)
    nxt[i][j]=lst[j];
    lst[st[i]-'a']=i;
}

for (int j=0;j<=26;j++)
lst[j]=-2;

for (int i=0;i<n;i++)
{
    for (int j=0;j<=26;j++)
    prev[i][j]=lst[j];
    lst[st[i]-'a']=i;
}

for (int i=0;i<n;i++)
for (int j=0;j<=105;j++)
bst[i][j]=10000000;

for (int i=0;i<n;i++)
{has[i][1]=1;bst[i][1]=i;}

for (int i=0;i<n;i++)
{
 if (nxt[i][st[i]-'a']<n)
 {
  has[i][2]=1;bst[i][2]=nxt[i][st[i]-'a'];
 }    
}

for (int sz=1;sz<=102;sz++)
{
 for (int i=n-1;i>=0;i--)
 if (has[i][sz])
 {
  for (int adl=0;adl<26;adl++)
  {
   a=prev[i][adl];
   b=nxt[bst[i][sz]][adl];
   if (a>=0&&b<n)
   {
   // cout<<a<<" "<<b<<" "<<sz<<" "<<i<<" "<<adl<<endl;
    if (bst[a][sz+2]>b){has[a][sz+2]=1;bst[a][sz+2]=b;par[a][sz+2]=i;}
  }}
 }   
}

for (int i=0;i<=100;i++)
for (int j=0;j<n;j++)
if (has[j][i]){answ=i;aps=j;}
//cout<<answ<<endl;

while (answ>0)
{
 res+=st[aps];
 aps=par[aps][answ];
 answ-=2;     
}
string tres=res;
reverse(tres.begin(),tres.end());
if (answ<0)tres.erase(tres.begin());
res+=tres;
cout<<res<<endl;

cin.get();cin.get();
return 0;}