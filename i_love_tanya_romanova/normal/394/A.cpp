/*
Brought back from the silence
As darkness whitened into a day
Tried to weave the pieces together
Force the past away

Mind weary of sorrow
Body tired from the way
Welcomed yet another morning
Of longing and dismay

What have I for you to offer
Besides this long haul
Wade across vast snowfields
Journey through endless moors

Death walked the earth today
Without a sound, motionless
Forced its way into my arms
Caressed me with the dark

Dragged again up to surface
From the bowels of the earth
To face yet another morning
Breath gasping black steam of death

These are our waking hours
In cold sunlight we pine away
Towards yet another morning
Till following hopeless day
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define bsize 256

using namespace std;

string st;
long a,b,c,q;

void showw(long a,long b,long c)
{
 for (int i=0;i<a;i++)
 cout<<"|";
 cout<<"+";
 for (int i=0;i<b;i++)
 cout<<"|";
 cout<<"=";
 for (int i=0;i<c;i++)
 cout<<"|";cout<<endl;
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
q=0;
while (st[q]!='+'){++a;++q;}
++q;
while (st[q]!='='){++b;++q;}
++q;
c=st.size()-q;

//cout<<a<<" "<<b<<" "<<c<<endl;

if (a+b==c)
showw(a,b,c);
else 
if (a+1+b==c-1)
{
 showw(a+1,b,c-1);
}
else if (a>1&&a+b-1==c+1)
{
 showw(a-1,b,c+1);
}
else if (b>1&&a+b-1==c+1)
{
 showw(a,b-1,c+1);
}
else cout<<"Impossible"<<endl;

cin.get();cin.get();
return 0;}