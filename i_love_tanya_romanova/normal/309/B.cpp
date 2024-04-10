/*
I'll wait here,
You're crazy,
Those vicious streets are filled with strays,
You should have never gone to Hollywood.

They find you,
To time you,
Say your the best they've ever seen,
You should have never trusted Hollywood.

I wrote you,
And told you,
You were the biggest fish out here,
You should have never gone to Hollywood.

They take you,
And make you,
They look at you in disgusting ways,
You should never trusted Hollywood.

I was standing on the wall,
Feeling ten feet tall,
All you maggots smoking fags on Santa Monica Boulevard,
This is my front page,
This is my new age,
All you bitches put your hands in the air and wave them like you just don't care.

All you maggots smoking fags out there on Sunset Boulevard.

All you bitches put your hands in the air and wave them like you just don't care.

Phoney people come to pray,
Look at all of them beg to stay,
Phoney people come to pray.

(The lines in the letter said, "We have gone to Hackensack")
Look at all of them beg to stay

Phoney people come to pray.

All you maggots smoking fags on Santa Monica Boulevard,
All you maggots smoking fags out there on Sunset Boulevard.
All you maggots smoking fags out there on Hollywood Boulevard.

You should have never trusted Hollywood.
You should have never gone to Hollywood.

All you bitches put your hands in the air and wave them like you just don't care.

You should have never trusted Hollywood.
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
 
#define  INF 100000000
#define eps 1e-11
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

long bst,bp,qpos;
long n,r,c,sz[2000000],rr,span;
long ans[1100000][23];
string st[1100000];
long nlfl,ql;
double explen;

void do_nline(long i)
{
     nlfl=1;
     cout<<endl;
     ql=0;
     explen=sz[i];
}

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>r>>c;

for (int i=1;i<=n;i++)
{cin>>st[i];sz[i]=st[i].size();}

rr=n;

for (int i=n;i;--i)
{
    span+=sz[i]+1;
    if (rr==i)span=sz[i];
    while (span>c){if (rr>i)span-=(sz[rr]+1);else span-=sz[rr];--rr;}
    ans[i][0]=rr;
}
/*
for (int i=1;i<=n;i++)
cout<<i<<" "<<st[i]<<" "<<ans[i][0]<<endl;
*/

for (int pw=0;pw<=22;pw++)
ans[n+1][pw]=n;

for (long pw=1;pw<=22;pw++)
for (long i=n;i>=1;--i)
ans[i][pw]=max(i-1,ans[ans[i][pw-1]+1][pw-1]);


bst=-1000;
bp=0;
for (int i=1;i<=n;i++)
{
    qpos=i-1;
    for (int pw=20;pw>=0;--pw)
    if (r&(1<<pw))qpos=ans[qpos+1][pw];
    span=qpos-i+1;
    if (span>bst)
    {bst=span;bp=i;}
    }

//cout<<bst<<endl;

ql=0;
nlfl=1;

for (int i=bp;i<bp+bst;i++)
{
 explen=ql+sz[i];
 if (i>bp)explen++;
 
  if (explen>c)
 {
  do_nline(i);          
 }   
 
 if (nlfl==0)cout<<" ";
 cout<<st[i];
 nlfl=0;ql=explen;
}

cout<<endl;

cin.get();cin.get();
return 0;}