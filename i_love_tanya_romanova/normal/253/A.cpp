/*
I am caught in a dream
and I am trying to pass through.
Something insane is on the prowl
uncertainty is frightening me.
It will get me. It will choke me.
Screaming in my bed in agony
when I hear the clock
I have got to wake up
cause falling back asleep
means to get in his trap
Release from Agony
Release from Agony
This nightmare surrounds me
I am prepared for the worst
Captured timeless in the darkness
one second seems like eternity
It will get me. It will choke me.
Screaming in my bed in agony
when I hear the clock
I have got to wake up
cause falling back asleep
means to get in his trap
Release from Agony
Release from Agony
Getting in state of panic
this can't be just imagination
Iam praying to be awake
I don't want to face this vicious circle
I know this nightmare will revert
it is driving me to despair
My refuge will be reality
Release from Agony!
It will get me. It will choke me.
Screaming in my bed in agony
when I hear the clock
I have got to wake up
cause falling back asleep
means to get in his trap
Release from Agony
Release from Agony
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
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,m,last,ttl;

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
if (n>m)
{last='G';}else last='B';
long ttl=n+m;
for (int i=1;i<=ttl;i++)
{
    if (n==0)cout<<"G",--m;
    else if (m==0)cout<<"B",--n;
    else if (last=='G'){cout<<"B";last='B';--n;}
    else {cout<<"G";--m;last='G';}
}cout<<endl;

cin.get();cin.get();
return 0;}