/*
Slit my wrists, take away the pain.
Slit my throat, there's no one to blame.
Lost in the fields of confusion.
Restless nights, they're not far away.
I came here for something and I'm not turning back.
A calm piece of mind but you still hold my keys.
Keeping my fate deep within your threshold.
Petty inconvenience but it means the world to me.
You have the power.
To set me free.
Caught in your grasp, how?
Just let me be.
Give me control out.
Out of these depths.
A fiery hell.
I pray for death.
I've been the wrong one time and time again.
Now I'm on my knees forgive me please.
Tore out my heart and handed to me on a silver platter.
Sew up the hole, emptiness in the place of compassion.
You made me this way.
I am the product of your creation.
Look the other way.
Now you've turned your back on me.
You've turned away from me, the future's much to far away to see.
I hope you learn the truth, not the way things were meant to be with me and you.
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

long a[2000],b[2000],m,n,calc,mx;

int main(){
//freopen("line3.in","r",stdin);
//freopen("line3.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>a[i];
cin>>m;
for (int i=1;i<=m;i++)
cin>>b[i];
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (b[j]%a[i]==0)
{
 if (b[j]/a[i]>mx){calc=1;mx=b[j]/a[i];}
 else
 if (b[j]/a[i]==mx)++calc;
}
cout<<calc<<endl;

cin.get();cin.get();
return 0;}