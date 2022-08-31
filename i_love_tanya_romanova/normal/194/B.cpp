/*
What the hell is going on
Skijumpers making music that sells gold
There's no talent in this game
Hunting, hunting for the fame
Publicity is all you need
that's why it feels to me like

Reign of Terror

Everything costs so much nowadays
An individuals vanish in the haze
Entertainment for the masses
saving, saving your own asses
Rats are leaving sinking ship
still it feels to me like

Reign of Terror

What the hell is going on
everything is upside down
Hunting, hunting for the fame
terror, terror everywhere
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

long long tests;
long long n,p;
long long gcd(long long a,long long b)
{
     while (a&&b)a>b?a%=b:b%=a;
     return a+b;
}

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
    cin>>n;
    p=gcd(n+1,4*n);
    cout<<(n+1)*4*n/p/(n+1)+1<<endl;
}
cin.get();cin.get();
return 0;}