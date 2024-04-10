/*
Hey, you watching me
Well, what do you see?
Something you want
or something else you just want to see?
I'm not here for you to stare
so would you cut it out
I may be the last thing you see
So be aware

You want me to do all your things
And what do I get? Nothing from you
You are all the same, you promise to change
But still nothing happens
You don't take the blame or the pain
That is something I should do
Well, I got something waiting for you

No, I can't take this anymore
You just make me feel like a dog
You don't listen to me no more
You just want to see me crawl
You're waiting for me to break
That is something that I won't take
I won't take this anymore
I hope you would just die
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
long mx;
vector<string> v;
long strt;
long calc;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

while (getline(cin,st))
{
 long p=st.size();
 mx=max(mx,p);
 v.push_back(st);
}

for (int i=0;i<mx+2;i++)
 cout<<"*";cout<<endl;
 
for (int i=0;i<v.size();i++)
{
 if (v[i].size()%2==mx%2||calc%2==0)
 strt=1;
 else strt=0;
 if (v[i].size()%2!=mx%2)++calc;
 while (v[i].size()!=mx){if (strt)v[i]+=' ';else v[i]=' '+v[i];strt=1-strt;}
 cout<<"*"<<v[i]<<"*"<<endl;
}
for (int i=0;i<mx+2;i++)
 cout<<"*";cout<<endl;

cin.get();cin.get();
return 0;}