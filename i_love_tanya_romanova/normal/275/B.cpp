/*
Oh life, it's bigger
It's bigger than you
And you are not me
The lengths that I will go to
The distance in your eyes
Oh no, I've said too much
I've said enough

That's me in the corner
That's me in the spotlight
Losing my religion
Trying to keep up with you
And I don't know if I can do it
Oh no, I've said too much
I haven't said enough

I thought that I heard you laughing
I thought that I heard you sing
I think I thought I saw you try

Every whisper 
Of every waking hour
I'm choosing my confessions
Trying to keep an eye on you
Like a hurt, lost and blinded fool, fool
Oh no, I've said too much
I've said enough

Consider this
Consider this, the hint of the century
Consider this, the slip
That brought me to my knees, failed
What if all these fantasies come
Flailing around
Now I've said too much

I thought that I heard you laughing
I thought that I heard you sing
I think I thought I saw you try

But that was just a dream
That was just a dream

That's me in the corner
That's me in the spotlight
Losing my religion
Trying to keep up with you
And I don't know if I can do it
Oh no, I've said too much
I haven't said enough

I thought that I heard you laughing
I thought that I heard you sing
I think I thought I saw you try

But that was just a dream
Try, cry, why try
That was just a dream
Just a dream
Just a dream, dream
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
//#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-9
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

char ar[100][100];
long n,m,fl,fl1,tfl;
long lx,ly,rx,ry,qx,qy;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
{
   cin>>ar[i][j]; 
}

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
for (int i1=i;i1<=n;i1++)
for (int j1=1;j1<=m;j1++)
if (ar[i][j]=='B'&&ar[i1][j1]=='B')
{
 lx=i;rx=i1;
 ly=j;ry=j1;
// if (lx>rx)swap(lx,rx);
// if (ly>ry)swap(ly,ry);
 fl=0;
 fl1=0;
long dx,dy;
if (ry>ly)dy=1;
else dy=-1;
if (rx>lx)dx=1;
else dx=-1;

 qx=lx;
 qy=ly;
    
 while (qx!=rx){qx+=dx; if (ar[qx][qy]=='W')fl=1;}
 while (qy!=ry){qy+=dy;if (ar[qx][qy]=='W')fl=1;}
    
 qx=lx;qy=ly;
 while (qy!=ry){qy+=dy;if (ar[qx][qy]=='W')fl1=1;}
 while (qx!=rx){qx+=dx; if (ar[qx][qy]=='W')fl1=1;}
 
 if (fl>0&&fl1>0){
 tfl=1;break;}
}

if (tfl)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}