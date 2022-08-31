/*
Head down running from the beast
Breakneck speed taking all my breath
Black feet scraped and scarred and dripping blood
Rain come down take me with your flood

I came to and I was running from you
Feel your breath on the back of my neck

Where have I come to be
Is this all thats left for me

I wish that I was still there
I want to keep on breathing

Bulls roar loud
Snakes move past my feet
No teeth no hands set me free
Bones start rattling round inside my head
I dont know if Im alive or dead

Where have I come to be
Is this all thats left for me

I wish that I was still there
I want to keep on breathing

Dig deep kicking up rock and dirt and sand
Out of this lifeless valley bones in hand
Over these mountains to the seas of life
Leave this desert for the sick and damned
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,ar[200000],mx,t,fdeg;

long gcd(long a,long b)
{
     while (a&&b){a>b?a%=b:b%=a;}
     return a+b;
} 
int main(){
//freopen("police.in","r",stdin);
//freopen("police.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    mx=max(mx,ar[i]);
}

t=ar[1];
for (int i=1;i<=n;i++)
t=gcd(t,ar[i]);

fdeg=mx/t;
fdeg-=n;
if (fdeg%2)cout<<"Alice"<<endl;
else cout<<"Bob"<<endl;

cin.get();cin.get();
return 0;}