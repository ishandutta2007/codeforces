/*
Into a strange new world, into the after
All your tears might find you've fallen too far
Take another look, take another ride
Can't we make them leave the hate behind

And I still believe in nothing
Will we ever see the shape of tomorrow?

Into the empty storm, into the formless loss of hope,
Where we can forget the game

And I still believe in nothing
Will we ever see the cure for our sorrow

Nothing is sacred when no one is saved
Nothing's forever so count your days
Nothing is final and no one is real
Pray for tomorrow and find your empty still

Nothing
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
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,res,q;

long gcd(long a,long b)
{
     while (a&&b)a>b?a%=b:b%=a;
     return a+b;
} 

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
res=0;
for (int i=1;i<=n;i++)
{
    cin>>q;
    res=gcd(res,q);
} 
cout<<res*n<<endl;

cin.get();cin.get();
return 0;}