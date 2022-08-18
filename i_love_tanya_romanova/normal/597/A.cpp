/*
Lean out your window, golden hair
I heard you singing in the midnight air
My book is closed, I read no more
Watching the fire dance, on the floor
I've left my book, I've left my room

For I heard you singing through the gloom
Singing and singing, a merry air
Lean out the window, golden hair...
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

long long k,a,b;
long long get(long long x)
{
	if (x%k==0)
		return x/k;
	if (x>0)
		return x/k;
	return x/k-1;
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>k>>a>>b;
long long res=get(b)-get(a-1);
cout<<res<<endl;

//cin.get();cin.get();
return 0;}