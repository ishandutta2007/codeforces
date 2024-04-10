/*
End of the whirl
Trend of the system
Bend of the curl
Hell will never miss them

Brains us to think
In tiny trains of thought
Time and time again
Mind overwrought

Above all the people
Above all the creeps
Above all the steeples
Above all the freaks

Weigh in, weigh out
Time fleeting by
Day in, day out
Life spilling by

Follow the same
Unwanted blind
Swallow your name
Get left behind

[2x]
Above all the people
Above all the creeps
Above all the steeples
Above all the freaks

You're freaking out [5x]

Seven billion breathe all at once
Heaven well conceived experience
Breed ignorants, feed ignorance

A simple meaning
To a simple plan
The temple gleaming
Keep fooling man

The question won
And beat the answer
Riddle come undone
Fat lady dances

[2x]
Above all the people
Above all the creeps
Above all the steeples
Above all the freaks

Above all the freaks
Above all the freaks
Above all the freaks

Above all the people
Above all the people
Above all the people
Above all the people
C'mon people
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

string st;
stack<long> s;

int main(){
//freopen("swimming.in","r",stdin);
//freopen("swimming.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 if (s.size()==0)s.push(st[i]);
 else if (s.top()==st[i])
 {
      s.pop();
 }   
 else s.push(st[i]);
}

if (s.size())cout<<"No"<<endl;
else cout<<"Yes"<<endl;

cin.get();cin.get();
return 0;}