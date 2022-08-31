/*
I lie here awake.
My lifeless body that's cold feeling the pain.
That's a cry far away.
Why is this prolonged, I've already lived, what's to fear.

Now kill the power, become partners of sin.
Alone in our decision to unlock the door,
And escape from within.
For only death is my life.
Escape from within.

From terminal living, cutting me, low in my prime.
Contract of death, silent screams beg to be signed.
You'll live the life of a saint as you decide,
Mercy kill to turn the tide.

Now kill the power, become partners of sin.
Alone in our decision to unlock the door,
And escape from within.
For only death is my life.
Escape from within.
Escape from within.

From terminal living, through the years I've laid alone.
Tubes through my body, there's no will to carry on.
You'll live the life of a saint as you decide,
Mercy kill to turn the tide.

Now kill the power, become partners of sin.
Alone in our decision to unlock the door,
And escape from within.
For only death is my life.
Escape from within.
Escape from within.
Escape from within.
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

string st;
long p1,p2;

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
if (st[0]=='f')p1=2;
else p1=3;
for (int i=0;i<st.size();i++)
if (st[i]=='r'&&i+1<st.size()&&st[i+1]=='u')
p2=i-1;
for (int i=0;i<=p1;i++)
cout<<st[i];
cout<<"://";
for (int i=p1+1;i<=p2;i++)
cout<<st[i];
cout<<".ru";
if(p2+3<st.size())cout<<"/";
for (int i=p2+3;i<st.size();i++)
cout<<st[i];
cout<<endl;

cin.get();cin.get();
return 0;}