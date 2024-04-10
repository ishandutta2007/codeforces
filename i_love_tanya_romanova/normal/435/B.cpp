/*
A distant light was shining
For all these years.
My life was pretty dark,
I had to live with my fears.

All this time it helped me to hold on.
But its becoming useless
So I should let it down

Take it off, burn it all, take the pain away!
Take that mask off your face, are your eyes made of
clay?
Take it off, burn it all, take the pain away!
Stop lying to yourself, you wont face it today.

I finally broke down the walls of my prison,
Constantly exhausted for no good reason.
But I wont complain or open my veins,
A better lifes waiting, where Im now
going!

I never thought it could become obsolete so fast.
This decision was so hard to take, but I made it at
last.
I know it took me so long,
I wasnt strong enough.
I know it took me so long,
To what life do I belong?

Youve never felt this taste:
It is much less sweet than the rest
But you cannot define it.

It fills your mouth and your mind,
It makes you feel like youre going blind.
You cant get rid of it by spitting
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

using namespace std;

string st;
long k;
long fen;

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st>>k;

for (int i=0;i<st.size();i++)
{
 for (int d='9';d>='0';d--)
 {
  fen=1e9;
  for (int j=i;j<st.size();j++)
   if (st[j]==d){fen=j;break;}
  if (fen-i>k)continue;
  for (int j=fen;j>i;j--)
  swap(st[j],st[j-1]);
  k-=(fen-i);
  break;
 }
}
cout<<st<<endl;

cin.get();cin.get();
return 0;}