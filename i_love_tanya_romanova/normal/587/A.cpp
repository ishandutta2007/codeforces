/*
In the aftermath, everything will clear
But the ones who stand have no fear
Can you feel the fire that burns inside?
Can't live without it, it's something I can't deny

Living my life in fire, burning in sweet desire
Want to get higher and higher, I don't mind the consequences
Living my life in fire, burning in sweet desire
Want to get higher and higher, I want to live forevermore

Burning fire in my soul
Flames grow higher more and more

We're running out of time, is there an answer?
Only the fire remains forever it burns
My desire, it burns inside of me
I can't live without it, it's something I just can't hide

Living my life in fire, burning in sweet desire
Want to get higher and higher, I don't mind the consequences
Living my life in fire, burning in sweet desire
Want to get higher and higher, I want to live forevermore

Burning fire in my soul
Flames grow higher more and more

Burning fire in my soul
Flames grow higher more and more

Living in fire, burning desire
Want to get higher and higher
Living my life in fire, burning in sweet desire
Want to get higher and higher, I want to live forevermore

Burning fire in my soul
Flames grow higher
Burning fire
Burning fire forevermore
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

using namespace std;

int n,ans,cnt[1<<21];

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
	int q;
	cin>>q;
	cnt[q]++;
}
for (int i=0;i<=1100000;i++)
{
	while (cnt[i]>1)
	{
		cnt[i]-=2;
		cnt[i+1]++;
	}
	if (cnt[i]>0)
		ans++;
}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}