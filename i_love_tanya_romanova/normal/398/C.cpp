/*
Just a word all it takes to set it off
Uncontrolled all restraint has been lost

Absorbing more than I can stand
Of these self defeating unreal demands
Giving into frustrations command
The devil makes good use with idle hands

Overwhelming desire to react
I am too far gone forever turning back
Searching for something to lash out at
Turning inward it is myself that I attack

The anger grows inside everyday
Unquenchable I have become my own prey

From where has this rage been spawned?
Been building deep inside for far too long
Forgotten memories buried and hidden
Creating my own emotional prison

Overwhelming desire to react
I am too far gone forever turning back
Searching for something to lash out at
Turning inward it is myself that I attack

Can it be that I have lost
Control of my contractions and my thoughts?
Can it be that I have lost
Control of my contractions and my thoughts?

Overwhelming desire to react
I am too far gone forever turning back
Searching for something to lash out at
Turning inward it is myself that I attack

It is myself, I attack
It is myself, I attack
It is myself, I attack
It is myself that I attack
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bsize 256

using namespace std;

long n;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
if (n!=5)
{
 for (int i=1;i<=n/2;i++)
 cout<<i<<" "<<i+n/2<<" "<<1<<endl;
 for (int i=n/2+1;i<n;i++)
 cout<<i<<" "<<i+1<<" "<<2*i-n-1+n%2<<endl;
 for (int i=1;i<n/2;i++)
 cout<<i<<" "<<i+1<<endl;
 cout<<1<<" "<<3<<endl;
}
if (n==5)
{
 cout<<"1 2 3"<<endl;
 cout<<"2 4 2"<<endl;
 cout<<"4 5 1"<<endl;
 cout<<"1 3 3"<<endl;
 cout<<"3 4"<<endl;
 cout<<"3 5"<<endl;
}
cin.get();cin.get();
return 0;}