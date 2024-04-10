/*
Start your brain! I'm thinking, man!

Start your brain, start your brain, start your brain, rev it up and ride!

Start your brain!
You got to start your brain!

Start your brain, rev it up and go
Learn the things that you don't wanna know
Do the things that you don't wanna do
It will tell a lot about you

Start your brain, rev it up and ride!
Start your brain, rev it up and ride!
Start your brain, rev it up and ride!
Start your brain, rev it up and ride!

Rev it up and ride!
Rev it up and ride!

Start your brain, rev it up and ride
It's been way too long since you have tried
Take your attitude and give it a rest
And anything you do, give it your best

Start your brain, rev it up and go
There's so many things that you don't know
Don't waste your time trying to impress
And spend that time cleaning up that mess

Start your brain, rev it up and ride!
Start your brain, rev it up and ride!
Start your brain, rev it up and ride!
Start your brain, rev it up and ride!

Rev it up and ride!
Rev it up and ride!

Start your brain, rev it up and ride!
Start your brain, rev it up and ride!
Start your brain, rev it up and ride!
Start your brain, rev it up and ride!

Rev it up and ride!
Rev it up and ride!

Start your brain!
You got to start your brain!

Start your brain, rev it up and ride
Figure out who you are deep inside
Take your attitude and give it a rest
And anything you do, give it your best

So, start your brain, rev it up and ride
Figure out who you are deep inside
Take your attitude and give it a rest
And anything you do, give it your best

Start your brain, start your brain, start your brain and ride!
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
long ans;
long calc1[20000],calc2[20000];

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>st1;
cin>>st2;
for (int i=0;i<st1.size();i++)
calc1[st1[i]]++;
for (int i=0;i<st2.size();i++)
calc2[st2[i]]++;
for (int i='a';i<='z';i++)
 if (calc2[i]>0&&calc1[i]==0){cout<<-1<<endl;return 0;}
for (int i='a';i<='z';i++)
ans+=min(calc1[i],calc2[i]);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}