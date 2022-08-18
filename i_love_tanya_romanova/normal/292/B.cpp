/*
Hey
I'm your life
I'm the one who takes you there
Hey
I'm your life
I'm the one who cares
They
They betray
I'm your only true friend now
They
They'll betray
I'm forever there

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true

You
You're my mask
You're my cover, my shelter
You
You're my mask
You're the one who's blamed
Do
Do my work
Do my dirty work, scapegoat
Do
Do my deeds
For you're the one who's shamed

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true

Hate
I'm your hate
I'm your hate when you want love
Pay
Pay the price
Pay, for nothing's fair

Hey
I'm your life
I'm the one who took you there
Hey
I'm your life
And I no longer care

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your truth, telling lies
I'm your reasoned alibis
I'm inside open your eyes
I'm you

Sad But True
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
#define eps 1e-5
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

long long a,b,deg[300000],c1,c2,c3,n,m;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    deg[a]++;
    deg[b]++;
}

for (int i=1;i<=n;i++)
if (deg[i]==1){c1++;}
else if (deg[i]>2)c2++;

if (c1==2&&c2==0)cout<<"bus topology"<<endl;
else if (c1==0&&c2==0)cout<<"ring topology"<<endl;
else if (c1==n-1&&c2==1)cout<<"star topology"<<endl;
else cout<<"unknown topology"<<endl;

cin.get();cin.get();
return 0;}