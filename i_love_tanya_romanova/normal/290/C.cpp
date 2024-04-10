/*
If you got something to say, then come my way
I'm guarded by Satan, I'm riding on Baphomet
I'll teach you a lesson in violence you won't soon forget
The pleasure of watching you die is what I will get

Fight for what you believe to be right
Crushing with all your might
I laugh at their pitiful cries
They run from the fire in my eyes

Nothing can save them now

You've learned a lesson in violence
Get on your knees and bow
Or learn a lesson in violence
I love to stab my victims until they're dead

A knife to the throat or a smashing blow to the head
I'm judge and jury, my sentence has just been passed
Step into the circle of hell if you think you can last

Fight for what you believe to be right
Crushing with all your might
I laugh at their pitiful cries
They run from the fire in my eyes

Nothing can save them now

You've learned a lesson in violence
Get on your knees and bow
Or learn a lesson in violence
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

double bst;
long n,s,q;
long calc;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>q;
 s+=q;
 ++calc;
 bst=max(bst,s*1.0/calc);
}
cout<<bst<<endl;

cin.get();cin.get();
return 0;}