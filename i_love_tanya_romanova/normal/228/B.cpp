/*
Waves of chaos all around
The birth of new religion
Rise from the underground
Empower enslave
Insurrection breaking down
In dark and brutal vision
Symphonic violent sound
The symbol is raised

This is nouveau supremacy
A neo nightmare
The wolf is rising from its lair
There is no turning back

The code is black
The code is black
Rise
This is the new world order

Pulling on the strings of hate
Sadistic revolution
Crushing subhuman faith
Objective engaged
Killing becomes industry
Defining resolution
War on impurity
Relentless campaign

This is nouveau supremacy
A neo nightmare
The wolf is rising from its lair
There is no turning back

The code is black
The code is black
Rise
This is the new world order

Death become the weak
Only strong will survive
Machine like propaganda
Fills a nation with pride
Hatred never seen
In the speeches of peace
From the designers of a dream
Only hell can unleash
Soldiers of the storm
Shock, divide and deploy
Elitist special forces
Operate and destroy
The sacrificial lamb
At the jaws of a beast
Total destruction of a kind
And religious belief

This is nouveau supremacy
A neo nightmare
The wolf is rising from its lair
There is no turning back

The code is black
The code is black
Rise
This is the new world order
The code is black
Rise
The code is black
The code, the code is black
The code, the code is black
The code, the code is black
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n1,m1,m2,n2,ans,shi,shj;
char ar1[400][400],ar2[300][300];
long ov;

int main(){
//freopen("galaxy.in","r",stdin);
//freopen("galaxy.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n1>>m1;
for (int i=1;i<=n1;i++)
for (int j=1;j<=m1;j++)
cin>>ar1[i][j];

cin>>n2>>m2;
for (int i=1;i<=n2;i++)
for (int j=1;j<=m2;j++)
{
 cin>>ar2[i][j];   
}

ans=-100;

for (int sh1=-100;sh1<=100;sh1++)
for (int sh2=-100;sh2<=100;sh2++)
{
    ov=0;
    for (int i=1;i<=n1;i++)
    for (int j=1;j<=m1;j++)
    {
        if (ar1[i][j]=='0')continue;
        if (i+sh1>0&&i+sh1<=n2)
        if (j+sh2>0&&j+sh2<=m2)
        if (ar2[i+sh1][j+sh2]=='1')++ov;
    }
    if (ov>ans)
    {
     ans=ov;shi=sh1;shj=sh2;
    }
}

//cout<<ans<<endl;
cout<<shi<<" "<<shj<<endl;

cin.get();cin.get();
return 0;}