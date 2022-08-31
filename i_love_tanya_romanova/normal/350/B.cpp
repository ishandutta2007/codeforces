/*
Come faster than the speed of light
Slow goin' the forgiving night
I'm a soldier in the endless war
Chained down to the money whore

I'm counting my days I'm jaded oh I'm gettin' sicker
I'm going astray yeah faded oh I'm gettin' sicker

First last and all in between
Let's give them more hell than they've ever seen
Give them something to remember
Give them how and why and what you're living for
First last and all in between the endless war

Eyes dancin' to a crankin' fit
Blood spillin' in the heart I'm hit
Lord knows I can't remember when
I'll be up before you count to ten

Uncounting my days I'm fading I'm gettin' sicker
I'm going astray yeah jaded oh I'm gettin' sicker

First last and all in between
Let's give them more hell than they've ever seen
Give them something to remember
Give them how and why and what you're living for
First last and all in between the endless war oh oh oh oh

Ooh yeah give me the dream give me the all right
Make it a laser beam spectacular spotlight
Brighter than the sun on a summer day
A wind to chase my clouds away
Oh yeah give me the dream make it be all right all right

Oh yeah give me a shot set me a fire
Burnin' like the sun on a metal cage
A wind that fan the flames of rage
Oh yeah give me a shot set me a fire all right

Oh yeah give me a dream
Oh yeah give me a dream
Oh yeah give me a dream
Oh yeah give me a dream

Come faster than the speed of dead
Slow goin' unforgivin' red
I'm a soldier in the endless war
Unchained by the timeless gore

I'm counting my days got jaded oh I'm gettin' sicker
I'm going astray yeah faded oh I'm gettin' sicker

First last and all in between
Let's give them more hell than they've ever seen
Give them something to remember
Give them how and why and what you're living for
First last and all in between the endless war
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

using namespace std;

long n,tp[200000],q,par[200000],sn[200000];
queue<long> qu;
long arp[200000];
long ss[200000];
long temp,ans;
long ap;
vector<long> answ;

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>tp[i];

for (int i=1;i<=n;i++)
{
    cin>>q;
    par[i]=q;
    ss[q]++;
}

for (int i=1;i<=n;i++)
if (tp[i]==1){qu.push(i);arp[i]=1;}

while (qu.size())
{
    //  cout<<temp<<endl;
 temp=qu.front();
 qu.pop();
 if (par[temp]==0)continue;
 q=par[temp];
 if (ss[q]>1)continue;
 if (arp[q]<arp[temp]+1)
 {
  arp[q]=arp[temp]+1;
  qu.push(q);
  sn[q]=temp;
 }
}

for (int i=1;i<=n;i++)
{if (arp[i]>ans){ap=i;ans=max(ans,arp[i]);}}

for (int i=1;i<=ans;i++)
{answ.push_back(ap);ap=sn[ap];}
cout<<answ.size()<<endl;
//reverse(answ.begin(),answ.end());
for (int i=0;i<answ.size();i++)
{if (i)cout<<" ";cout<<answ[i];}
cout<<endl;

cin.get();cin.get();
return 0;}