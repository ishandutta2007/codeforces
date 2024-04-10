/*
Razors edge
Outlines the dead
Incisions in my head
Anticipation the stimulation
To kill the exhilaration

[CHORUS]
Close your eyes
Look deep in your soul
Step outside yourself
And let your mind go
Frozen eyes stare deep in your mind as you die

[CHORUS 2]
Close your eyes
And forget your name
Step outside yourself
And let your thoughts drain
As you go insane... go insane

Innate seed
To watch you bleed
A demanding physical need
Desecrated eviscerated
Time perpetuated

[CHORUS]

[CHORUS 2]

Inert flesh
A bloody tomb
A decorated splatter brightens the room
An execution a sadist ritual
Mad intervals of mind residuals

[CHORUS]

[CHORUS 2]
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
#define eps 1e-6
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

long n,m,q,c1,c2,l,r,span;

int main(){
//freopen("tape.in","r",stdin);
//freopen("tape.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{cin>>q;if (q<0)c1++; else c2++;}

for (int i=0;i<m;i++)
{
    cin>>l>>r;
    span=r-l+1;
    if (span%2==0&&c1>=span/2&&c2>=span/2)cout<<1<<endl;
    else cout<<0<<endl;
}
cin.get();cin.get();
return 0;}