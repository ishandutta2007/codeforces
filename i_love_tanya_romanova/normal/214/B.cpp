/*
We walk this earth
With fire in our hands
Eye for an eye
We are nemesis

We are with you
Countless vicious souls
Fight, fighting for freedom
United, we stand, we stand

We are a legion
Voice of anarchy
This is revolution
Creating new disorder

We are enemy
Opponent of the system
Crushing hypocrisy
Slaying the philistine

One for all, all for one
We are strong, we are one
One for all, all for one
We are one nemesis

A malicious fever burns
In our heart, in our veins
Your blood, my blood
Our blood runs the same

One for all, all for one
We are strong, we are one
One for all, all for one
We are one nemesis

One for all, all for one
We are strong, we are one
One for all, all for one
We are one nemesis
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

long n,ar[2000000],fl,s,calc[100];

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>ar[i-1];if (ar[i-1]==0)++fl;
calc[ar[i-1]]++;
}
if (fl==0){cout<<-1<<endl;return 0;}

for (int i=0;i<10;i++)
s+=calc[i]*i;
if (s%3==1)
{
           fl=0;
           for (int i=1;i<=9;i++)
           if (i%3==1&&calc[i]>0&&fl==0)
           {
            fl++;calc[i]--;
           }
           if (fl==0)
           {
            for (int i=1;i<=9;i++)
            if (i%3==2)
            while (calc[i]>0&&fl<2){calc[i]--;fl++;
            }
           }
}

if (s%3==2)
{
            fl=0;
           for (int i=1;i<=9;i++)
           if (i%3==2&&calc[i]>0&&fl==0)
           {
            fl++;calc[i]--;
           }
           if (fl==0)
           {
            for (int i=1;i<=9;i++)
            if (i%3==1)
            while (calc[i]>0&&fl<2){calc[i]--;fl++;
            }
           }
}
s=0;
for (int i=1;i<=9;i++)
s+=calc[i];
if (calc[0]>1&&s==0)
{cout<<"0"<<endl;return 0;}
for (int i=9;i>=0;--i)
for (int j=calc[i];j;--j)
cout<<i;
cout<<endl;

cin.get();cin.get();
return 0;}