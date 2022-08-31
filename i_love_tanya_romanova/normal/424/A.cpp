/*
We saw it all pass by and you went by
And I can't control anything
When you said that life can't be what you want
And I really want everything
Hat I pray when I believe

I saw it end long before it ended
Life itself turned pale and ended
I saw you cry acres of your image
Life itself does not heal me

Like a slow scenery I'm losing all my faith
In lifeless motion you're walking like you're dead
Like a slow scenery I'm losing all my faith
In lifeless motion you're walking like you're dead

We saw it all pass by and you went by
And I can't control anything
When you said that life can't be what you want
And I really want everything
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
//#include <memory.h>

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
//#define N 120000

using namespace std;

long n;
string st;
long c1,c2;

int main(){
//freopen("trading.in","r",stdin);
//freopen("trading.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
for (int i=0;i<st.size();i++)
 if (st[i]=='x')++c1;

cout<<abs(c1-n/2)<<endl;
if (c1>n/2)
{
 for (int i=0;i<st.size();i++)
 if (st[i]=='x'&&c1>n/2)st[i]='X',--c1;
}
else
{
    for (int i=0;i<st.size();i++)
     if (st[i]=='X'&&c1<n/2)st[i]='x',++c1;
}
cout<<st<<endl;

cin.get();cin.get();
return 0;}