/*
Mike Campagnolo and M-Bro
City lights are dimming
Kings and Queens alive
Flames of red are burning
As they diminish time
Eyes of greed are rising
The aides of good will send
Conflict of extremity
A cry, it's the end
Crawling from a shaken mind
The prophets as us why
The jaws of the sharpest realm
Leave us all to die
The population's gathered
Persuaded to defend
The weakness is intelligence
The strength is in - The End
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

string st;
long ans[2000];
long answ;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 ans[i]=1;
 for (int j=0;j<i;j++)
 if (st[j]==st[i]&&j%2!=i%2)
 ans[i]=max(ans[i],ans[j]+1);
}
answ=0;
for (int i=0;i<st.size();i++)
answ=max(answ,ans[i]);
cout<<answ<<endl;

cin.get();cin.get();
return 0;}