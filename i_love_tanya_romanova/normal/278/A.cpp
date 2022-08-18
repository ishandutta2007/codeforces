/*
Welcome to our fortress tall
Take some time to show you around
Impossible to break these walls
For you see the steel is much too strong
Computer banks to rule the world
Instruments to sight the stars

Possibly I've seen too much
Hangar 18 I know too much.

Foreign life forms inventory
Suspended State of cryogenics
Selective amnesia's the story
Believed foretold but who'd suspect
The military intelligence
Two words combined that can't make sense

Possibly I've seen too much
Hangar 18 I know too much.
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

long n,d[200000],s,a,b,t;

int main(){
//freopen("knight.in","r",stdin);
//freopen("knight.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>d[i];
    s+=d[i];
}
cin>>a>>b;
if (a>b)swap(a,b);

for (int i=a;i<b;i++)
t+=d[i];
cout<<min(t,s-t)<<endl;

cin.get();cin.get();
return 0;}