/* 
In your dreams
The pain is so real
Before the dead
You'll have to kneel
Hear your future screams
See your epitaph
As you scream
The dead they laugh

Pain, growing stronger
Life, exists no longer
Welcome, to a world of pain
Death and despair

Denial of life (Vile denial)
Denial of life
Denial of life

Created by your mind
To overtake your life
Sacrificial suicide
End it with a knife
Much too late
To change your mind
A bloody corpse
Is left behind

Pain, growing stronger
Life, exists no longer
Welcome, to a world of pain
Death and despair

Denial of life (Vile denial)
Denial of life
Denial of life
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
#define eps 0.001
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

long n,s,t,p[2000000],fst[1200000];

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>s>>t;
for (int i=1;i<=n;i++)
cin>>p[i];
for (int i=1;i<=n;i++)
fst[i]=-1;
fst[s]=0;

for (int iter=1;iter<=1000000;iter++)
{
 s=p[s];
 if (fst[s]==-1)fst[s]=iter;
}

cout<<fst[t]<<endl;

cin.get();cin.get();
return 0;}