/*
Seize the day or die
Regretting the time you lost
It's empty and cold without you here
Too many people to ache over

I see my vision burn
I feel my memories fade with time
But I'm too young to worry
These streets we travel on
Will undergo our same lost past

I found you here
Now please just stay for a while
I can move on with you around
I hand you my mortal life
But will it be forever?

I'd do anything for a smile
Holding you 'til our time is done
We both know the day will come
But I don't want to leave you

I see my vision burn
I feel my memories fade with time
But I'm too young to worry
A melody, a memory
Or just one picture

Seize the day or die
Regretting the time you lost
It's empty and cold without you here
Too many people to ache over

Newborn life replacing all of us
Changing this fable we live in
No longer needed here
So where do we go?

Will you take a journey tonight
Follow me past the walls of death?
But girl, what if
There is no eternal life?

I see my vision burn
I feel my memories fade with time
But I'm too young to worry
A melody, a memory
Or just one picture

Seize the day or die
Regretting the time you lost
It's empty and cold without you here
Too many people to ache over

Trials in life, questions of us existing here
Don't wanna die alone
Without you here, please tell me
What we have is real

So, what if I never hold you, yeah
Or kiss your lips again?
So I never want to leave you
And the memories of us to see
I beg don't leave me

Seize the day or die
Regretting the time you lost
It's empty and cold without you here
Too many people to ache over

Trials in life, questions of us existing here
Don't wanna die alone
Without you here, please tell me
What we have is real

Silence, you lost me
No chance for one more day
Silence, you lost me
No chance for one more day

Silence, you lost me
No chance for one more day
Silence, you lost me
No chance for one more day

Silence, you lost me
No chance for one more day
Silence, you lost me
No chance for one more day
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

long long w,m;

bool solve(long long have, long long W)
{
    if (have==0)return true;
    if (have>W*2)return false;
    if (W>=have&&solve(W-have,W/w))return true;
    if (W<=have&&solve(have-W,W/w))return true;
    if (solve(have,W/w))return true;
    return false;
}

int main(){
//freopen("towers.in","r",stdin);
//freopen("towers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>w>>m;
long long q=1;
while (q<m)q*=w;

if (solve(m,q))
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;

//cin.get();cin.get();
return 0;}