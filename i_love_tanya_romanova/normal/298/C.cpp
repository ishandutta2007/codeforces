/*
And it feels right this time
On this crash course with the big time
Pay no mind to the distant thunder
New day fills his head with wonder, boy....

Says it feels right this time
Turned it 'round and found the right line
Good day to be alive Sir
Good day to be alive, he said.....

Then it comes to be that the soothing light at the end of your tunnel
Is just a freight train coming your way
Then it comes to be that the soothing light at the end of your tunnel
Is just the freight train coming your way

Don't it feel right like this
All the pieces fall to his wish
Sucker for that quick reward boy
Sucker for that quick reward they said.....

Then it comes to be that the soothing light at the end of your tunnel
Is just a freight train coming your way
Then it comes to be that the soothing light at the end of your tunnel
Is just the freight train coming your way......
It's coming your way
It's coming your way......
Here comes

Yeah, Then it comes to be that the soothing light at the end of your tunnel
Is just a freight train coming your way.... Yeah...
Then it comes to be, Yeah...
Then it comes to be, Yeah...
Then it comes to be, Yeah...
Then it comes to be, Yeah...
Then it comes to be, Yeah...
Then it comes to be, Yeah...
Then it comes to be, Yeah...
Then it comes to be, Yeah
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long calc;
string st1,st2;

int main(){
//freopen("sumdist.in","r",stdin);
//freopen("sumdist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st1;
cin>>st2;
for (int i=0;i<st1.size();i++)
if (st1[i]=='1')++calc;

if (calc%2)++calc;

for (int i=0;i<st2.size();i++)
if (st2[i]=='1')--calc;
if (calc<0)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}