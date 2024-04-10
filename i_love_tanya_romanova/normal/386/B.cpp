/*
The sphinx and star
The key and gate.

Seven secrets of the sphinx
Eleven riddles of the star
Drink the wine of babylon
And dance the dance of yezidi

The sphinx and star
The cup and stone.

Seven secrets of the sphinx
Give all the keys to alkhemy
And the making of the stone
That will turn the metal to gold

Seven secrets of the sphinx
Enter the desert of apep
Through the tower of yezid
That will turn mud to diamonds
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

long n,q,t,ans,s[2000],calc[2000];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    calc[q]++;
}
cin>>t;
for (int i=1;i<=1000;i++)s[i]=s[i-1]+calc[i];

for (int i=t;i<=1000;i++)
{
    q=s[i];
    if (i>t)q-=s[i-t-1];
    ans=max(ans,q);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}