/*
I'm not anti-society, society's anti-me
And I'm not anti-religion, religion is anti-me
And I'm not anti-tradition, tradition is anti-me
And I'm not anti-anything, I just wanna be free

Fascist state, no freedom
Unless you control yourself
Use self expression, lose your freedom
You're undesirable, you go straight to jail

Two sided politics
What's there in it for me

Kill someone in a war
Get a medal, you're a hero
Protect yourself in every day war
You're a minority you go straight to jail

Two sided politics
What's there in it for me

I'm not anti-Reagan, Reagan's anti-me
I'm not anti-government, government's anti-me
I'm not anti-politics, politics is anti-me
I'm not anti-anything, I just wannna be free

Innocent, never guilty
High class lawyer, you are rich
If you're poor must be guilty
Even if innocent you go straight to jail

Two sided politics yeah
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

string st1,st2;
long cnt[1<<20];
long q;
long ans1,ans2;
long used[1<<20];

long paired(char x)
{
 if (x>='a'&&x<='z')
  return x-'a'+'A';
  return x-'A'+'a';
}

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1>>st2;
for (int i=0;i<st2.size();i++)
 cnt[st2[i]]++;

for (int i=0;i<st1.size();i++)
{
 if (cnt[st1[i]]){++ans1;--cnt[st1[i]];used[i]=1;}
}

for (int i=0;i<st1.size();i++)
{
 if (used[i])continue;
 int q=paired(st1[i]);
 if (cnt[q]){++ans2;--cnt[q];}
}
cout<<ans1<<" "<<ans2<<endl;

cin.get();cin.get();
return 0;}