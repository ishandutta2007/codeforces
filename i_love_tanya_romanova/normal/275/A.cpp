/*
This ain't a song for the broken-hearted 
No silent prayer for the faith-departed 
I ain't gonna be just a face in the crowd 
You're gonna hear my voice 
When I shout it out loud 

It's my life 
It's now or never 
I ain't gonna live forever 
I just want to live while I'm alive 
(It's my life) 
My heart is like an open highway 
Like Frankie said 
I did it my way 
I just wanna live while I'm alive 
It's my life 

This is for the ones who stood their ground 
For Tommy and Gina who never backed down 
Tomorrow's getting harder make no mistake 
Luck ain't even lucky 
Got to make your own breaks 

It's my life 
And it's now or never 
I ain't gonna live forever 
I just want to live while I'm alive 
(It's my life) 
My heart is like an open highway 
Like Frankie said 
I did it my way 
I just want to live while I'm alive 
'Cause it's my life 

Better stand tall when they're calling you out 
Don't bend, don't break, baby, don't back down 

It's my life 
And it's now or never 
'Cause I ain't gonna live forever 
I just want to live while I'm alive 
(It's my life) 
My heart is like an open highway 
Like Frankie said 
I did it my way 
I just want to live while I'm alive 

[Chorus:]
It's my life 
And it's now or never 
'Cause I ain't gonna live forever 
I just want to live while I'm alive 
(It's my life) 
My heart is like an open highway 
Like Frankie said 
I did it my way 
I just want to live while I'm alive
'Cause it's my life!
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
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long ar[100][100],r[100][100];

int main(){
//freopen("jumping.in","r",stdin);
//freopen("jumping.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

for (int i=1;i<=3;i++)
for (int j=1;j<=3;j++)
cin>>ar[i][j];

for (int i=1;i<=3;i++)
for (int j=1;j<=3;j++)
r[i][j]=1+ar[i][j]+ar[i-1][j]+ar[i][j-1]+ar[i][j+1]+ar[i+1][j];

for (int i=1;i<=3;i++)
for (int j=1;j<=3;j++)
r[i][j]=r[i][j]%2;
for (int i=1;i<=3;i++)
{for (int j=1;j<=3;j++)
cout<<r[i][j];
cout<<endl;}


cin.get();cin.get();
return 0;}