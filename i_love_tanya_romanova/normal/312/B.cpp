/*
Hear the call of the wild in us all
It waits for the night to fall
I'm getting hot, I'm ready for the night
No holdin' back, let's ball
I'm gonna give all you can take all night
And leave you in the morning feeling right

I'm an animal, there's an animal in me
Gonna set it free
I'm an animal, there's an animal in me
Gonna set it free

I've been looking, you've been watching the side
There's somethings you just can't hide
Oh, your getting wet, your working up a sweat
Your hairs standing up on end
Your skin is screaming, glad we met?
Tonight's one night you won't forget

I'm an animal, there's an animal in me
Gonna set it free
I'm an animal, there's an animal in me
Gonna set it free
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

double a,b,c,d,p;
double ans;

int main(){
//freopen("gnu.in","r",stdin);
//freopen("gnu.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

p=1;
cin>>a>>b>>c>>d;
for (int iter=0;iter<=1000000;iter++)
{
    ans+=p*a/b;
    p=p*(b-a)/b;
    p=p*(d-c)/d;
    if (p<1e-12)break;
}
cout.precision(12);
cout<<ans<<endl;

cin.get();cin.get();
return 0;}