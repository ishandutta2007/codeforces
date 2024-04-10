/*
The killing is a mean rots in the pain
Fight for the fear of rights
The time is set scream for the help
Fly thru the darkest nights

The peeling is the skin rotting the soul
Hailing for the chosen son
Mortality the pain fear for the living
Ravage the chosen one

The darkness falls beyond the grave
Blessed ground in which they save
Even though the time has passed
Your soul is fucked in the gutter

Rotting souls in fear of desperately
Serpent souls in bowels on which to feed
Reach out for joy reach out for blood and parts
Reach out for craves the blood we're feasting on blood
Help me I'm in pain
Help me I'm in pain
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;
string st;
long n,k,ar[200000],cp;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>k;
getline(cin,st);
getline(cin,st);
for (int i=1;i<=n;i++)ar[i]=st[i-1]-48;

for (int i=1;i<=n-2;i++)
{if (ar[i]==4&&ar[i+1]==7&&ar[i+2]==7&&i%2==1&&cp==0){cp=i;}
 if (ar[i]==4&&ar[i+1]==4&&ar[i+2]==7&&i%2==1&&cp==0)cp=i;
}

if (cp==0)
{for (int i=1;i<n;i++)
{if (ar[i]==4&&ar[i+1]==7&&k>0)
{--k;
 if (i%2==1){ar[i+1]=4;} else ar[i]=7;
}
}
}

else 
{for (int i=1;i<cp;i++)
{if (ar[i]==4&&ar[i+1]==7&&k>0)
{--k;
 if (i%2==1){ar[i+1]=4;} else ar[i]=7;
}
}

if (k>0)
{if ((k%2==1&&ar[cp+1]==7)||(k%2==0&&ar[cp+1]==4))ar[cp+1]=4; else ar[cp+1]=7;}

}

for (int i=1;i<=n;i++)cout<<ar[i];
cout<<endl;

 cin.get();cin.get();
return 0;
 }