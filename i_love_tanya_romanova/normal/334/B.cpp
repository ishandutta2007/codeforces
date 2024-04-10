/*  
So goddamn easy to write this,
You make it spill on the page.
So drunk on yourself, self-righteous,
A laughing stock of your own fucking sage.

But I ain't one to call names,
Or throw stones in a house of glass.
You try me.

This is a motherfucking invitation
The only one you could ever need.
This is a motherfucking invitation.
You try me.

Just one time you got a reason,
But you had nothing to lose.
A blind preacher for the pin-eyed congregation,
It must be easy to loathe.

But I ain't one of those names,
Or throw stones in a house of glass.
You try me.

This is a motherfucking invitation
The only one you could ever need.
This is a motherfucking invitation.
You try me.

You can tell the same lie a thousand times,
But it never gets any more true,
So close your eyes once more and once more believe
That they all still believe in you.
Just one time.

This is a motherfucking invitation
The only one you could ever need
This is a motherfucking invitation
Just one time

This is a motherfucking invitation
You try me
Just one time
You try me
Just one time
You try me
You try me
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
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long x[100],y[100];
vector<long> xx,yy,dx,dy;
set<pair<long, long> > pts;
long fl;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=0;i<8;i++)
{
    cin>>x[i]>>y[i];
    xx.push_back(x[i]);
    yy.push_back(y[i]);
    pts.insert(make_pair(x[i],y[i]));
}
sort(xx.begin(),xx.end());
sort(yy.begin(),yy.end());

for (int i=0;i<xx.size();i++)
if (i==0||xx[i]!=xx[i-1])dx.push_back(xx[i]);

for (int i=0;i<yy.size();i++)
if (i==0||yy[i]!=yy[i-1])dy.push_back(yy[i]);

if (dx.size()!=3||dy.size()!=3)
cout<<"ugly"<<endl;
else
{
 fl=0;
 for (int i=0;i<3;i++)
 for (int j=0;j<3;j++)
 if (i!=1||j!=1)
 if (pts.find(make_pair(dx[i],dy[j]))==pts.end())
{fl=1;
// cout<<dx[i]<<" "<<dy[i]endl;
 }if (fl)cout<<"ugly"<<endl;
 else cout<<"respectable"<<endl; 
}

cin.get();cin.get();
return 0;}