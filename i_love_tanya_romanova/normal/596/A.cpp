/*
If I was a moon then would I be missed
If I slept through the night just for a change
Or kept in a cauldron where I could never ask why
Wouldn't it be strange, it's hard to say

If you were a moon I know you would be shining bright
To light up the night, I know you would
When I would just stay behind with my thoughts for a while
Like all dreamers do, I know I'll figure it out soon

I could go further, I could be only with a sudden tune
I could go further but I could be never if it wasn't for you

If I was a moon then I would be mystified
And light up the sky, you know I could
But I would just stay away with my thoughts for a while
Like all dreamers do, you know I'll figure it out soon
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
#define ry asdgasdg
#define rx iqowputtew

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 200000;

using namespace std;

int n,lx,ly,rx,ry,x[100],y[100];

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
		cin>>x[i]>>y[i];
	}
	
	lx=rx=x[1];
	ly=ry=y[1];
	
	for (int i=1;i<=n;i++)
	{
		lx=min(lx,x[i]);
		rx=max(rx,x[i]);
		ly=min(ly,y[i]);
		ry=max(ry,y[i]);
	}
	
	if (lx==rx||ly==ry)
		cout<<-1<<endl;
	else
		cout<<(rx-lx)*(ry-ly)<<endl;
		
	return 0;
}