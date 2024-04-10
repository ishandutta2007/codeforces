/*
So after all those one night stands
You've ended up with heart in hand
A child alone
On your own
Retreating

Regretful for the things you're not
And all the things you haven't got
Without a home
A heart of stone
Lies bleeding

And for all the roads you followed
And for all you did not find
And for all the things you had to leave behind

I am the way
I am the light
I am the dark inside the night
I hear your hopes
I feel your dreams
And in the dark I hear your screams
Don't turn away
Just take my hand
And when you make your final stand
I'll be right there
I'll never leave
All I ask of you
Believe

Your childhood eyes were so intense
While bartering your innocence
For bits of string
The grown-up wings
You needed

But when you had to add them up
You found that there were not enough
To get you in
Pay for sins
Repeated

And for all the years you borrowed
And for all the tears you cried
And for all the fears you had to keep inside
Yeah

I am the way
I am the light
I am the dark inside the night
I hear your hopes
I feel your dreams
And in the dark I hear your screams
Don't turn away
Just take my hand
And when you make your final stand
I'll be right there
I'll never leave
And all I ask of you
Believe, yeah

I never wanted to know
Never wanted to see
I wasted my time
Till time wasted me
Never wanted to go
Always wanted to stay
'Cause the persons I am
Are the parts that I play
So I plot and I plan
Hope and I scheme
To the lure of a night
Filled with unfinished dreams
And I'm holding on tight
To a world gone astray
As they charge me for years
I can't pay

I am the way
I am the light
I am the dark inside the night
I hear your hopes
I feel your dreams
And in the dark I hear your screams
Don't turn away
Just take my hand
And when you make your final stand
I'll be right there
I'll never leave
All I ask of you
Believe
Believe
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long long cp,w1,w2;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
if (st[i]=='^')cp=i;
for (int i=0;i<st.size();i++)
if (st[i]>='0'&&st[i]<='9')
{
 if (i<cp)w1+=(cp-i)*(st[i]-48);
 else w2+=(i-cp)*(st[i]-48);
}
if (w1==w2)cout<<"balance"<<endl;
else if (w1>w2)cout<<"left"<<endl;
else cout<<"right"<<endl;

cin.get();cin.get();
return 0;}