/*
I see a red door and I want it painted black
No colors anymore I want them to turn black
I see the girls walk by dressed in their summer clothes
I have to turn my head until my darkness goes
I see a line of cars and they're all painted black
With flowers and my love both never to come back
I see people turn their heads and quickly look away
Like a new born baby it just happens ev'ry day
I look inside myself and see my heart is black
I see my red door and it has been painted black
Maybe then I'll fade away and not have to face the facts
It's not easy facin' up when your whole world is black
No more will my green sea go turn a deeper blue
I could not foresee this thing happening to you
If I look hard enough into the settin sun
My love will laugh with me before the mornin comes
I see a red door and I want it painted black
No colors anymore I want them to turn black
I see the girls walk by dressed in their summer clothes
I have to turn my head until my darkness goes
Hmm, hmm, hmm,...
I wanna see it painted, painted black
Black as night, black as coal
I wanna see the sun blotted out from the sky
I wanna see it painted, painted, painted, painted black
Yeah!
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
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

long n,q,bd,mx;
map<long, long> calc;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (long i=1;i<=n;i++)
{
 cin>>q;
 bd=min(i-1,n-i);
 bd=q-bd;
 if (bd<=0)continue;
 mx=max(mx,calc[bd]+1);
 calc[bd]++;
}
cout<<n-mx<<endl;

cin.get();cin.get();
return 0;}