/*  
I can feel your fear and weakness
I see my own in the mirrors of your eyes
Carved into a corner hopeless
There's death ahead and doom behind
There's a bad storm blowing in
And most of us won't make it
The wreckage of your past
Means nothing now, forsake it

The memories cripple you
You're torn apart, your doubt must

Die
It only fell apart 'cause you let it
Bled of all you had to lose
Pick up the pieces with your broken
Hands
It only fell apart 'cause you let it
Bled of all you had to lose
Pick up the pieces with your broken
Hands

Well there's those that do
And those that just do talking
We're all going through hell
It's burn or keep on walking
The blackguards sing their shanty
Pure death riding the wind
Right now it's do or die
Now will you choose to live

The memories that ruin you
You're torn apart your doubt must

Die
It only fell apart 'cause you let it
Bled of all you had to lose
Pick up the pieces with your broken
Hands
It only fell apart 'cause you let it
Bled of all you had to lose
Pick up the pieces with your broken
Hands

You best delay self-pity
Locked in devastation's throes
The noose waits you swinging
A blade of malice cuts the rope

Hostility ensues, no attempt to repent
your struggles vindicate the illest of intent

Die
It only fell apart 'cause you let it
Bled of all you had to lose
Pick up the pieces with your broken
Hands
It only fell apart 'cause you let it
Bled of all you had to lose
Pick up the pieces with your broken
Hands
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
#define clone agsdahfaassdg
using namespace std;

long n,l,r;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
l=1;
r=n*n;
for (int i=1;i<=n;i++)
{
    for (int j=1;j<=n/2;j++)
    {
        if (j>1)cout<<" ";
        cout<<l<<" "<<r;
        ++l;--r;
    }cout<<endl;
}
cin.get();cin.get();
return 0;}