/*
Remember a day before today
A day when you were young
Free to play along with time
Evening never comes

Sing a song that can't be sung
Without the morning's kiss
Queen, you shall be it if you wish
Look for your king
Why can't we play today
Why can't we stay that way

Climb your favourite apple tree
Try to catch the sun
Hide from your little brother's gun
Dream yourself away
Why can't we reach the sun
Why can't we blow the years away

Blow away
Blow away
Remember
Remember
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

string st;
int tests;
char memo[N];

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;

cin>>tests;
for (;tests;--tests)
{
	int l,r,k;
	cin>>l>>r>>k;
	--l;
	--r;
	for (int i=l;i<=r;i++)
	{
		int np=l+((k+i-l)%(r-l+1));
		memo[np]=st[i];
	}
	for (int i=l;i<=r;i++)
		st[i]=memo[i];
}
cout<<st<<endl;

//cin.get();cin.get();
return 0;}