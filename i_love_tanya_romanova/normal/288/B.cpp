/*
Maybe one day I'll be an honest man
Up till now I'm doing the best I can
Long roads.Long days, of sunrise, to sunset
Sunrise to sunset

Dream on brothers while you can
Dream on sisters I hope you will find the one
All of our lives, covered up quickly by the tides of time

Spend your days full of emptiness
Spend your years full of loneliness
Wasting love, in a desperate caress
Rolling shadows of night

Dream on brothers while you can
Dream on sisters I hope you will find the one
All of our lives, covered up quickly by the tides of time

Sands are flowing and the lines are in your hand
In your eyes I see the hunger, and the desperate cry that tears the night

Spend your days full of emptiness
Spend your years full of loneliness
Wasting love, in a desperate caress
Rolling shadows of night
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

long long n,r,k;

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
r=1;
for (int i=1;i<=(n-k);i++)
r=r*(n-k)%bs;
for (int i=1;i<=k-1;i++)
{r*=k;r%=bs;}

cout<<r%bs<<endl;

cin.get();cin.get();
return 0;}