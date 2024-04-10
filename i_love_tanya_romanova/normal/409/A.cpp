/*
In these moments of loss and torment
When the vast skies don't seem to call to you
When the weight of this world bears down
And the stars have fallen like tears

I am with you always,
From the darkness of night until the morning
I am with you always,
From life until death takes me

Monuments built in remembrance of me
But monuments fade, erode and decay
The memories are all that remain
As far as east is from the west, remember

I am with you always,
From the darkness of night until the morning
I am with you always,
From life until death takes me

When hope seems lost down and lowly,
I am here with you always

I am with you always,
From the darkness of night

I am with you always,
From the darkness of night until the morning
I am with you always,
From life until death takes me

I am with you always,
From life until death takes me
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

string st1,st2;
vector<char> v1,v2;
long score;

long cm(char a,char b)
{
//     cout<<a<<" "<<b<<endl;s
 if (a==b)return 0;
 if (a=='8'&&b=='[')return 1;
 if (a=='['&&b=='(')return 1;
 if (a=='('&&b=='8')return 1;
 return -1; 
}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>st1;
cin>>st2;
for (int i=0;i<st1.size();i+=2)
{
 v1.push_back(st1[i]);
}
for (int i=0;i<st2.size();i+=2)
{
 v2.push_back(st2[i]);
}
for (int i=0;i<v1.size();i++)
score+=cm(v1[i],v2[i]);
//cout<<score<<endl;
if (score==0)cout<<"TIE"<<endl;
else if (score>0)cout<<"TEAM 1 WINS"<<endl;
else cout<<"TEAM 2 WINS"<<endl;

cin.get();cin.get();
return 0;}