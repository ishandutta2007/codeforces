/*
Onward pounding war machine
The hammer battalion Unleashed
Warheads armed with nuclear hate
Using humans as our bait

The order is to kill
Fire at will
The order is to kill
Fire at will
Hammer battalion Unleashed

Smashing through like rabid hounds
Walls they built fall to the ground
Those who oppose is flee or die
Death is marching on our side

The order is to kill
Fire at will
The order is to kill
Fire at will
Hammer battalion Unleashed

Join the battalion!
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
#define bs 109546051211ll
#define bsize 512
#define nice adsfasdfasdfasdf

using namespace std;

long long ans,ar[100],w;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=6;i++)
    cin>>ar[i];

w=ar[6]*2+1;

for (int i=1;i<=min(ar[1],ar[5]);i++)
{
    ans+=w;
    w+=2;
}
w-=1;

for (int i=min(ar[1],ar[5])+1;i<=max(ar[1],ar[5]);i++)
{
    ans+=w;
}

w-=1;

for (int i=max(ar[1],ar[5])+1;i<=ar[1]+ar[2];i++)
{
    ans+=w;
    w-=2;
}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}