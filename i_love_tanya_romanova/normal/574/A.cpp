/*
Something has left my life
And I don't know where it went to
Somebody caused me strife
And it's not what I was seeking.
Didn't you see me, didn't you hear me
Didn't you see me standing there
Why did you turn out the lights
Did you know that I was sleeping
Say a prayer for me
Help me to feel the strength I did
My identity has if been taken
Is my heart breaking on me
All my plans fell though my hands
They fell
Though my hands on me
All my dreams, it suddenly seems
Empty
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n,ar[1<<20];
int ans;

int gm()
{
	int bst=1;
	for (int i=1;i<=n;i++)
		if (ar[i]>=ar[bst])
			bst=i;
	return bst;
}

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
	cin>>ar[i];

while (true)
{
	int ps=gm();
	if (ps==1)
		break;
	ar[1]++;
	ar[ps]--;
	++ans;
}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}