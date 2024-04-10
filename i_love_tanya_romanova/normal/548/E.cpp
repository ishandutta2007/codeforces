/*
I used to be the kinda guy
Who never let you look inside
I'd smile when I was crying

I had nothing but a lot to lose
Thought I had a lot to prove
Lived my life theres no denying

Goodbye to all my yesterdays
Goodbye so long
I'm on my way

I've had enough of crying
Bleeding sweating dieing
Hear me when I say
Gonna live my life
Everyday

I'm gonna touch the sky
I spread these wings and fly
I ain't here to play
Gonna live my life
Everyday

Change everybody's feeling strange
Never gonna be the same
Makes you wonder how the world keeps turning

Life, learning how to live my life
Learning how to pick my fights
Take my shots while I'm still burning

Goodbye to all those rainy nights
Goodbye so long
I'm moving on

I've had enough of crying
Bleeding sweating dieing
Hear me when I say
Gonna live my life
Everyday

I'm gonna touch the sky
I spread these wings and fly
I ain't here to play
Gonna live my life
Everyday

Hit the gas take the wheel
I just made myself a deal
There ain't nothing gonna get in my way
Everyday

Goodbye so long
I'm moving on

I've had enough of crying
Bleeding sweating dieing
Hear me when I say
Gonna live my life
Everyday

I'm gonna touch the sky
I spread these wings and fly
I ain't here to play
Gonna live my life
Everyday

I, oh I, oh I
I'm gonna live my life everyday
I, oh I, oh I
I'm gonna live my life everyday
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

using namespace std;

long long pairs;
int trash[1<<20],n,tests;
int pr[1<<20];
vector<int> divs[1<<20];
int mob[1<<20];
int have[1<<20];
int value;
int cnt;
int ttl[1<<20];

int gcd(int a,int b)
{
    while (a&&b)a>b?a%=b:b%=a;
    return a+b;
}

void add(int x)
{
    cnt++;
    for (int i=0;i<divs[x].size();i++)
    {
        int q=divs[x][i];
        if (mob[q]==0)continue;
        pairs+=mob[q]*ttl[q];
    }
    for (int i=0;i<divs[x].size();i++)
    {
        int q=divs[x][i];
        ttl[q]++;
    }
}
void remove(int x)
{
    cnt--;
    
    for (int i=0;i<divs[x].size();i++)
    {
        int q=divs[x][i];
        ttl[q]--;
    }
    for (int i=0;i<divs[x].size();i++)
    {
        int q=divs[x][i];
        if (mob[q]==0)continue;
        pairs-=mob[q]*ttl[q];
    }
}

int brute()
{
    int res=0;/*
    for (int i=1;i<=6;i++)
     cout<<ttl[i]<<" ";
    cout<<endl;*/
    for (int i=1;i<n;i++)
     for (int j=i+1;j<=n;j++)
      if (have[i]==1&&have[j]==1&&gcd(trash[i],trash[j])==1)
       ++res;
    return res;
}
int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>tests;
for (int i=1;i<=n;i++)
{
    cin>>trash[i];
}

for (int i=2;i<=500000;i++)
{
    for (int j=i;j<=500000;j+=i)
     divs[j].push_back(i);  
}

pr[1]=1;
for (int i=1;i<=500000;i++)
 mob[i]=-1;
 
for (int i=2;i<=500000;i++)
{
    if (pr[i])continue;
    if (pr[i]==0)
     for (int j=i*2;j<=500000;j+=i)
     {
        pr[j]=1;
     }
    for (int j=i;j<=500000;j+=i)
     mob[j]*=-1;
}

for (int i=2;i<=1000;i++)
for (int j=i*i;j<=1000000;j+=i*i)
 mob[j]=0;
/*
for (int i=1;i<=20;i++)
 cout<<i<<" "<<mob[i]<<endl;
 */
/*
for (int i=1;i<=10;i++)
 cout<<mob[i]<<" ";
 cout<<endl;
 */
for (;tests;--tests)
{
    cin>>value;
    if (have[value]==0)
        {have[value]=1;add(trash[value]);}
    else
        {have[value]=0;remove(trash[value]);}
    cout<<1ll*cnt*(cnt-1)/2-pairs<<"\n";
//  cout<<brute()<<endl;
}

//cin.get();cin.get();
return 0;}