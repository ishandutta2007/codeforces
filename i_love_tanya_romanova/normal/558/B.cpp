/*
I belong to those from somewhere
nowhere, everywhere
We constructed your race
for a special task
At last you failed
You'll be wiped out 
Without a warning he appeared
in between all of these grey hired old men
We called them the world presidents
They ask him for just ten more years
and so he granted it 
Freedom peace and all the
things we'd wished before
were no longer visions
They had all come true
On the tenth year
the world awaits 
From nowhere again he appears
and told us once more we had failed
You were not built for love and peace
You were to be the killer race
without emotion 
It's not for you to understand
the reason for the things we planned
So we will erase what you've done
because you've failed once again
It doesn't matter why
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
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 1024

using namespace std;

int n,ar[1<<20],mx;
vector<int> ent[1<<20];
int aL,aR;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    ent[ar[i]].push_back(i);
    if (mx<ent[ar[i]].size())
        mx=ent[ar[i]].size();
}

aL=1;
aR=n;
for (int i=0;i<=1000000;i++)
{
    if (ent[i].size()<mx)
        continue;
    int span=ent[i].back()-ent[i][0];
    if (span<aR-aL)
    {
        aL=ent[i][0];
        aR=ent[i].back();
    }
}
cout<<aL<<" "<<aR<<endl;

//cin.get();cin.get();
return 0;}