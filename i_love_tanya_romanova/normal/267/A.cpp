/*
Harlots of Hell spread your wings
As I penetrate your soul
Feel the fire shoot through your body
As I slip into your throne
Cast aside, do as you will
I care not how you plead
Satan's child now stalks the earth
Born from my demon seed

Hot winds of Hell
Burns, in my wake
Death is what you pray,
Behold, captor of sin

Infernal slaves of manipulation
Captive of my vice
Abandon God, the helpless one
To relieve you of your plight
Subversive action will not help
It will strengthen me
I see decline in your every move
Death your final plea

Hot winds of Hell
Burns, in my wake
Death is what you pray,
Behold, captor of sin

Your skin turns to leather
I ignite your timid blood
You feel my lethal touch
As I grasp your weary soul
I'll take you down into the fire
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
#define bsize 64
#define clone agsdahfaassdg

using namespace std;

long long tests,a,b;
long long solve(long long a,long long b)
{
 if (a==0||b==0)return 0;
 if (a<b)return solve(b,a);
 return a/b+solve(a%b,b);     
}

int main(){
//freopen("mammoth.in","r",stdin);
//freopen("mammoth.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
    cin>>a>>b;
    cout<<solve(a,b)<<endl;
}

cin.get();cin.get();
return 0;}