/*
Woo...
I'm ahead, I'm a man
I'm the first mammal to wear pants, yeah
I'm at peace with my lust
I can kill 'cause in God I trust, yeah
It's evolution, baby

I'm at piece, I'm the man
Buying stocks on the day of the crash
On the loose, I'm a truck
All the rolling hills, I'll flatten 'em out, yeah
It's herd behavior, uh huh
It's evolution, baby

Admire me, admire my home
Admire my son, he's my clone
Yeah, yeah, yeah, yeah
This land is mine, this land is free
I'll do what I want but irresponsibly
It's evolution, baby

I'm a thief, I'm a liar
There's my church, I sing in the choir:
(hallelujah, hallelujah)

Admire me, admire my home
Admire my son, admire my clones
'Cause we know, appetite for a nightly feast
Those ignorant Indians got nothin' on me
Nothin', why?
Because... it's evolution, baby!

I am ahead, I am advanced
I am the first mammal to make plans, yeah
I crawled the earth, but now I'm higher
2010, watch it go to fire
It's evolution, baby
Do the evolution
Come on, come on, come on
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define N 120000

using namespace std;

string st;
vector<pair<long, long> > v;
long calc;
long long ans1,ans2;
long calcc[1000][1000];

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 if (i==0||st[i]==st[i-1])++calc;
 else
 {
  v.push_back(make_pair(st[i-1],calc));
  calc=1;
 }
}

//v.push_back(make_pair(st[st.size()-1],calc));

/*for (int i=0;i<v.size();i++)
{
 
}*/

for (int i=0;i<st.size();i++)
{
 calcc[st[i]][i%2]++;
 ans1+=calcc[st[i]][1-i%2];
 ans2+=calcc[st[i]][i%2];
}
cout<<ans1<<" "<<ans2<<endl;

cin.get();cin.get();
return 0;}