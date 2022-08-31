/*
Fearless rejection
Breathing with imperfection
Living with imperfection
Listen to me when I say
That I will never get back to you
You bite the hand that was feeding you
Dark thoughts nailed into your fate now
Dark thoughts awaiting to shine now
I choose a way with no surrender
I choose a way with no surrender
Won't you stay away, away
I guess it's not the last time
Won't you stay away, away
I just hope it's the last time
Looking after me
I need you and you need me
But it seems you didn't read the information
Dark thoughts nailed into my fate now
Dark thoughts awaiting to shine now
Keeping me calm before I explode
Keeping me calm you're keeping me close
You don't know my determination
I'll make you feel a new sensation
Won't you stay away, away
I guess it's not the last time
Won't you stay away, away
I just hope it's the last time
I need to be in control
In control of myself
In control of myself
Fearless rejection
Imperfection
Won't you stay away, away
I guess it's not the last time
Won't you stay away, away
I just hope it's the last time
I need to be in control
In control of myself
I choose a way with no surrender
I choose a way with no surrender
*/

#pragma comment(linker, "/STACK:16777216")
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

using namespace std;

string st;
long ans;
set<char> sett;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

getline(cin,st);
for (int i=0;i<st.size();i++)
 sett.insert(st[i]);
for (int i='a';i<='z';i++)
 if (sett.find(i)!=sett.end())++ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}