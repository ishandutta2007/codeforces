/*
Eject from the womb, restrained, I'm catching the wind
Unfolded fire blows with the words, straight from within
The second I was born I found a shelter deep in my own
I ventured further out on the edge of the glacier
This is how we talk to the world
Pure liquid fire running through our veins
We're in this alone, we bow to no one
Carved by the waves, our sacred temple
Sing the praises of no flag, we set the tone
This is no fiction, we've come to an end now
Our conviction untouched, we build a life straight
Intelligence of heart as only guidance
Infinite power lies all around us and in the heart
The flashes find a way, stealing through these broken walls
And when this fire grows, it does it so we can't remember
The meaning of this life, we'll be marching until the end
Had not taste for more lies, we are standing alone
The bright treasure found has no price and no name
In the light of this star, with the forces aligned
This is how we talk to the world
Pure liquid fire running through our veins
We're in this alone, we bow to no one
Carved by the waves, our sacred temple
Sing the praises of no flag, we set the tone
This is no fiction, we've come to an end now
Our conviction untouched, we build a life straight
Intelligence of heart as only guidance
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

long n,ar[200000],mx,t,fdeg;

long gcd(long a,long b)
{
     while (a&&b){a>b?a%=b:b%=a;}
     return a+b;
} 
int main(){
//freopen("police.in","r",stdin);
//freopen("police.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    mx=max(mx,ar[i]);
}

t=ar[1];
for (int i=1;i<=n;i++)
t=gcd(t,ar[i]);

fdeg=mx/t;
fdeg-=n;
if (fdeg%2)cout<<"Alice"<<endl;
else cout<<"Bob"<<endl;

cin.get();cin.get();
return 0;}