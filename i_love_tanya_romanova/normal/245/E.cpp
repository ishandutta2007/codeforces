/*
Knowledge alone is not what's consuming me
No one at home - even when I'm not asleep
Demons are chasing me
Knowing that I can't run
Teasing and taunting me
Round in my mind
Knowledge alone is not what's consuming
Bleed the mind
Drain to see what's inside
What will you find
Something you can't explain
Bleed the mind
Empty the thoughts from there
Asleep inside
Brain activity - rare
Demons are chasing me
Knowing that I can't run
Teasing and taunting me
Round in my mind
Bleed the mind
Until the head is turned
Search the soul - can't find morality
No one at home - lost deep inside my sleep
Search the soul - look past the hollow stare
Find my soul
Demons are chasing me
Knowing that I can't run
Teasing and taunting me
Round in my mind
Bleed the mind
Until the head is
Until the head is turned
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
#define eps 1e-8
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
long mn,mx,q;

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
mn=mx=0;

for (int i=0;i<st.size();i++)
{
 if (st[i]=='-')--q;
 else ++q;
 mx=max(mx,q);
 mn=min(mn,q);   
}
cout<<mx-mn<<endl;

cin.get();cin.get();
return 0;}