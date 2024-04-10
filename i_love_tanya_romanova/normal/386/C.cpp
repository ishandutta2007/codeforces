/*
Kronos is drumming
And time is running.
Enter the aeon
And bring back the past.

Wheel of fortuna
Dancing with shiva
Spin to the newborn
Who live to the last.

The world is changing
And fall apart
End of the kingdom
And of the heart

The queen of beauty (veil of time)
Now cold and pale
The sun is setting
The night prevail.

But fear not darkness.
It' hidden light
And you will find it
Shining with bright.

The time is running (veil of time)
The flame will burn
When today vanish,
But all return.

Time will come to an end but bring back the start again

Queen of time will rise again
And bring forth the future
Wheel of time will whirl around
And bring back the past.
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long long last[500];
long long tv[200];
long long ans[200];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i='a';i<='z'+1;i++)
last[i]=-1;

for (int i=0;i<st.size();i++)
{
 last[st[i]]=i;
 for (int j='a';j<='z'+1;j++)
 tv[j-'a']=last[j];
 sort(tv,tv+27);
 reverse(tv,tv+27);
 for (int j=1;j<27;j++)
 {ans[j]+=tv[j-1]-tv[j];}
 
}
long
q=26;
while (ans[q]==0)--q;
cout<<q<<endl;
for (int i=1;i<=q;i++)
cout<<ans[i]<<endl;

cin.get();cin.get();
return 0;}