/*
Yeah, alright
Yeah, alright

Two skies watching it all fading
Two skies living it all fading
Two skies watching it all fading
Two skies fading ones abating
Two suns living it all dying
Two suns fighting ones abiding

Two suns watching them both fighting
Two suns seeing them both dying
Two suns watching them both fighting
Two suns fighting ones abiding
Two skies seeing them both dying
Two skies fading ones abiding

Oh oh ah

Crack pipes, needles, PCP and fast cars
Kind of mix really well and a dead movie star
When I feel like talking I'll never be wrong
If I fell like walking you best come along
I close my windows crank the heat up high
till my palms are wet and my tongue is dry

I'm looking for a mother that will get me high
Just a stupid motherfucker if I die I die
I'm a midnight fist fight

Looking for a mother that will get me high
Just a stupid motherfucker if I die I die
I'm a midnight fist fight

Looking for a mother that will get me high
Just a stupid motherfucker if I die I die
All right

(Two suns fighting ones abiding)
Looking for a mother that will get me high
Just a stupid motherfucker if I die I die...
All right

(Two skies fading ones abiding)
Looking for a mother that will get me high
Just a stupid motherfucker if I die I die...
(Two suns fighting ones abiding)
Looking for a mother that will get me high
Just a stupid motherfucker if I die I die...
(Two skies two sons watching their own war)
Looking for a mother that will get me high
Just a stupid motherfucker if I die I die...

All right
Yeah, alright
Yeah, alright
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

long ar[100],x,n;

bool check(long x)
{
 for (int i=0;i<10;i++)
 ar[i]=0;
 for (int i=1;i<=4;i++)
 {
     ar[x%10]++;x/=10;
 }
 for (int i=0;i<10;i++)
 if (ar[i]>1)return true;
 return false;
}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
++n;
while (check(n))++n;
cout<<n<<endl;

cin.get();cin.get();
return 0;}