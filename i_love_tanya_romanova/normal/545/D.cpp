/*
And it feels right this time
On his crash course with the big time
Pay no mind to the distant thunder
New day filled his head with wonder, boy

Says it feel right this time
Turned around and found the light lime
"Good day to be alive.
It's a good day to be alive", he said

Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way
Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way, hey, yeah

Don't it feel right like this?
All the pieces fall to his wish
"Sucker for that quick reward, boy
Sucker for that quick reward", they say

Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way
Then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way, hey, yeah
It's comin' your way, it's comin' your way, yeah, yeah, here it comes

Yeah, then it comes to be that the soothing light at the end of your tunnel
Was just a freight train comin' your way

Then it comes to be, yeah, yeah
Then it comes to be, yeah, yeah
Then it comes to be, yeah, yeah
Then it comes to be, yeah

Then it comes to be, yeah
Then it comes to be, yeah
Then it comes to be, yeah, yeah
Then it comes to be, yeah
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

int n,ar[1<<20];
int s,ans;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
 cin>>ar[i];
sort(ar,ar+n);
for (int i=0;i<n;i++)
 if (ar[i]>=s)
    s+=ar[i],
    ans++;

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}