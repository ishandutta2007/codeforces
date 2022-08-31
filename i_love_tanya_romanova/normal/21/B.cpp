/*
In a time when dinosaurs walked the earth
When the land was swamp and caves were home
In an age when prize possession was fire
To search for landscapes men would roam.

Then the tribes they came to steal their fire
And the wolves they howled into the night
As they fought a vicious angry battle
to save the power of warmth and light.

Drawn by Quest for fire
They searched all through the land
Drawn by Quest for fire
Discovery of man.

And they thought that when the embers died away
That the flame of life had burnt and died
Didn't know the sparks that made the fire
Were made by rubbing stick and stone.

So they ploughed through forest and swamps of danger
And they fought the cannibal tribes and beasts
In the search to find another fire
To regain the power of life and heat.

Drawn by Quest for fire
They searched across the land
Drawn by Quest for fire
Discovery of man.
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

long a1,b1,a2,b2,q;
double c1,c2;

long gcd(long a,long b)
{
     a=abs(a);b=abs(b);
     while (a&&b)a>b?a%=b:b%=a;
     return a+b;
}
int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a1>>b1>>c1;
cin>>a2>>b2>>c2;

if (a1<0||(a1==0&&b1<0)){a1=-a1;b1=-b1;c1=-c1;}
if (a2<0||(a2==0&&b2<0)){a2=-a2;b2=-b2;c2=-c2;}
long q=gcd(a1,b1);
//q=gcd(q,c1);
//cout<<q<<endl;
if (q==0)q=1;
a1/=q;b1/=q;c1/=q;
q=gcd(a2,b2);
//q=gcd(q,c2);
if (q==0)q=1;
a2/=q;b2/=q;c2/=q;

if (a1==0&&b1==0&&fabs(c1)<1e-6&&(a2!=0||b2!=0))
cout<<-1<<endl;
else if (a2==0&&b2==0&&fabs(c2)<1e-6&&(a1!=0||b1!=0))
cout<<-1<<endl;
else

if (a1==a2&&b1==b2)
{
 if (a1==0&&a2==0&&b1==0&&b2==0&&fabs(c1)<1e-5&&fabs(c2)<1e-5)
 cout<<-1<<endl;
 else 
 if (fabs(c1-c2)<1e-6&&(a1!=0||b1!=0))cout<<-1<<endl;
 else cout<<0<<endl;                  
}

else if (a1==0&&b1==0)cout<<0<<endl;
else if (a2==0&&b2==0)cout<<0<<endl;
else cout<<1<<endl;

cin.get();cin.get();
return 0;}