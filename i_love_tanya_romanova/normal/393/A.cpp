/*
This will be for now and for ever the diverging of our paths...

Now that this night has turned into a dawn
I step aside from this path of grieving
Left with all these things I never had chance to say
Words wishful, filled with caring

You must stop your bleeding
Before you run yourself dry
You must let go of your wound
Because love it is crying for is gone

Now that this night has turned into a dawn
I give up this life I have been leading
Left with all these things I never meant to say
Words deceitful, double-dealing

As every breaking day fades away before the dusk
So does hate pause and resentment turn to reason
You've carried enough this burden meant only for me to bear
Now it's your time to straighten up, time for you to walk tall
Alone...
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
 
#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 2048
 
using namespace std;

string st;
long ans;
long calc[2000];

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
calc[st[i]]++;

ans=1e9;
ans=min(ans,calc['e']/3);
ans=min(ans,calc['i']);
ans=min(ans,calc['t']);
ans=min(ans,(calc['n']-1)/2);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}