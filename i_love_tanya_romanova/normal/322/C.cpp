/*
Just can't win for losing, stare 'em in the eye
An ego made for bruising, a heart that you can't buy
If patience is a virtue, let's set out to sin
I'm all worked up in the desert heat, here I go again
I never seem to smile, you'll find me in the dirt
Your lovable reptile, yeah for what it's worth
I'm poison to your happiness, poison to this song
C'mon down, c'mon down to the ground so we can sing along

Plug me in, yeah, now set me free
I got a two fang grip that you should see
All wrapped up down, 'round your leg
Let me loose, I'm a powder keg
I love you

More
Than you can take
Make no mistake
I'm an Electric Rattlesnake
More
Than you can take
A two fang break
Electric Rattlesnake
All curled up, make no mistake
Two fang deep, got skin to break
Plug me in, got to shake and bake
Electric Rattlesnake
More
Than you can take
No mistake
Electric Rattlesnake

I'm ya satisfaction, give ya skin a glow
The number one attraction, apples packed to go
C'mon down the garden, original sin
Got a two fang bite in the overnight, here I go again
All about just living, living this or that
Shake it up and lay it out, the pigs are getting fat
Bite me as I slither, rape me as I bake
Plug me in baby, then turn me on
I'm your Electric Rattlesnake

Snake bite, color my imagination
In a spiral dream, a hallucination
It comes to me with no reservation
I got the taste, do you mind?
Snake bite, color my imagination
Like a spiral dream of illumination
It fills me up like a medication
I got the taste, do you mind, here I go again
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

using namespace std;

long long n,m,shx[1000],shy[10000],tx,ty,fl;
string st;
long long mx,my;


void check(long long x,long long y)
{
     if (x!=0&&mx==0)return;
     if (y!=0&&my==0)return;
//     if (x==0&&mx==0&&y==0&&my==0)fl=1;
     if (mx!=0){
     if (x%mx)return;
     x/=mx;
     }
     
     if (my!=0)
     {if (y%my)return;
     y/=my;
     }
     if (y<0)return;
     if (x<0)return;
     if (my!=0&&mx!=0)
     if (x!=y)return;
     fl=1;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
cin>>st;
for (int i=0;i<st.size();i++)
{
    shx[i+1]=shx[i];shy[i+1]=shy[i];
    if (st[i]=='U')shy[i+1]++;
    if (st[i]=='D')shy[i+1]--;
    if (st[i]=='L')shx[i+1]--;
    if (st[i]=='R')shx[i+1]++;
}

mx=shx[st.size()];
my=shy[st.size()];

for (int i=0;i<=st.size();i++)
{
 tx=n-shx[i];
 ty=m-shy[i];
 check(tx,ty);
}
if (fl)cout<<"Yes"<<endl;
else cout<<"No"<<endl;

cin.get();cin.get();
return 0;}