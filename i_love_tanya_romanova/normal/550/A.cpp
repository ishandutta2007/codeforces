/*
Have you lost all your senses?
Oh, why did you have to go tempting fate?
Blinded by your ambitions
Oh, why can't you see the chaos you create?

Oh, have we gone too far, too fast?

My dying eyes scream with pain
All my hopes and my dreams drown in flames
And all the lies shine so bright
All the souls of the world light up the night

You're a slave to desire
For lust of profit you consume my soul
Do you think you can make it stop?
Oh no - it's too late to turn, you've lost control.

Oh, have we gone too far, too fast?

My dying eyes scream with pain
All my hopes and my dreams drown in flames
And all the lies shine so bright
All the souls of the world light up the night

Pushing the boundaries
Reinvent a new reality
Changing evolution
Ignoring the past
As we realize our destructive destiny

Come on!
I want to see you drown in flames.

My dying eyes scream with pain
All my hopes and my dreams drown in flames
And all the lies shine so bright
All the souls of the world light up the night
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

string st;
int found;
int ab1,ab2,ba1,ba2;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;

int found=0;

ab1=ba1=1e9;
ab2=ba2=-1e9;

for (int i=0;i+1<st.size();i++)
{
    if (st[i]=='A'&&st[i+1]=='B')
    {
        ab1=min(ab1,i);
        ab2=max(ab2,i);
    }
    if (st[i]=='B'&&st[i+1]=='A')
    {
        ba1=min(ba1,i);
        ba2=max(ba2,i);
    }
}

if (ab1+1<ba2||ba1+1<ab2)
 found=1;
 
if (found)
 cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 
//cin.get();cin.get();
return 0;}