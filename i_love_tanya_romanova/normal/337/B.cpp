/*
I gotta see you moving fast, see you come my way
See the dreams, I hope they last, never fade away
Gotta see the lights above, make it loud tonight
Gotta set it all on fire, set it all alight

See the flashing lights, hear the thunder roll
I am gonna set you alight
Gotta make it man, I ain't got no choice
Gotta fill this hall tonight

Helpless, Helpless, Helpless, Helpless
Helpless, Helpless, Helpless, Helpless

I don't know what I'm gonna do, maybe not tonight, yeah
Gotta set you all afire, gotta treat you right
I can see the flashing lights, lazer for your love
Gotta hear the thunder roar, coming from above

See the flashing lights, hear the thunder roar
I am gonna set you all alight
Gotta make it man, I ain't got no choice
Gotta fill this hall tonight

Helpless, Helpless, Helpless, Helpless
Helpless, Helpless, Helpless, Helpless

I can see the stars, I can see what's going on
Every night alone, I sing my songs just for fun
Only time will tell if I make it myself someday
The stage is mine, music is my destiny
Cannot squeeze the life from me

I can see the stars, I can see what's going on
Every night alone, I sing my songs just for fun
This business ain't for laughs, business men don't like it so
Helpless maybe babe, but you can still enjoy the show
Cannot squeeze the life from me

Gotta be good, see you tonight
I know that was fine
Gotta be safe, gotta be true
You know that you're mine
Help me now, I'm coming home, ohh
Gotta be fine, gotta be right
You'll set me alight

Help me now, I'm coming home
I can see the band from miles away
Looks so right, feels so tight, oohh
Feels so fine, feels so good. oohh
Makes a man a whole man
Lord it's gonna make my day
Helpless, helpless, oohh
Helpless, helpless, oohh
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define ttl 4888888
#define clone agsdahfaassdg

using namespace std;

long a,b,c,d;

long gcd(long a,long b)
{while (a&&b)a>b?a%=b:b%=a;
return a+b;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b>>c>>d;
if (b*1.0/a<d*1.0/c){swap(a,b);swap(c,d);}
//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
//cout<<(b*c-a*d)<<" "<<b*c<<endl;
long aa,bb;

aa=b*c-a*d;
bb=b*c;
//cout<<aa<<" "<<bb<<endl;
long q=gcd(aa,bb);
cout<<aa/q<<"/"<<bb/q<<endl;
cin.get();cin.get();
return 0;}