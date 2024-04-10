/*
Living and dying laughing and crying
Once you have seen it you will never be the same
Life in the fast lane is just how it seems
Hard and it's heavy, it's dirty and mean

Motorbreath
It's how I live my life
I can't take it any other way
Motorbreath
The sign of living fast
It is going to take
Your breath away

Don't stop for nothing it's full speed or nothing
I am taking down you know whatever is in my way
Getting your kicks as you are shooting the line
Sending the shivers up and down your spine

Motorbreath
It's how I live my life
I can't take it any other way
Motorbreath
The sign of living fast
It is going to take
Your breath away

Those people who tell you not to take chances
They are all missing on what life is about
You only live once so take hold of the chance
Don't end up like others the same song and dance

Motorbreath
It's how I live my life
I can't take it any other way
Motorbreath
The sign of living fast
It is going to take
Your breath away
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

long n;
string st;
long x,y;

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>st;
for (int i=0;i<n/2;i++)
{
    x=i;y=i+n/2;
    if (st[i]=='R'&&st[y]=='L')swap(x,y);
    cout<<x+1<<" "<<y+1<<endl;
}
cin.get();cin.get();
return 0;}