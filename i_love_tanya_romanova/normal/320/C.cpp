/*
If I say I don't need anyone
I can say these things to you 
'Cause 
I can turn on any one 
Just like I turned on you 
I've got a tongue like a razor 
A sweet switchblade knife 
And I can do you favors 
But then you'll do whatever I like

[Chorus:]
Here I am 
And you're a Rocket Queen 
I might be a little young 
But honey I ain't naive 
Here I am 
And you're a Rocket Queen oh yeah 
I might be too much 
But honey you're a bit obscene

I've seen everything imaginable 
Pass before these eyes 
I've had everything that's tangible 
Honey you'd be surprised 
I'm a sexual innuendo 
In this burned out paradise
If you turn me on to anything 
You better turn me on tonight

Chorus

I see you standing 
Standing on your own 
It's such a lonely place for you 
For you to be 
If you need a shoulder
Or if you need a friend 
I'll be here standing 
Until the bitter end 
No one needs the sorrow 
No one needs the pain 
I hate to see you 
Walking out there 
Out in the rain 
So don't chastise me
Or think I, I mean you harm 
Of those that take you 
Leave you strung out
Much too far 
Baby-yeah

Don't ever leave me 
Say you'll always be there
All I ever wanted 
Was for you 
To know that I care
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

string st;
long long r,ans;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for(int i=0;i<st.size();i++)
{
 if (st[i]=='1')
 {
 r=1;
 for (int j=0;j<i;j++)
 r=r*2%bs;
 for (int j=i+1;j<st.size();j++)
 r=r*4%bs;
 ans+=r;
 }
 ans%=bs;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}