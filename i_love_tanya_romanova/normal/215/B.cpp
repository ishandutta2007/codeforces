/*
Darkness coats us.
The smell of fall.
Changing season.
The graveyard is alive, black cat across my path,
the chill of cold wind, the breath of the dead.
Imprisoned souls.
Trapped for eternity.
Black crows break the silence.
The garden of the dead s alive tonight and you can't stop it.
Just enjoy it.
Open up your mind and you will feel it too.
The sound, the touch, the thoughts, that you've been so blind to.
You can feel the thoughts of the dead.
Feeling the thoughts of the dead.
True or false, it's still there, teaching me.
True or false, still there, teaching me.
You can feel it tonight.
The wood has rotted away.
Take the time absorb it.
Their time is slipping away.
Stone all carved by hand.
Statues that resemble their faces.
They still breathe.
Come join us.
Smell the burning ember's, time flickering away.
Timeless but soon gone.
Timeless but soon gone.
I can find myself, alone with just my thoughts.
As time crumbles away.
As I crumble away.
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,m,k;
double x[100000],y[100000],a,b,w1,w2,ro1,ro2,z[100000],r,rr,ll,s1,s2,ro;

int main(){
//freopen("line3.in","r",stdin);
//freopen("line3.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
    cin>>x[i];
}
cin>>m;
for (int i=0;i<m;i++)
{
cin>>y[i];
}
cin>>k;
for (int i=0;i<k;i++)
cin>>z[i];

sort(x,x+n);
sort(y,y+m);
sort(z,z+k);

r=x[n-1];
ro1=y[m-1];
ro2=z[0];

//cout<<r<<" "<<ro1<<" "<<ro2<<endl;

cin>>a>>b;
swap(b,a);
double m;
ll=0;
rr=r;
while (ll<rr-eps)
{
 m=ll+rr;
 m/=2;
 w1=m*m*ro2;
 w2=r*r*ro1-m*m*ro1;
 if (w1/w2<a/b)ll=m;
 else rr=m;     
}
cout.precision(9);
cout<<fixed<<ll<<endl;

cin.get();cin.get();
return 0;}