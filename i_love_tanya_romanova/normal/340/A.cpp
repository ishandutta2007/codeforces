/*
"Son," she said, "Have I got a little story for you
What you thought was your Daddy was nothin' but a
While you were sittin' home alone at age thirteen
Your real Daddy was dyin', sorry you didn't see him but I'm glad we talked"

Oh I, oh, I'm still alive
Hey, I, oh, I'm still alive
Hey I, oh, I'm still alive
Hey, oh

Oh, she walks slowly, across a young man's room
She said, "I'm ready for you"
"I can't remember anything to this very day 'cept the look, the look
Oh, you know where, now I can't see, I just stare"

I'm still alive
Hey I, but, I'm still alive
Hey I, boy, I'm still alive
Hey I, I, I'm still alive, yeah
Ooh yeah, yeah, yeah, yeah, ooh

"Is something wrong?", she said
Well of course there is, "you're still alive," she said
Oh, and do I deserve to be?
Is that the question? And if so, if so, who answers, who answers?

I, oh, I'm still alive
Hey I, oh, I'm still alive
Hey I, oh I'm still alive
Hey I, oh I'm still alive
Hey, hey, hey, hey, hey, hey
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
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long long a,b,l,r;
long long gcd(long long x,long long y)
{
 while (x&&y)x>y?x%=y:y%=x;
 return x+y;    
}

long long solve(long long a,long long b,long long c)
{
 return c/(a*b/gcd(a,b));
}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b>>l>>r;
cout<<solve(a,b,r)-solve(a,b,l-1)<<endl;

cin.get();cin.get();
return 0;}