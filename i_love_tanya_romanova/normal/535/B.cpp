/*
It's a wish for reprisal
the vengeance the divine has chosen
In the reflection of this anger
Is the embodiment of all that is despised
They'll claim it's justified
They'll say it's divine judgment
With prayers and wishes to be granted
with destruction and murder behind their eyes
Pray tonight, Pray
Beg the sky, Beg
the angels they claim
May be sent to take our life
A wish for something more than death
Born now are new saviors
Sent to steal our breath

Pray tonight, Pray
Beg the sky, Beg
The angels they claim
May be sent to take your life

Some claim it's justified
Some say it's judgment of the divine
How could it be the work the work of their divinity?
It's divine retribution
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n;
map<long, long> mapp;
vector<long> v;

void gen(long x)
{
 if (x>0)v.push_back(x);
 if (x>1e8)return;
 gen(x*10+4);
 gen(x*10+7);
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

gen(0);
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
 mapp[v[i]]=i+1;
cin>>n;
cout<<mapp[n]<<endl;

cin.get();cin.get();
return 0;}