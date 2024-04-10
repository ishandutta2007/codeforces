/*
Been here before
Been here before couldn't say I liked it
Do I start writing this down?
Just let me plug you into my world
Can't you help me be uncrazy?

Name this for me, heat the cold air
Take the chill off of my life
And if I could I'd turn my eyes
To look inside and see what's comin'

It comes alive, It comes alive, It comes alive
And I die a little more
It comes alive, It comes alive, It comes alive
Each moment here I die a little more

Then the unnamed feeling
It comes alive
The the unnamed feeling
Takes me away

I'm frantic in your soothing arms
I can not sleep in this down filled world
I've found safety in this loneliness
But I can not stand it anymore

Cross my heart hope not to die
Swallow evil, ride the sky
Lose myself in a crowded room
You fool, you fool, it will be here soon

It comes alive, It comes alive, It comes alive
And I die a little more
It comes alive, It comes alive, It comes A-live
Each moment And I die a little more

Then the unnamed feeling
It comes alive
The the unnamed feeling
Treats me this way
And I wait for this train
Toes over the line
And then the unnamed feeling
Takes me away

Get the fuck out of here
I just wanna get the fuck away from Me
I rage, I glaze, I hurt, I hate
I hate it all, why? Why? Why me?

I cannot sleep with a head like this
I wanna cry, I wanna scream
I rage, I glaze, I hurt, I hate
I wanna hate it all away
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

char c[10][10];
long fwin,swin, move,cx,c0;

string solve()
{
 cx=c0=0;
 
 for (int i=1;i<=3;i++)
 for (int j=1;j<=3;j++)
 {
  if (c[i][j]=='X')++cx;
  if (c[i][j]=='0')++c0;   
 }
 if (c0>cx||c0<cx-1)return "illegal";
 if (cx>c0)move=2;
 else move=1;
 
 for (int i=1;i<=3;i++)
 {
     if (c[i][1]==c[i][2]&&c[i][1]==c[i][3]&&c[i][1]=='X')fwin=1;
     if (c[i][1]==c[i][2]&&c[i][1]==c[i][3]&&c[i][1]=='0')swin=1;
 }
 
 for (int i=1;i<=3;i++)
 {
     if (c[1][i]==c[2][i]&&c[1][i]==c[3][i]&&c[1][i]=='X')fwin=1;
     if (c[1][i]==c[2][i]&&c[1][i]==c[3][i]&&c[1][i]=='0')swin=1;
 }
 
 if (c[1][1]==c[2][2]&&c[2][2]==c[3][3]&&c[3][3]=='X')fwin=1;
 if (c[1][1]==c[2][2]&&c[2][2]==c[3][3]&&c[3][3]=='0')swin=1;
 
 if (c[1][3]==c[2][2]&&c[2][2]==c[3][1]&&c[3][1]=='X')fwin=1;
 if (c[1][3]==c[2][2]&&c[2][2]==c[3][1]&&c[3][1]=='0')swin=1;
 
 if (fwin&&swin)return "illegal";
 if (fwin>0&&move==1)return "illegal";
 if (swin>0&&move==2)return "illegal";
 if (fwin)return "the first player won";
 if (swin)return "the second player won";;
 if (cx+c0==9)return "draw";
 if (move==1)return "first";
 return "second";
}

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=3;i++)
for (int j=1;j<=3;j++)
{
 cin>>c[i][j];   
}

cout<<solve()<<endl;

cin.get();cin.get();
return 0;}