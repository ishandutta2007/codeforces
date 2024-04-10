/*
Once upon a time I was the scribe of all my dreams
Ive seen the years turn into dust, now feel the rust in me
Ive walked the shores of Avalon, Ive seen the seasons change
Ive laughed and cried, Ive lived and died, but only on the page

Now all I have, all I am
All I ever was is here, on the page
Its all the same, it never mattered anyway
Its all a lie so let it burn

All empty words and all rhymes will fade
As the light of last candle flickers away
If the story is over, this chapter my last
Let it be my best one, let it be my own

I hope its not too late to learn to live and learn to love
I yearn to fight, to turn the tide before the tender dark
For I never drew the sword from stone, theres no Helen in my Troy
I stand alone, I stand forgotten, just gazing into the void

Come night, test my will, test my soul
Test my faith and test my heart, torn apart
Make me strong, make me whole again and
Guide through the dark til the morning comes

All empty words and all rhymes will fade
As the light of last candle flickers away
If the story is over, this chapter my last
Let it be my best one, let it be my own
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256
#define clone agsdahfaassdg

using namespace std;

long long n,m,ar[200000],s,bst,pre,temp;

long long son[5300000][2],valu[5300000]; long d[5300000];
bool hmove[5300000][2];
long long tvert;

void add(long long val,long long vert)
{
// cout<<val<<" "<<vert<<" "<<d[vert]<<endl;
// cin.get();
 if (d[vert]==0)return;
 long temp;
 if (val&(1ll<<(d[vert]-1)))temp=1;
 else temp=0;
 if (hmove[vert][temp])
 {
  add(val,son[vert][temp]);
 }
 else
 {
  hmove[vert][temp]=1;
  son[vert][temp]=tvert+1;
  ++tvert;
  d[tvert]=d[vert]-1;
  valu[tvert]=valu[vert]+temp*(1ll<<d[tvert]);
  add(val,tvert);
 }
}

long long gett(long long val,long long vert)
{
 if (d[vert]==0)return valu[vert];
 long temp;
 if (val&(1ll<<(d[vert]-1)))temp=1;
  else temp=0;
 if (hmove[vert][temp])return gett(val,son[vert][temp]);
 else return gett(val,son[vert][1^temp]);
}

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

d[0]=43;

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    s^=ar[i];
}

bst=0;

pre=s;

add(0,0);

for (int i=n;i+1;--i)
{
 temp=((1ll<<42)-1)^pre;
 
 m=gett(temp,0);
 if ((m^pre)>bst)
 {
  bst=(m^pre);
 }   
 pre^=ar[i];
 temp=s^pre;
 add(temp,0);
}

cout<<bst<<endl;

cin.get();cin.get();
return 0;}