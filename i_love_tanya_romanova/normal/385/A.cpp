/*
Born into somewhere unseen and unknown
Just like a wonder so small and alone
Take me away into your innocent dreams
Maybe I'd see what it all means

A million to one
You will lose it all
A million to one
You'll be falling
Down to where I am
An unholy man
A million to one
You'll be falling

It's so sad and so true but what can I do
Only a few years then it's up to you
To care for yourself, I hope I gave good advice
For all your life, how to survive

A million to one
You will lose it all
A million to one
You'll be falling
Down to where I am
An unholy man
A million to one
You'll be falling
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

long n,m,ar[200000],ans;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
}
ans=0;
for (int i=2;i<=n;i++)
ans=max(ans,ar[i-1]-ar[i]);
ans-=m;
if (ans<0)ans=0;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}