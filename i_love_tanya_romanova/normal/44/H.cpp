/*
I'll always belong to the shadow
Don't show me new results
I will never enter your heaven
Make the most of my dirty cell

Creeps infected by control
That's what put me in here
Dig deep don't think you ever get to the place where they buried me
The last glimpse that I had
Fragments, pieces of some things valuable
Even though it doesn't make sense anymore
I release my last fear

[Chorus:]
The cold worms and me
We're alone and free
The dead light inside
Fuel to new seed
We're alone and free

When there are only my bones
Please put them in use
Want to be part of a new dawn
The darkness disappears
Don't release these chains
Never been closer to myself
All your mistakes run though
As I realize what we become
The end is here to bid farewell
I'll turn to ash and hear them sing
Songs about my emotions dead and alone
Don't make an effort you don't know me anyway

My frustration, my conversation, why are we even here?
The abuse that we use I do not longer care

[Chorus]
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
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

string st;
long long dp[100][100];
long tsum;
long long answ;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<=9;i++)
dp[0][i]=1;
for (int i=0;i+1<st.size();i++)
for (int lst=0;lst<=9;lst++)
{
 tsum=lst+st[i+1]-48;
 if (tsum%2)
 {
  dp[i+1][tsum/2]+=dp[i][lst];
  dp[i+1][tsum/2+1]+=dp[i][lst];
 }
 else
 {
  dp[i+1][tsum/2]+=dp[i][lst];
 }   
}

answ=0;
for (int i=0;i<10;i++)
answ+=dp[st.size()-1][i];

long fl=0;
for (int i=1;i<st.size();i++)
if (abs(st[i]-st[i-1])>1)fl=1;
if (fl==0)--answ;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}