/*
It's not so much the pain
It's more the actual knife
Pretending the picture is perfect
I cut myself to sleep
I close my eyes for a second
And curse my fragile soul
I scream to hide that I'm lonely
The echo calls my name

[Pre chorus:]
If I ever, If I never
Make me understand the thought whatever
Make me see. Make me be
Make me understand you're there for me

[Chorus:]
Take this life, I'm right here
Stay awhile and breathe me in
Take this life, I'm right here
Stay awhile and breathe me in

The rain drops just beg to hit me
What now? Hasn't rained for days
No time to play hide-and-seek
I call on you to take me on
Break me down to pieces
Put me back, do it right this time
Struggling to fill this empty shell
Burn all my efforts
In the end it means nothing

[Pre chorus]

[Chorus]

[x2]
These thoughts, burn a hole in my heart
These thoughts, will keep me free and

[Pre chorus]

[Chorus]
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

set<string> has;
long n,m,k;
string st;
string name;
map<string, long> ax,ay;
long usd[100][100];
long a,b;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=1;i<=k;i++)
{
    cin>>st;
    if (st=="-1")
    {
            cin>>name;
            if (has.find(name)==has.end())
            {
             cout<<-1<<" "<<-1<<endl;
            }     
            else
            {
                has.erase(has.find(name));
                cout<<ax[name]<<" "<<ay[name]<<endl;
                usd[ax[name]][ay[name]]=0;
            }
    }
    else
    {
      cin>>a>>b;
      cin>>name;
      while (usd[a][b]==1){++b;if (b>m){++a;b=1;}}
     // cout<<a<<" "<<b<<endl;
      if (a<=n){usd[a][b]=1;has.insert(name);ax[name]=a;ay[name]=b;}   
    }
}

cin.get();cin.get();
return 0;}