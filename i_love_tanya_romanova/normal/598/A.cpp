/*
I've got a little black book with my poems in
Got a bag with a toothbrush and a comb in
When I'm a good dog
They sometimes throw me the bone in

I got elastic bands keepin' my shoes on
Got those swollen hand blues
I got thirteen channels of shit on the TV to choose from
I've got electric light

And I've got second sight
I got amazing powers of observation
And that is how I know, when I try to get through
On the telephone to you, there'll be nobody home

I've got the obligatory Hendrix perm and the inevitable pinhole burns
Now all down the front of my favorite satin shirt
I've got nicotine stains on my fingers, I've got a silver spoon on a chain
Got a grand piano to prop up my mortal remains

I've got wild staring eyes
And I've got a strong urge to fly, but I got nowhere to fly to
Ooh, babe when I pick up the phone there is still nobody home
I've got a pair of Gohills boots and I got fading roots
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
#include <ctime>
#include <memory.h>
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define M 18
#define N 1000005

using namespace std;

int tests;
long long n;
long long get(long long x)
{
	return x*(x+1)/2;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
	cin>>n;
	long long res=get(n);
	for (int i=0;i<=30;i++)
		if ((1ll<<i)<=n)
			res-=2*(1ll<<i);
	cout<<res<<endl;
}

//cin.get();cin.get();
return 0;}