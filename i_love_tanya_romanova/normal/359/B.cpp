/*
Load up on guns and bring your friends
It's fun to lose and to pretend
She's over-bored and self-assured
Oh no, I know a dirty word

Hello, hello, hello, hello.
Hello, hello, hello, hello.
Hello, hello, hello, hello.
Hello, hello, hello

With the lights out, it's less dangerous
Here we are now, entertain us
I feel stupid and contagious
Here we are now, entertain us

A mulatto, an albino
A mosquito, my libido
Yeah, hey, yay

I'm worse at what I do best
And for this gift I feel blessed
Our little group has always been
And always will until the end

Hello, hello, hello, how low?
Hello, hello, hello, how low?
Hello, hello, hello, how low?
Hello, hello, hello

With the lights out, it's less dangerous
Here we are now, entertain us
I feel stupid and contagious
Here we are now, entertain us

A mulatto, an albino
A mosquito, my libido
Yeah, hey, yay

And I forget just why I taste
Oh yeah, I guess it makes me smile
I found it hard, it's hard to find
Oh well, whatever, nevermind

Hello, hello, hello, how low?
Hello, hello, hello, how low?
Hello, hello, hello, how low?
Hello, hello, hello

With the lights out, it's less dangerous
Here we are now, entertain us
I feel stupid and contagious
Here we are now, entertain us

A mulatto, an albino
A mosquito, my libido

A denial, a denial
A denial, a denial
A denial, a denial
A denial, a denial
A denial
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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,k,ar[200000],cur,usd[200000];
int main(){
//freopen("elect.in","r",stdin);
//freopen("elect.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>k;
ar[1]=k+1;
ar[2]=1;
usd[k+1]=1;

cur=1;
for (int i=2;i<=n*2;i++)
{
       while (usd[cur])++cur;
       ar[i]=cur;
       ++cur;
}

for (int i=1;i<=n*2;i++)
{if (i>1)cout<<" ";
cout<<ar[i];}
cout<<endl;
cin.get();cin.get();
return 0;}