/*
I hear, I speak, counted the words all of my life
I see, I dream, if world's a womb, I'd be the knife
I run, I flee, your fingers just won't leave my head
I hear you speak for those I left for dead

I hear, I speak, the tongues are forked, the ears distort
I see, I dream, your world's a horde against my fort
I run, I flee, the vermin stalk within my walls
I hear them speak, their dirt within my halls

Mother help your undead son
Let go of your undead son
Mother help your undead son
Let me go, undead son, oh

I walk, I'm dead, I'm slowly eaten from inside
I walk this walk, been walking since I died

Mother help your undead son
Let go of your undead son
Mother help your undead son
Let me go, undead son
Undead son

Mother help your undead son
Let go of your undead son
Mother help your undead son
Let me go, undead son

Mother help your undead son
Mother help your undead son
Let go of your undead son
Mother help your undead son

Mother help your undead son
Undead son, undead son, undead son
Mother help your undead son
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
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long QR[33][33] =
    {
    1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,0,1,0,1,0,0,1,1,1,1,1,1,1,
    1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1,0,0,0,0,0,1,
    1,0,1,1,1,0,1,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,0,0,0,1,0,1,1,1,0,1,
    1,0,1,1,1,0,1,0,1,0,1,1,0,0,1,0,0,1,1,1,1,1,0,1,0,0,1,0,1,1,1,0,1,
    1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,1,0,1,0,1,1,1,0,1,
    1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,
    1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,
    1,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,0,0,1,
    1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,0,0,
    0,1,1,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,1,0,
    0,1,1,1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,1,0,0,1,0,1,1,0,0,0,
    1,1,1,0,0,0,0,1,0,1,1,1,0,1,0,0,1,1,0,1,0,0,1,1,0,1,0,1,0,0,1,0,0,
    1,0,1,0,1,0,1,0,0,0,1,0,1,1,0,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,
    1,0,1,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,
    0,0,0,0,1,0,1,0,0,0,1,1,0,0,1,1,0,1,0,0,0,1,1,1,1,0,1,0,1,1,0,1,0,
    1,0,1,0,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,0,
    1,0,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1,0,0,0,0,1,1,1,0,0,0,1,0,0,0,
    0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,
    0,0,1,1,0,1,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,0,0,
    0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,0,0,0,1,1,1,1,0,1,0,1,0,1,0,0,1,1,0,
    1,1,1,0,1,0,1,0,0,1,1,0,0,1,1,1,0,1,0,0,1,1,0,1,0,0,0,0,0,1,1,1,0,
    1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,1,1,1,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,
    0,0,1,0,0,0,1,1,1,0,1,1,1,0,0,0,0,1,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,
    0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,0,
    1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,1,1,0,1,0,1,0,1,1,0,1,0,
    1,0,0,0,0,0,1,0,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,0,1,0,0,0,1,1,0,1,1,
    1,0,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,0,0,0,
    1,0,1,1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,0,1,0,1,1,1,1,1,1,0,1,1,0,1,0,
    1,0,1,1,1,0,1,0,0,1,0,0,0,1,1,0,1,1,1,1,0,1,1,0,1,0,1,1,1,0,0,0,0,
    1,0,0,0,0,0,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,
    1,1,1,1,1,1,1,0,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,0,0,1
    };
    
int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

long i,j;
cin>>i>>j;
cout<<QR[i][j]<<endl;

cin.get();cin.get();
return 0;}