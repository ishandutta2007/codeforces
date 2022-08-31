/*
Cought in neverland, no purpose to be seen
There's no point of destination
Neverending wastelands, such a wicked odyssey
Don't know what we have done wrong
Lead us back to Rome to follow you again
Bring you the power, get salvation
I know less than all but more
than many who know less
I know it's keeping us strong

And while they are pulling strings
While they are in command
They're hanging on strings
And fate they do commend into another hand

Cought in neverland, heat and fire, snow and ice
They call nether world what we call a paradise
Cought in neverland and their spirits cannot rise
From the nether world, they can't see a paradise

And the Roman whore, the masters and the slaves
Raging on without they don't know
Good intentions on their minds
Can't ask for why they bow out

Lead us to Eden, judge those who bite off more
than they can chew to serve, without they ask
Or call in doubt the ask

Cought in neverland, heat and fire, snow and ice
They call nether world what we call a paradise
Cought in neverland and their spirits cannot rise
From the nether world, they can't see a paradise

Cought in neverland in the place of many eyes
Make it be what they are allowed to realize

Cought in neverland, heat and fire, snow and ice...
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

using namespace std;

long long n,ar[2100000],s,r;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=0;i<n;i++)
cin>>ar[i];

sort(ar,ar+n);
reverse(ar,ar+n);

for (int pw=0;(1<<pw)<=n;pw+=2)
{
    r=(1<<pw);
    for (int j=0;j<r;j++)
    s+=ar[j];
}
cout<<s<<endl;

cin.get();cin.get();
return 0;}