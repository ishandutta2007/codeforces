/*
Off the heezay,
I've been taken from your arms
So many times I've felt this before.
The sheets are tangled
And they don't feel right on my carcass.
Like you do.

This is my revenge!
For every second sleep has stole
I feel dead
I feel dead inside.
I feel dead
I feel so fucking dead
I feel dead
I feel so dead!

Last night we dressed to our best,
And drank 'til there was nothing left.
I walked you home, you held my hand
We fucked away the rest of the night

Take my hand
For this is my revenge.
This is my revenge.
For every second lost.
This is my revenge!
This is my revenge!
This is my revenge!
This is my...
This is my revenge!
This is my...
(For every second)
Sleep has stole

And sweetie, I've got to say
That I'm really not worth the time of your day.
I guess when when we left each other for the first time
We didn't think goodbye would be our new favorite line.
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
//#include <memory.h>

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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long temp,tests,n;
set<long> ans;

int main(){
//freopen("test.in","r",stdin);
//freopen("test.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=3;i<=1000;i++)
{temp=180*(i-2);
if (temp%i==0)ans.insert(temp/i);}

cin>>tests;
for (;tests;--tests)
{
 cin>>n;
 if (ans.find(n)!=ans.end())cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}

cin.get();cin.get();
return 0;}