/*
Destiny, feel disgrace.
I'm the one that's fallen.
I'm the one in pain.
I'm the one that's going.
Forces decay in pain, by the light.

The suffer is cold.
There's colors
Searing his face.

Drifting through the sorrow.
The visions yet display.
It strips the soul completely empty.
Sirens rage in vain.

Drifting through the sadness.
Violence fills the sky.
Torturing, the voice rang out.
My servants they are blind, by the light.

Suffer is cold.
There's colors
Searing his face.
By the light.
By the light.
By the light.
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

long r1,r2,c1,c2;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>r1>>c1>>r2>>c2;

if (r1==r2||c1==c2)cout<<1;
else cout<<2;
cout<<" ";
if (r1+c1==r2+c2||r1-c1==r2-c2)
cout<<1;
else if ((r1+c1)%2==(r2+c2)%2)cout<<2;
else cout<<0;
cout<<" ";
cout<<max(abs(r1-r2),abs(c1-c2))<<endl;

cin.get();cin.get();
return 0;}