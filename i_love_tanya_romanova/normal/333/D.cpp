/*  
Anticipating, salivating, intoxicating
How I've been waiting
To gently soak in
Your dream that's broken
Caress my hands
Around your throat
When I choke the last gasp of air out of you

I'll mesmerize you, hypnotize you
Paralyze you, my snake eyes blind you
My tenderest tickle, my gentlest prickle
The back of your neck
I stab icicles

My sweetest grin will pull you in
Behind that grin a razor teeth smile
Under your bed
Inside your head
I am the monster in wait

Walk, run
I'm the fear you've become
Pray, hope
Before it's your
Downfall, and all falls down

I patronize you, victimize you
My false pretenses endear me to you
I'm psychopathic, psychosomatic
Believe everything you've heard about me

Ate you alive since you were a child
That's when the monster first appeared to you
So know my name
What is my name?
My name is fear and I'm you

Walk, run
I'm the fear you've become
Pray, hope
Before it's your
Downfall, and all falls down

With faith I crawl
In sadness, I fear what I've become
'Cause after all
I'm acting, pretend my smile on
Before the fall
The pain washes over
Hold on, hold on
Survive
Survive
This

Walk, run
Free the fear you've become
Fight back
Before it's your
Downfall, and all falls down
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
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long fl,a,b;

vector<long> v;
long n,m,ans,ar[1005][1005],l,r,mm,has[1005][1005];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
 cin>>ar[i][j];   
//ar[i][j]=j;
}

l=0;
r=1200000000;
while (l<r)
{
      mm=l+r+1;
      mm/=2;
      fl=0;
      for (int i=1;i<=m;i++)
      for (int j=i+1;j<=m;j++)
      has[i][j]=0;
      for (int i=1;i<=n;i++)
      {     
       v.clear();
       for (int j=1;j<=m;j++)
       if (ar[i][j]>=mm)v.push_back(j);
       for (int j=0;j<v.size();j++)
       for (int q=j+1;q<v.size();q++)
       {
        a=v[j];b=v[q];
        if (has[a][b])fl=1;
        has[a][b]=1;
       }
       if (fl)break;
      }     
      if (fl)l=mm;
      else r=mm-1;
}

cout<<l<<endl;
cin.get();cin.get();
return 0;}